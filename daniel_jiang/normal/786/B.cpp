// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

#define int ll

const int N=5e5+5,D=5e5,INF=1e17;
int n,m,st,dis[N<<1],node[N];
bool vst[N<<1];
vector<pair<int,int> >es[N<<2];

#define mid ((l+r)>>1)
#define xl (x<<1)
#define xr (x<<1|1)

inline void build(int x,int l,int r){
	if(l==r){node[l]=x;return ;}
	es[x].pb(mp(0,xl));es[x].pb(mp(0,xr));
	es[xl+D].pb(mp(0,x+D));es[xr+D].pb(mp(0,x+D));
	build(xl,l,mid);build(xr,mid+1,r);
}

inline void add(int x,int l,int r,int L,int R,int v,int w,int op){
	if(L<=l&&r<=R){
		if(op==2) es[v].pb(mp(w,x));
		else es[x+D].pb(mp(w,v));
		return ;
	}
	if(L<=mid) add(xl,l,mid,L,R,v,w,op);
	if(R>mid) add(xr,mid+1,r,L,R,v,w,op);
}

inline void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
	fill(dis,dis+(N<<1)+1,INF);dis[s]=0;q.push(mp(0,s));
	while(!q.empty()){
		int x=q.top().second,sum=q.top().first;
		q.pop();
		if(vst[x]) continue;
		vst[x]=1;
		for(re i=0;i<es[x].size();++i){
			int t=es[x][i].second,w=es[x][i].first;
			if(dis[t]>sum+w){
				dis[t]=sum+w;
				q.push(mp(dis[t],t));
			}
		}
	}
}

// ----------  ---------- //

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);rd(st);
	build(1,1,n);
	for(re i=1;i<=n;++i) es[node[i]].pb(mp(0,node[i]+D)),es[node[i]+D].pb(mp(0,node[i]));
	for(re i=1;i<=m;++i){
		int op,u,v,w,l,r;
		rd(op);
		if(op==1){
			rd(v);rd(u);rd(w);
			es[node[v]].pb(mp(w,node[u]));
		}
		else{
			rd(v);rd(l);rd(r);rd(w);
			add(1,1,n,l,r,node[v],w,op);
		}
	}
	dijkstra(node[st]);
	for(re i=1;i<=n;++i){
		if(dis[node[i]]==INF) cout<<"-1 ";
		else wr(dis[node[i]]),putchar(' ');
	}puts("");
	return 0;
}

// ---------- Main ---------- //