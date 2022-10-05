#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=1000005;
int f[N],g[N],n,a,b,ans;
vi e[N];

void dfs(int u,int fa){
	int sn=e[u].size()-1;
	f[u]=1,g[u]=sn;
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		f[u]=max(f[u],g[v]+1);
		g[u]=max(g[u],max(f[v],g[v])+sn-1);
	}
}

void dfs2(int u,int fa,int F,int G){
	int owo=e[u].size();
	int ff=max(f[u],G+1);
	int gg=max(g[u]+1,max(F,G)+owo-1);
	ans=max(ans,max(ff,gg));
	int mxf=0,mxf2=0,fp=0;
	int mxg=0,mxg2=0,gp=0;
	for(auto v:e[u]){
		if(v==fa) continue;
		if(f[v]>mxf) mxf2=mxf,mxf=f[v],fp=v;
		else if(f[v]>mxf2) mxf2=f[v];
		if(g[v]>mxg) mxg2=mxg,mxg=g[v],gp=v;
		else if(g[v]>mxg2) mxg2=g[v];
	}
	int sn=owo-1;
	for(auto v:e[u]){
		if(v==fa) continue;
		int mf=(fp==v?mxf2:mxf);
		int mg=(gp==v?mxg2:mxg);
		mf=max(mf,F),mg=max(mg,G);
		dfs2(v,u,mg+1,max(mf,mg)+sn-1);
	}
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	dfs(1,0),dfs2(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}