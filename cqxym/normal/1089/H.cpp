#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
#define R register int
#define N 200001
char s[100002];
vector<int>G[N],E[N],H[N];
int dfn[N],low[N],bel[N],ord[N],deg[N];
bool in[N],tag[N];
stack<int>S;
inline void Tarjan(int x,int&ct,int&tot){
	ct++;
	dfn[x]=low[x]=ct;
	in[x]=true;
	S.push(x);
	for(int T:G[x]){
		if(dfn[T]==0){
			Tarjan(T,ct,tot);
			if(low[T]<low[x]){
				low[x]=low[T];
			}
		}else if(in[T]==true&&dfn[T]<low[x]){
			low[x]=dfn[T];
		}
	}
	if(dfn[x]==low[x]){
		int v;
		tot++;
		do{
			v=S.top();
			S.pop();
			bel[v]=tot;
			in[v]=false;
		}while(x!=v);
	}
}
inline void Solve(){
	int n,m,x,y,tot=0;
	scanf("%d%d",&n,&m);
	for(R i=n<<1;i!=0;i--){
		vector<int>().swap(G[i]);
		dfn[i]=0;
	}
	scanf("%s",s+1);
	auto Neg=[=](int x){
		if(x>n){
			return x-n;
		}
		return x+n;
	};
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		if(x<0){
			x=n-x;
		}
		if(y<0){
			y=n-y;
		}
		G[Neg(x)].push_back(y);
		G[Neg(y)].push_back(x);
	}
	x=0;
	for(R i=n<<1;i!=0;i--){
		if(dfn[i]==0){
			Tarjan(i,x,tot);
		}
	}
	for(R i=1;i<=n;i++){
		if(bel[i]==bel[i+n]){
			puts("FALSE");
			return;
		}
	}
	for(R i=1;i<=tot;i++){
		tag[i]=false;
		vector<int>().swap(E[i]);
	}
	for(R i=1;i<=n;i++){
		if(s[i]=='E'){
			tag[bel[i]]=tag[bel[i+n]]=true;
		}else if(tag[bel[i]]==true||tag[bel[i+n]]==true){
			puts("FALSE");
			return;
		}
	}
	for(int i=n<<1;i!=0;i--){
		for(int T:G[i]){
			if(bel[T]!=bel[i]){
				E[bel[i]].push_back(bel[T]);
				deg[bel[T]]++;
			}
		}
	}
	for(int i=1;i<=tot;i++){
		if(deg[i]==0){
			S.push(i);
		}
	}
	y=0;
	while(S.empty()==false){
		x=S.top();
		S.pop();
		y++;
		ord[y]=x;
		for(int T:E[x]){
			deg[T]--;
			if(deg[T]==0){
				S.push(T);
			}
		}
	}
	for(R i=1;i<=tot;i++){
		vector<int>().swap(H[i]);
	}
	for(int i=n<<1;i!=0;i--){
		H[bel[i]].push_back(i);
	}
	for(R i=tot;i!=0;i--){
		x=ord[i];
		tag[x]=false;
		y=0;
		for(int T:H[x]){
			if(T>n){
				T-=n;
			}
			if(s[T]=='A'){
				y++;
			}
		}
		for(int T:E[x]){
			tag[x]=tag[x]||tag[T];
		}
		if(y!=0&&tag[x]==true||y>1){
			puts("FALSE");
			return;
		}
		tag[x]=tag[x]||y!=0;
	}
	puts("TRUE");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}