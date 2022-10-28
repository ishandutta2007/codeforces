//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Mincost-Maxflow with potentials
// Running Dijkstra after choosing a correct potential function
// Complexity: non-polynomial if the edge capacities are large
// If edge capacities are constant, then NlogN if potentials are fixed
// If potentials not fixed, read fix_potentials function
// References:
// 1) https://cp-algorithms.com/graph/min_cost_flow.html
// 2) https://cses.fi/paste/3525f456fb3bd9b1172866/
// 3) https://cp-algorithms.com/graph/bellman_ford.html
// Sample Submission: https://codeforces.com/gym/102759/submission/108205885
// Usage: MCMF m(n), add_edge(a,b,cap,cost), mincost_maxflow(s, t)
// In case edge weights are negative, read comments on fix_potential below

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity, orig_cap;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    orig_cap.assign(N, vector<int>(N, 0));

    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
        orig_cap[e.from][e.to] = 1;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    return cost;
}

int bin_to_int(string s){
	int x = 0;
	forn(i,s.length()){
		x *= 2;
		if(s[i] == '1') x++; 
	}
	return x;
}

int link[LIM] = {0};
int sz[LIM] = {0};


int find(int x){
	if(x == link[x]) return x;
	return link[x] = find(link[x]);
}
 
void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	link[b] = a;
}

vector<Edge> e;

void add_edge(int a, int b, int cap, int cost){
	Edge ne;
	ne.from = a;
	ne.to = b;
	ne.capacity = cap;
	ne.cost = cost;
	e.pb(ne);
}

signed main(){
	fastio;

	int d, n;
	cin>>d>>n;
	ll s[n];

	int cnt = 0;

	forn(i,n){
		string x; cin>>x;
		reverse(all(x));
		s[i] = bin_to_int(x);
	}

	forn(i,n){
		link[i] = i;
		sz[i] = 1;
	}

	int source = 0, sink = 3*n+1;
	// MCMF m(3*n+2);

	forn(i,n){
		forn(j,n){
			if(i == j) continue;
			if((s[i]&s[j]) == s[i]){
				// i is submask of j
				// add edge i->j
				add_edge(i+1, 2*n+j+1, 1, 0);
			}
		}
	}

	forsn(i,1,2*n+1){
		if(i <= n){
			ll x = bitcount(s[i-1]);
			add_edge(source, i, 1, -x);
		}
		else{
			add_edge(source, i, 1, 0);
			add_edge(i, i+n, 1, 0);
		}
	}
	forsn(i,2*n+1,3*n+1){
		int k = i - 2*n - 1;
		ll x = bitcount(s[k]);
		add_edge(i, sink, 1, x);
	}

	min_cost_flow(3*n+2, e, 1e18, source, sink);
	
	forsn(i,1,n+1){
		forsn(j,2*n+1,3*n+1){
			if((capacity[i][j] == 0) && (orig_cap[i][j] == 1)){
				// cout<<"uniting "<<i-1<<" "<<j-2*n-1<<endl;
				unite(i-1,j-2*n-1);
			}
		}
	}

	v32 v[n];
	forn(i,n){
		int x = find(i);
		v[x].pb(s[i]);
	}
	forn(i,n){
		sort(all(v[i]));
	}
	int num = 0;
	forn(i,n){
		if(v[i].size() > 0) num++;
	}
	v32 op;
	forn(i,n){
		if(v[i].size() == 0) continue;
		int set[d] = {0};
		forstl(r, v[i]){
			int f = r;
			// cout<<i<<" "<<r<<endl;
			forn(k,d){
				if((f%2 == 1) && (set[k] == 0)){
					op.pb(k);
					set[k] = 1;
				}
				if(set[k] == 1) assert((f%2) == 1);
				f /= 2;
			}
		}
		num--;
		if(num != 0) op.pb(-1);
	}
	cout<<op.size()<<ln;
	forstl(r,op){
		if(r!=-1) cout<<r<<" ";
		else cout<<"R ";
	}
	cout<<ln;

	return 0;
}