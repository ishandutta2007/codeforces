#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e10;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=55;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
}
dinic(205,0,201);


struct rect
{
	int x1,y1,x2,y2;
	bool contains(const rect& other) const{
		return other.x1 >= x1
			&& other.x2 <= x2
			&& other.y1 >= y1
			&& other.y2 <= y2;
	}
}
input[N];

istream& operator>>(istream& in,rect &a){in>>a.x1>>a.y1>>a.x2>>a.y2;return in;}

void solve(){
	int n,m;
	cin >> n >> m;
	
	vector<int> x,y;
	rep(i,0,m){
		cin >> input[i];
		x.pb(input[i].x1);
		x.pb(input[i].x2+1);
		// x.pb(input[i].x2);
		// x.pb(input[i].x1-1);
		
		y.pb(input[i].y1);
		y.pb(input[i].y2+1);
		// y.pb(input[i].y2);
		// y.pb(input[i].y1-1);
	}
	
	sort(all(x));
	uniq(x);
	sort(all(y));
	uniq(y);
	
	vector<int> xl,xr,yl,yr;
	rep(i,0,m){
		xl.pb(input[i].x1);
		xl.pb(input[i].x2+1);
		xr.pb(input[i].x2);
		xr.pb(input[i].x1-1);
		
		yl.pb(input[i].y1);
		yl.pb(input[i].y2+1);
		yr.pb(input[i].y2);
		yr.pb(input[i].y1-1);
	}
	
	sort(all(xl)); uniq(xl);
	sort(all(xr)); uniq(xr);
	sort(all(yl)); uniq(yl);
	sort(all(yr)); uniq(yr);
	
	xr.pb(INF);
	yr.pb(INF);
	
	for(int x1:xl){
		int x2 = *lower_bound(all(xr),x1);
		int wid = x2 - x1 + 1;
		int id = lower_bound(all(x),x1) - x.begin() + 1;
		dinic.add_edge(0,id,wid);
	}
	
	for(int y1:yl){
		int y2 = *lower_bound(all(yr),y1);
		int wid = y2 - y1 + 1;
		int id = lower_bound(all(y),y1) - y.begin() + 101;
		dinic.add_edge(id,201,wid);
	}
	
	for(int x1:xl){
		for(int y1:yl){
			int x2 = *lower_bound(all(xr),x1);
			int y2 = *lower_bound(all(yr),y1);
			
			bool ok = 0;
			rep(i,0,m){
				if(input[i].contains({x1,y1,x2,y2})){
					ok = 1;
				}
			}
			
			if(ok){
				// add edge x1 - y1
				int idx = lower_bound(all(x),x1) - x.begin() + 1;
				int idy = lower_bound(all(y),y1) - y.begin() + 101;
				dinic.add_edge(idx,idy,INF);
			}
		}
	}
	
	cout << dinic.flow();
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}