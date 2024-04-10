//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	for (i=0;i<n;i++) cout<<a[i]<<" \n"[i+1==n];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
namespace network_flow
{
	const int N=2e5+50;//number of points
	namespace flow
	{
		typedef ll wT;//single flow
		typedef ll cT;//total flow
		const cT inf=numeric_limits<cT>::max();//maximum
		struct Q
		{
			int v;
			wT w;
			int id;
		};
		vector<Q> e[N];
		int fc[N],q[N];
		int n,s,t;
		int bfs()
		{
			fill_n(fc,n,0);
			int p1=0,p2=0,u;
			fc[s]=1;q[0]=s;
			while (p1<=p2)
			{
				int u=q[p1++];
				for (auto [v,w,id]:e[u]) if (w&&!fc[v]) fc[q[++p2]=v]=fc[u]+1;
			}
			return fc[t];
		}
		cT dfs(int u,cT maxf)
		{
			if (u==t) return maxf;
			cT j=0,k;
			for (auto &[v,w,id]:e[u]) if (w&&fc[v]==fc[u]+1&&(k=dfs(v,min(maxf-j,(cT)w))))
			{
				j+=k;
				w-=k;
				e[v][id].w+=k;
				if (j==maxf) return j;
			}
			fc[u]=0;
			return j;
		}
		cT maxflow(const vector<tuple<int,int,wT>> &edges,int S,int T)//[0,n]
		{
			s=S;t=T;n=max(s,t);
			for (auto [u,v,w]:edges) n=max({n,u,v});
			++n;
			assert(n<N);
			for (int i=0;i<n;i++) e[i].clear();
			for (auto [u,v,w]:edges) if (u!=v)
			{
				e[u].push_back({v,w,(int)e[v].size()});
				e[v].push_back({u,0,(int)e[u].size()-1});
			}
			cT r=0;
			while (bfs()) r+=dfs(s,inf);
			return r;
		}
	}
	using flow::maxflow,flow::fc;
	namespace match
	{
		int lk[N];
		int maxmatch(int n,int m,const vector<pair<int,int>> &edges)//lk[[0,n]]->[0,m]
		{
			++n;++m;
			assert(max(n,m)<N);
			int s=n+m,t=n+m+1,i;
			vector<tuple<int,int,ll>> eg;
			eg.reserve(n+m+edges.size());
			for (i=0;i<n;i++) eg.push_back({s,i,1});
			for (i=0;i<m;i++) eg.push_back({i+n,t,1});
			for (auto [u,v]:edges) eg.push_back({u,v+n,1});
			int r=maxflow(eg,s,t);
			fill_n(lk,n,-1);
			for (i=0;i<n;i++) for (auto [v,w,id]:flow::e[i]) if (v<s&&!w) {lk[i]=v-n;break;}
			return r;
		}
	}
	using match::maxmatch,match::lk;
	namespace costflow
	{
		typedef ll wT;
		typedef ll cT;
		const cT inf=numeric_limits<cT>::max();
		struct Q
		{
			int v;
			wT w;
			cT c;
			int id;
		};
		vector<Q> e[N];
		cT dis[N];
		int pre[N],pid[N],ipd[N];
		bool ed[N];
		int n,s,t;
		pair<wT,cT> spfa()
		{
			queue<int> q;
			fill_n(dis,n,inf);
			memset(ed,0,n*sizeof ed[0]);
			q.push(s);dis[s]=0;
			while (q.size())
			{
				int u=q.front();q.pop();ed[u]=0;
				for (auto [v,w,c,id]:e[u]) if (w&&dis[v]>dis[u]+c)
				{
					dis[v]=dis[u]+c;
					pre[v]=u;
					pid[v]=e[v][id].id;
					ipd[v]=id;
					if (!ed[v]) q.push(v),ed[v]=1;
				}
			}
			if (dis[t]==inf) return {0,0};
			wT mw=numeric_limits<wT>::max();
			for (int i=t;i!=s;i=pre[i]) mw=min(mw,e[pre[i]][pid[i]].w);
			for (int i=t;i!=s;i=pre[i]) e[pre[i]][pid[i]].w-=mw,e[i][ipd[i]].w+=mw;
			return {mw,(cT)mw*dis[t]};
		}
		pair<wT,cT> mcmf_spfa(const vector<tuple<int,int,wT,cT>> &edges,int S,int T)//[0,n]
		{
			s=S;t=T;n=max(s,t);
			for (auto [u,v,w,c]:edges) n=max({n,u,v});
			++n;
			assert(n<N);
			for (int i=0;i<n;i++) e[i].clear();
			for (auto [u,v,w,c]:edges) if (u!=v)
			{
				e[u].push_back({v,w,c,(int)e[v].size()});
				e[v].push_back({u,0,-c,(int)e[u].size()-1});
			}
			pair<wT,cT> r{0,0},rr;
			while ((rr=spfa()).first) r={r.first+rr.first,r.second+rr.second};
			return r;
		}
		pair<wT,cT> mcmf_dijk(const vector<tuple<int,int,wT,cT>> &edges,int S,int T)//[0,n]
		{
			s=S;t=T;n=max(s,t);
			for (auto [u,v,w,c]:edges) n=max({n,u,v});
			++n;
			assert(n<N);
			for (int i=0;i<n;i++) e[i].clear();
			for (auto [u,v,w,c]:edges) if (u!=v)
			{
				e[u].push_back({v,w,c,(int)e[v].size()});
				e[v].push_back({u,0,-c,(int)e[u].size()-1});
			}
			static cT h[N];
			auto get_h=[&]()
			{
				fill_n(h,n,inf);
				memset(ed,0,n*sizeof ed[0]);
				queue<int> q;
				q.push(s);h[s]=0;
				while (q.size())
				{
					int u=q.front();q.pop();ed[u]=0;
					for (auto [v,w,c,id]:e[u]) if (w&&h[v]>h[u]+c)
					{
						h[v]=h[u]+c;
						if (!ed[v]) q.push(v),ed[v]=1;
					}
				}
				return;
			};
			auto dijkstra=[&]() -> pair<wT,cT>
			{
				static int fl[N],zl[N];
				int i;
				memset(ed,0,n*sizeof ed[0]);
				fill_n(dis,n,inf);
				typedef pair<cT,int> pa;
				priority_queue<pa,vector<pa>,greater<pa>> q;
				dis[s]=0;q.push({0,s});
				while (q.size())
				{
					int u=q.top().second;
					q.pop();ed[u]=1;
					i=0;
					for (auto [v,w,c,id]:e[u])
					{
						if (w&&dis[v]>dis[u]+c) fl[v]=id,zl[v]=i,q.push({dis[v]=dis[pre[v]=u]+c,v});
						++i;
					}
					while (q.size()&&ed[q.top().second]) q.pop();
				}
				if (dis[t]==inf) return {0,0};
				wT tf=numeric_limits<wT>::max();
				for (i=t;i!=s;i=pre[i]) tf=min(tf,e[pre[i]][zl[i]].w);
				for (i=t;i!=s;i=pre[i]) e[pre[i]][zl[i]].w-=tf,e[i][fl[i]].w+=tf;
				for (int u=0;u<n;u++) for (auto &[v,w,c,id]:e[u]) c+=dis[u]-dis[v];
				return {tf,tf*(h[t]+=dis[t])};
			};
			get_h();
			for (int u=0;u<n;u++) for (auto &[v,w,c,id]:e[u]) c+=h[u]-h[v];
			pair<wT,cT> r{0,0},rr;
			while ((rr=dijkstra()).first) r={r.first+rr.first,r.second+rr.second};
			return r;
		}
	}
	using costflow::mcmf_spfa,costflow::mcmf_dijk;
	namespace bounded_flow
	{
		typedef ll wT;//single flow
		typedef ll cT;//total flow
		bool valid_flow(const vector<tuple<int,int,wT,wT>> &edges)// l
		{
			if (!edges.size()) return 1;
			int n=0,i;
			cT tot=0;
			for (auto [u,v,l,r]:edges)
			{
				n=max({n,u,v});
				if (l>r) return 0;
			}
			++n;
			static cT cd[N];
			memset(cd,0,n*sizeof cd[0]);
			for (auto [u,v,l,r]:edges) cd[u]+=l,cd[v]-=l;
			vector<tuple<int,int,wT>> eg;
			eg.reserve(n+edges.size());
			for (i=0;i<n;i++) if (cd[i]>0) eg.push_back({i,n+1,cd[i]}),tot+=cd[i];
			else if (cd[i]<0) eg.push_back({n,i,-cd[i]});
			for (auto [u,v,l,r]:edges) eg.push_back({u,v,r-l});
			return tot==flow::maxflow(eg,n,n+1);
		}
		cT valid_flow_st(vector<tuple<int,int,wT,wT>> edges,int s,int t)//-1 invalid, wT=cT
		{
			int n=max(s,t);
			cT tot=0;
			for (auto [u,v,l,r]:edges) n=max({n,u,v}),tot+=(u==s)*r;
			++n;
			edges.push_back({t,s,0,tot});
			if (!valid_flow(edges)) return -1;
			assert(flow::e[s].back().v==t);
			assert(flow::e[t].back().v==s);
			return tot-flow::e[t].back().w;
		}
		cT valid_maxflow(const vector<tuple<int,int,wT,wT>> &edges,int s,int t)//-1 invalid, wT=cT
		{
			cT r=valid_flow_st(edges,s,t);
			if (r<0) return r;
			flow::s=s;flow::t=t;
			flow::e[s].pop_back();flow::e[t].pop_back();
			while (flow::bfs()) r+=flow::dfs(s,flow::inf);
			return r;
		}
        cT valid_minflow(const vector<tuple<int,int,wT,wT>> &edges,int s,int t)//-1 invalid, wT=cT
		{
			cT r=valid_flow_st(edges,s,t);
			if (r<0) return r;
			flow::s=t;flow::t=s;
			flow::e[s].pop_back();flow::e[t].pop_back();
			while (flow::bfs()) r-=flow::dfs(t,flow::inf);
			return r;
		}//not check
	}
	using bounded_flow::valid_flow,bounded_flow::valid_flow_st,bounded_flow::valid_maxflow,bounded_flow::valid_minflow;
	namespace bounded_cost_flow
	{
		pair<ll,ll> valid_mcf(const vector<tuple<int,int,ll,ll,ll>> &edges,int s,int t)//[u,v,l,r,c],mincost flow
		{
			int n=max(s,t);
			for (auto [u,v,l,r,c]:edges) n=max({n,u,v});
			++n;
			int ss=n,tt=n+1;
			static ll cd[N];
			memset(cd,0,n*sizeof cd[0]);
			for (auto [u,v,l,r,c]:edges) cd[u]+=l,cd[v]-=l;
			vector<tuple<int,int,ll,ll>> e;
			ll t1=0,t2=0;
			for (int i=0;i<n;i++) if (cd[i]>0) e.push_back({i,tt,cd[i],0}),t2+=cd[i]; 
			else if (cd[i]<0) e.push_back({ss,i,-cd[i],0});
			for (auto [u,v,l,r,c]:edges) e.push_back({u,v,r-l,c});
			for (auto [u,v,w,c]:e) t1+=(u==s)*w;
			e.push_back({t,s,t1,0});
			auto res=mcmf_spfa(e,ss,tt);//checked dijk
			if (res.first!=t2) return {-1,-1};
			res.first=costflow::e[s].back().w;
			for (auto [u,v,l,r,c]:edges) res.second+=l*c;
			return res;
		}
		pair<ll,ll> valid_mcmf(const vector<tuple<int,int,ll,ll,ll>> &edges,int s,int t)//[u,v,l,r,c],mincost maxflow
		{
			auto r=valid_mcf(edges,s,t);
			if (r.first<0) return {-1,-1};
			costflow::e[s].pop_back();
			costflow::e[t].pop_back();
			costflow::s=s;costflow::t=t;
			pair<ll,ll> rr;
			while ((rr=costflow::spfa()).first) r={r.first+rr.first,r.second+rr.second};//spfa ver. not checked dijk
			return r;
		}
	}
	using bounded_cost_flow::valid_mcf,bounded_cost_flow::valid_mcmf;
	namespace ne_costflow
	{
		pair<ll,ll> ne_mcmf(const vector<tuple<int,int,ll,ll>> &edges,int s,int t)
		{
			vector<tuple<int,int,ll,ll,ll>> e;
			for (auto [u,v,w,c]:edges) if (c>=0) e.push_back({u,v,0,w,c}); else
			{
				e.push_back({u,v,w,w,c});
				e.push_back({v,u,0,w,-c});
			}
			return valid_mcmf(e,s,t);
		}
	}
	using ne_costflow::ne_mcmf;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i,j;
	cin>>n>>m;
	vector<int> a(n);
	for (int &x:a) cin>>x;
	sort(all(a));
	if (a.back()*2>=m) {cout<<"-1\n";return 0;}
	sort(all(a));
	for (i=0;i<n;i++) if (a[i]*3>m) break;
	int L=i;
	vector<pair<int,int>> edges;
	for (i=L;i<n;i++)
	{
		for (j=0;j<L;j++) if (a[i]%a[j]==0) edges.push_back({j,i-L});
	}
	int ans=network_flow::maxmatch(L,n-L,edges);
	if (ans<n-L) {cout<<"-1\n";return 0;}
	vector<int> kl(n-L);
	for (i=0;i<L;i++) if (network_flow::lk[i]>=0) kl[network_flow::lk[i]]=i;
	vector<pair<int,int>> ta;
	for (i=L;i<n;i++)
	{
		int x=kl[i-L];
		ta.push_back({a[x]+a[i]*2,a[x]+a[i]});
	}
	for (i=0;i<L;i++) if (network_flow::lk[i]==-1) ta.push_back({a[i]*3,a[i]*2});
	cout<<ta.size()<<'\n';
	for (auto [x,y]:ta) cout<<x<<' '<<y<<'\n';
}