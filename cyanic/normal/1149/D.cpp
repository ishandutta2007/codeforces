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

template<class T> inline void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=75,M=1<<17;
struct node{
	int u,s,d;
	friend bool operator < (node a,node b){
		return a.d>b.d;
	}
}; priority_queue<node> Q;
int d[N][M],pa[N],cur[N],ans[N],sz[N];
int n,m,cnt,a,b;
vector<pii> e[N];

int gp(int x){
	return pa[x]==x?x:pa[x]=gp(pa[x]);
}
/*
6 5 1 2
2 3 1
3 4 1
4 5 1
1 6 2
6 2 2
*/
int main(){
	read(n),read(m),read(a),read(b);
	rep(i,1,n) pa[i]=i;
	rep(i,1,m){
		int u,v,w;
		read(u),read(v),read(w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
		if(w==a) pa[gp(u)]=gp(v);
	}
	rep(x,1,n) sz[gp(x)]++,cur[x]=-1;
	rep(x,1,n) if(sz[pa[x]]>=4){
		if(cur[pa[x]]==-1) cur[pa[x]]=cnt++;
		pa[x]=cur[pa[x]];
	} else pa[x]+=N;
	memset(d,0x3f,sizeof d);
	memset(ans,0x3f,sizeof ans);
	d[1][!pa[1]]=0,Q.push((node){1,!pa[1],0});
	while(!Q.empty()){
		node t=Q.top(); Q.pop();
		if(t.d>d[t.u][t.s]) continue;
		int u=t.u,s=t.s;
		ans[u]=min(ans[u],t.d);
		for(auto v:e[u]){
			if(v.se==a){
				if(d[u][s]+a<d[v.fi][s]){
					d[v.fi][s]=d[u][s]+a;
					Q.push((node){v.fi,s,d[v.fi][s]});
				}
			}
			else if((pa[v.fi]>=N||!(s>>pa[v.fi]&1))&&pa[v.fi]!=pa[u]){
				int ns=(pa[v.fi]>=N?s:s|(1<<pa[v.fi]));
				if(d[u][s]+b<d[v.fi][ns]){
					d[v.fi][ns]=d[u][s]+b;
					Q.push((node){v.fi,ns,d[v.fi][ns]});
				}
			}
		}
	}
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}