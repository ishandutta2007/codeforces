#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int MOD = 1000000007; // 998244353
// const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(ld& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        pr(first); pr(rest...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
    
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) { 
        pr(first); ps(); // no space at end of line
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
        pr(first," "); ps(rest...); // print w/ spaces
    }
}

using namespace output;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

template<class T> T invGeneral(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invGeneral(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    modular(const ll& v) { 
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    
    // friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend void pr(const modular& a) { pr(a.val); }
    friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular pow(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { 
        auto i = invGeneral(a.val,MOD); assert(i != -1);
        return i;
    } // equivalent to return exp(b,MOD-2) if MOD is prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*template<int SZ> struct Hungarian {
	#define INF 100000000 //just infinity
	
	int cost[SZ][SZ]; //cost matrix
	int n, max_match; //n workers and n jobs
	int lx[SZ], ly[SZ]; //labels of X and Y parts
	int xy[SZ]; //xy[x] - vertex that is matched with x,
	int yx[SZ]; //yx[y] - vertex that is matched with y
	bool S[SZ], T[SZ]; //sets S and T in algorithm
	int slack[SZ]; //as in the algorithm description
	int slackx[SZ]; //slackx[y] such a vertex, that
	// l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
	int pre[SZ]; //array for memorizing alternating paths
	
	void init_labels() {
		memset(lx, 0, sizeof(lx)); memset(ly, 0, sizeof(ly));
		F0R(x,n) F0R(y,n) ckmax(lx[x],cost[x][y]);
	}
	
	void update_labels() {
		int x, y, delta = INF; //init delta as infinity
		F0R(y,n)  if (!T[y]) ckmin(delta,slack[y]); //calculate delta using slack
		F0R(x,n) if (S[x]) lx[x] -= delta; //update X labels
		F0R(y,n) if (T[y]) ly[y] += delta; //update Y labels
		F0R(y,n) if (!T[y]) slack[y] -= delta; //update slack array
	}
	
	void add_to_tree(int x, int prex) {
		//x - current vertex,prex - vertex from X before x in the alternating path,
		//so we add edges (prex, xy[x]), (xy[x], x)
		S[x] = true; //add x to S
		pre[x] = prex; //we need this when augmenting
		F0R(y,n) //update slacks, because we add new vertex to S
			if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
				slack[y] = lx[x] + ly[y] - cost[x][y];
				slackx[y] = x;
			}
	}
	
	void augment()  { //main function of the algorithm
		if (max_match == n) return; //check wether matching is already perfect
		int x, y, root; //just counters and root vertex
		queue<int> q; //pos in queue
		memset(S, false, sizeof(S)); //init set S
		memset(T, false, sizeof(T)); //init set T
		memset(pre, -1, sizeof(pre)); //init set pre - for the alternating tree
		F0R(x,n) //finding root of the tree
			if (xy[x] == -1) {
				q.push(root = x);
				pre[x] = -2;
				S[x] = true;
				break;
			}
		F0R(y,n) { //initializing slack array
			slack[y] = lx[root] + ly[y] - cost[root][y];
			slackx[y] = root;
		}
	
		//second part of augment() function
		while (1)  {
			while (sz(q)) { //building tree with bfs cycle
				x = q.front(); q.pop(); //current vertex from X part
				for (y = 0; y < n; y++) //iterate through all edges in equality graph
					if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
						if (yx[y] == -1) break; //an exposed vertex in Y found, so
						//augmenting path exists!
						T[y] = true; //else just add y to T,
						q.push(yx[y]); //add vertex yx[y], which is matched
						//with y, to the queue
						add_to_tree(yx[y], x); //add edges (x,y) and (y,yx[y]) to the tree
					}
				if (y < n) break; //augmenting path found!
			}
			if (y < n) break; //augmenting path found!
			update_labels(); //augmenting path not found, so improve labeling
	
			//in this cycle we add edges that were added to the equality graph as a
			//result of improving the labeling, we add edge (slackx[y], y) to the tree if
			//and only if !T[y] && slack[y] == 0, also with this edge we add another one
			//(y, yx[y]) or augment the matching, if y was exposed
			F0R(y,n) if (!T[y] && slack[y] == 0) {
				if (yx[y] == -1) { //exposed vertex in Y found - augmenting path exists!
					x = slackx[y];
					break;
				} else {
					T[y] = true; //else just add y to T,
					if (!S[yx[y]]) {
						q.push(yx[y]); //add vertex yx[y], which is matched with
						//y, to the queue
						add_to_tree(yx[y], slackx[y]); //and add edges (x,y) and (y,
						//yx[y]) to the tree
					}
				}
			}
			if (y < n) break; //augmenting path found!
		}
		if (y < n) {//we found augmenting path!
			max_match++; //increment matching
			//in this cycle we inverse edges along augmenting path
			for (int cx = x, cy = y, ty; cx != -2; cx = pre[cx], cy = ty) {
				ty = xy[cx];
				yx[cy] = cx;
				xy[cx] = cy;
			}
			augment(); //recall function, go to step 1 of the algorithm
		}
	}//end of augment() function
	
	int solve(int _n) {
		// F0R(i,SZ) lx[i] = ly[i] = xy[i] = yx[i] = S[i] = T[i] = slack[i] = slackx[i] = pre[i] = 0;
		n = _n;
		max_match = 0; //number of vertices in current matching
		memset(xy, -1, sizeof(xy));
		memset(yx, -1, sizeof(yx));
		init_labels(); //step 0
		exit(0);
		augment(); //steps 1-3
		int ret = 0; //weight of the optimal matching
		F0R(x,n) ret += cost[x][xy[x]]; //forming answer there
		// ps("HUH",ret); exit(0);
		return ret;
	}
};

Hungarian<20> H;*/

int N,tmp[2][21][21],cost[21][21],ans=-MOD;
int minv[21]; 
bool used[21];
const int INF = (int)1e9;

int co = 0;

void dfs(int a, int b, vi U, vi V, vi P) {
	if (a == N+1) {
		// ps("HA");
		// ps("HUH",V[0]);
		ckmax(ans,V[0]);
		return;
	}
	F0R(i,2) { // thanks tourist :o
		if (i == 0 && a-1-b == N/2) continue;
		if (i == 1 && b == N/2) continue;
		FOR(j,1,N+1) cost[a][j] = 1000000-tmp[i][a][j];
		auto u = U, v = V, p = P;
		vi way(N+1);
		
	  	p[0] = a; int j0 = 0;
	  	F0R(j,N+1) minv[j] = INF, used[j] = false; 
	  	do {
	  		used[j0] = true;
	  		int i0 = p[j0], delta = INF, j1;
	  		FOR(j,1,N+1) if (!used[j]) {
  				int cur = cost[i0][j]-u[i0]-v[j]; assert(cur >= 0);
  				if (cur < minv[j]) minv[j] = cur,  way[j] = j0;
  				if (minv[j] < delta) delta = minv[j],  j1 = j;
  			}
  			F0R(j,N+1)
	  			if (used[j]) u[p[j]] += delta, v[j] -= delta;
	  			else minv[j] -= delta;
	  		j0 = j1;
	  	} while (p[j0]);
	  	do {
	  		int j1 = way[j0];
	  		p[j0] = p[j1];
	  		j0 = j1;
	  	} while (j0);
		dfs(a+1,b+i,u,v,p);
	}
}

int main() {
    setIO(); re(N);
    F0R(i,2) FOR(j,1,N+1) FOR(k,1,N+1) re(tmp[i][j][k]);
    dfs(1,0,vi(N+1),vi(N+1),vi(N+1));
    ps(ans+1000000*N);
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/