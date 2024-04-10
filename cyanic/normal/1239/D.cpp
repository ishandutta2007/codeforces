#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=2000005;
int dfn[N],low[N],stk[N],bel[N];
int mark[N],n,m,a,b,res,clk,top;
vi e[N];

void replace(){
	res=clk=top=0;
	rep(i,1,n){
		e[i].clear();
		dfn[i]=low[i]=bel[i]=0;
		mark[i]=0;
	}
}

void tarjan(int u){
	dfn[u]=low[u]=++clk;
	stk[++top]=u;
	for(auto v:e[u])
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!bel[v]){
			low[u]=min(low[u],dfn[v]);
		}
	if(low[u]!=dfn[u])return;
	++res;
	while(stk[top]!=u)
		bel[stk[top--]]=res;
	bel[stk[top--]]=res;
}

void rmain(){
	read(n),read(m);
	replace();
	rep(i,1,m){
		read(a),read(b);
		if(a==b)continue;
		e[a].pb(b);
	}
	rep(i,1,n)
		if(!dfn[i])tarjan(i);
	if(res==1){
		puts("No");
		return;
	}
	vi A,B;
	rep(i,1,n)
		if(bel[i]<res)A.pb(i);
		else B.pb(i);
	puts("Yes");
	printf("%d %d\n",(int)A.size(),(int)B.size());
	for(auto x:A)printf("%d ",x);puts("");
	for(auto x:B)printf("%d ",x);puts("");	
}

int main(){
	int T; read(T);
	while(T--)rmain();
	return 0;
}