#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(),x.end()
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

const int N=500005;
struct edge{
	int v,id,l;
} e[N<<1];
int h[N],u[N],v[N],d[N],fa[N],num[N];
int cur[N],f[N],g[N];
int n,m,tot;

void doit(vi &e,vi &p){
	int sz=e.size(),k=max_element(all(e))-e.begin();
	rotate(e.begin(),e.begin()+k,e.end());
	rotate(p.begin(),p.begin()+k,p.end());
	int t=min_element(all(e))-e.begin();
	rep(i,1,t) if(e[i-1]<e[i]) return;
	rep(i,t,sz-2) if(e[i]>e[i+1]) return;
	cur[e[t]]=e[0];
}

void dfs(int u){
	for(int k=h[u];k;k=e[k].l){
		int v=e[k].v;
		if(v==fa[u]) continue;
		if(!d[v]){
			d[v]=d[u]+1;
			num[v]=e[k].id;
			fa[v]=u,dfs(v);
		}
		else if(d[v]<d[u]){
			vi ids,pts;
			ids.pb(e[k].id),pts.pb(u);
			for(int x=u;x!=v;x=fa[x])
				ids.pb(num[x]),pts.pb(fa[x]);
			doit(ids,pts);
		}
	}
}

int main(){
	read(n),read(m);
	per(i,m,1){
		read(u[i]),read(v[i]);
		e[++tot]=(edge){v[i],i,h[u[i]]},h[u[i]]=tot;
		e[++tot]=(edge){u[i],i,h[v[i]]},h[v[i]]=tot;
	}
	d[1]=1,dfs(1);
	rep(i,1,n) f[i]=1;
	rep(i,1,m){
		if(cur[i]) g[cur[i]]=f[u[i]]+f[v[i]];
		f[u[i]]=f[v[i]]=f[u[i]]+f[v[i]]-g[i];
	}
	rep(i,1,n) printf("%d ",f[i]-1); puts("");
	return 0;
}