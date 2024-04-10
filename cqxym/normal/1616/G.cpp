#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 150001
vector<int>G[N],H[N];
bool tag[N],vis[N][2];
int rt[N];
I void PreDFS(int x,int t){
	if(vis[x][t]==false){
		vis[x][t]=true;
		for(int T:H[x+1]){
			if(rt[T+1]>=x){
				PreDFS(T,t^1);
			}
		}
	}
}
I void SufDFS(int x,int t){
	if(vis[x][t]==false){
		vis[x][t]=true;
		for(int T:G[x]){
			if(rt[x+1]>=T-1){
				SufDFS(T-1,t^1);
			}
		}
	}
}
I bool Check(int x,int y){
	return vis[x][0]&&vis[y-1][0]||vis[x][1]&&vis[y-1][1];
}
I void Solve(){
	int n,m,x,y,pos,ct;
	scanf("%d%d",&n,&m);
	ct=n-1;
	for(R i=0;i<=n;i++){
		tag[i]=vis[i][0]=vis[i][1]=false;
	}
	for(R i=0;i<=n;i++){
		vector<int>().swap(G[i]);
	}
	for(R i=0;i<=n;i++){
		vector<int>().swap(H[i]);
	}
	for(R i=2;i<=n;i++){
		H[i].push_back(0);
	}
	for(R i=1;i!=n;i++){
		G[i].push_back(n+1);
	}
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		if(y==x+1){
			ct--;
			tag[x]=true;
		}else{
			G[x].push_back(y);
			H[y].push_back(x);
		}
	}
	if(ct==0){
		printf("%lld\n",(n-1ll)*n>>1);
		return;
	}
	rt[n]=n;
	for(R i=n-1;i!=0;i--){
		rt[i]=tag[i]==true?rt[i+1]:i;
	}
	for(R i=n;rt[i]==n;i--){
		pos=i;
	}
	pos--;
	PreDFS(rt[1],0);
	vis[rt[1]][0]=false;
	SufDFS(rt[1],0);
	int ct1=0,ct2=0;
	for(R i=0;i<=rt[1];i++){
		if(vis[i][0]==true){
			ct1++;
		}
	}
	for(R i=pos;i<=n;i++){
		if(vis[i][0]==true){
			ct2++;
		}
	}
	L ans=(L)ct1*ct2;
	ct1=ct2=0;
	for(R i=0;i<=rt[1];i++){
		ct1+=vis[i][1];
	}
	for(R i=pos;i<=n;i++){
		ct2+=vis[i][1];
	}
	ans+=(L)ct1*ct2;
	ct1=ct2=0;
	for(R i=0;i<=rt[1];i++){
		if(vis[i][0]==true&&vis[i][1]==true){
			ct1++;
		}
	}
	for(R i=pos;i<=n;i++){
		if(vis[i][0]==true&&vis[i][1]==true){
			ct2++;
		}
	}
	ans-=(L)ct1*ct2;
	if(rt[1]==pos){
		if(Check(rt[1],rt[1])==true){
			ans--;
		}
		if(Check(pos+1,pos+1)==true){
			ans--;
		}
		if(Check(rt[1],pos+1)==true){
			ans--;
		}
	}else if(rt[1]==pos-1&&Check(rt[1]+1,rt[1]+1)==true){
		ans--;
	}
	printf("%lld\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}