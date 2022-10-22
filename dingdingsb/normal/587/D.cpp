// Problem: CF587D Duff in Mafia
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF587D
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=8e5+100;
int n,m;
//
vector<int>e[N];
int dfn[N],low[N],cnt,tot,col[N];bool ins[N];stack<int>s;
void dfs(int u){
	dfn[u]=low[u]=++cnt;ins[u]=1;s.push(u);
	for(auto v:e[u]){
		if(!dfn[v])dfs(v),chkmn(low[u],low[v]);
		else if(ins[v])chkmn(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++tot;int x=0;
		while(x!=u){
			x=s.top();s.pop();
			ins[x]=0;col[x]=tot;
		}
	}
}
struct edge{
	int u,v,col,w;
}E[N];
vector<int>id[N];
bool chk(int up,bool clear=true){
	int tot=2*m;
	for(int i=1;i<=m;i++)if(E[i].w>up)
		e[i].pb(i+m);
	for(int i=1;i<=n;i++){
		if(!id[i].size())continue;
		vector<int>pre,suf;
		pre.resize(id[i].size());
		suf.resize(id[i].size());
		for(int j=0;j<id[i].size();j++){
			int x=id[i][j];
			pre[j]=++tot;
			e[tot].pb(x+m);
			if(j!=0)e[tot].pb(pre[j-1]);
		}
		for(int j=id[i].size()-1;~j;j--){
			int x=id[i][j];
			suf[j]=++tot;
			e[tot].pb(x+m);
			if(j!=id[i].size()-1)e[tot].pb(suf[j+1]);
		}
		for(int j=0;j<id[i].size();j++){
			int x=id[i][j];
			if(j!=0)e[x].pb(pre[j-1]);
			if(j!=id[i].size()-1)e[x].pb(suf[j+1]);
		}
	}
	for(int i=1;i<=n;i++){
		if(!id[i].size())continue;
		for(int l=0;l<id[i].size();){
			int r=l;while(r+1<id[i].size()&&E[id[i][l]].col==E[id[i][r+1]].col)r++;
			vector<int>p,pre,suf;
			p.resize(r-l+1);pre.resize(r-l+1);suf.resize(r-l+1);
			for(int j=l;j<=r;j++)p[j-l]=id[i][j];
			for(int j=0;j<p.size();j++){
				int x=p[j];
				pre[j]=++tot;
				e[tot].pb(x);
				if(j!=0)e[tot].pb(pre[j-1]);
			}
			for(int j=p.size()-1;~j;j--){
				int x=p[j];
				suf[j]=++tot;
				e[tot].pb(x);
				if(j!=p.size()-1)e[tot].pb(suf[j+1]);
			}
			for(int j=0;j<p.size();j++){
				int x=p[j];
				if(j!=0)e[x+m].pb(pre[j-1]);
				if(j!=p.size()-1)e[x+m].pb(suf[j+1]);
			}
			l=r+1;
		}
	}
	for(int i=1;i<=tot;i++)if(!dfn[i])dfs(i);
	bool res=1;
	for(int i=1;i<=m;i++)if(col[i]==col[i+m])res=0;
	if(clear)for(int i=1;i<=tot;i++)e[i].clear(),dfn[i]=low[i]=col[i]=0;cnt=0;
	return res;
}
map<int,int>C;//
int kk=0;
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		read(E[i].u,E[i].v,E[i].col,E[i].w);
		if(!C[E[i].col])C[E[i].col]=++kk;E[i].col=C[E[i].col];
		id[E[i].u].pb(i);
		id[E[i].v].pb(i);
	}
	for(int i=1;i<=n;i++)
		sort(id[i].begin(),id[i].end(),[&](int i,int j){return E[i].col<E[j].col;});
	int l=0,r=1e9,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	if(ans==-1)return puts("No"),0;
	puts("Yes");
	write(ans);vector<int>a;
	chk(ans,false);for(int i=1;i<=m;i++)if(col[i]<col[i+m])a.pb(i);
	putchar(' ');write(a.size());putchar('\n');
	for(auto x:a)write(x),putchar(' ');
}