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
// typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

namespace io {
    template<typename Test, template<typename...> class Ref>
    struct is_specialization : std::false_type {};

    template<template<typename...> class Ref, typename... Args>
    struct is_specialization<Ref<Args...>, Ref>: std::true_type {};
    // https://stackoverflow.com/questions/16337610/how-to-know-if-a-type-is-a-specialization-of-stdvector

    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
    
    // INPUT 
    
    // double input seems slow on CF
    void re(double& x) { string t; cin >> t; x = stod(t); } 
    void re(ld& x) { string t; cin >> t; x = stold(t); }
    template<class T> void re(T& x) { cin >> x; }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
        re(first); re(rest...); 
    }
    template<class T1, class T2> istream& operator>>(istream& is, pair<T1,T2>& p) {
        is >> p.f >> p.s; return is;
    }
    template<class T> istream& operator>>(istream& is, vector<T>& a) {
        F0R(i,sz(a)) is >> a[i];
        return is;
    }
    
    // OUTPUT 
    
    template<class T> void pr(const T& x) { cout << x << '\n'; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
        cout << first << ' '; pr(rest...); 
    }
    template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) {
        os << '{' << a.f << ", " << a.s << '}'; return os;
    }
    template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
        os << '{';
        F0R(i,sz(a)) {
            if (i) {
                os << ", ";
                if (is_specialization<T, vector>::value) os << '\n';
            }
            os << a[i];
        }
        os << '}';
        return os;
    }
}

using namespace io;


typedef double T;
typedef vector<T> vd;
typedef vector<vd> vvd;

const T eps = 1e-8, inf = 1/.0;
#define ltj(X) if(s == -1 || mp(X[j],N[j]) < mp(X[s],N[s])) s=j

struct LPSolver {
	int m, n;
	vi N, B;
	vvd D;

	LPSolver(const vvd& A, const vd& b, const vd& c) :
		m(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {
			F0R(i,m) F0R(j,n) D[i][j] = A[i][j];
			F0R(i,m) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i];}
			F0R(j,n) { N[j] = j; D[m][j] = -c[j]; }
			N[n] = -1; D[m+1][n] = 1;
		}

	void pivot(int r, int s) { // row, column
		T *a = D[r].data(), inv = 1 / a[s]; // eliminate col s from consideration?
		F0R(i,m+2) if (i != r && abs(D[i][s]) > eps) {
			T *b = D[i].data(), inv2 = b[s] * inv;
			F0R(j,n+2) b[j] -= a[j] * inv2;
			b[s] = a[s] * inv2;
		}
		F0R(j,n+2) if (j != s) D[r][j] *= inv;
		F0R(i,m+2) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv;
		swap(B[r], N[s]);
	}

	bool simplex(int phase) {
		int x = m + phase - 1;
		for (;;) {
			int s = -1;
			F0R(j,n+1) if (N[j] != -phase) ltj(D[x]); // find most negative col
			if (D[x][s] >= -eps) return true;
			int r = -1;
		    F0R(i,m) {
				if (D[i][s] <= eps) continue;
				if (r == -1 || mp(D[i][n+1] / D[i][s], B[i])
				             < mp(D[r][n+1] / D[r][s], B[r])) r = i; // find smallest positive ratio
			}
			if (r == -1) return false;
			pivot(r, s); 
		}
	}

	T solve(vd &x) {
		int r = 0;
    	FOR(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
		if (D[r][n+1] < -eps) {
			pivot(r, n);
			if (!simplex(2) || D[m+1][n+1] < -eps) return -inf;
			F0R(i,m) if (B[i] == -1) {
				int s = 0;
				FOR(j,1,n+1) ltj(D[i]);
				pivot(i, s);
			}
		}
		bool ok = simplex(1); x = vd(n);
		F0R(i,m) if (B[i] < n) x[B[i]] = D[i][n+1];
		return ok ? D[m][n+1] : inf;
	}
};

vvd A;
vd B,C;

int n,x,sum;
vpi adj[500];

int co = 0;

void addIneq(vi a, int b) {
    vd tmp(all(a)); 
    F0R(i,co) tmp.pb(0);
    tmp.pb(1);
    co ++;
    for (auto& z: A) z.pb(0);
    A.pb(tmp);
    B.pb(b);
    C.pb(0);
}

ll dist[500];

void dfs(int i, int p) {
    for (auto a: adj[i]) if (a.f != p) {
        dist[a.f] = dist[i]+a.s;
        dfs(a.f,i);
    }
}

int main() {
    setIO(); re(n,x);
    vi col(n); re(col);
    for (int i: col) {
        sum += i;
        C.pb(i-1);
    }
    F0R(i,n-1) {
        int u,v,w; re(u,v,w); u--,v--;
        adj[u].pb({v,w}), adj[v].pb({u,w});
    }
    // sum(a) <= sum, sum(a) >= sum
    addIneq(vi(n,1),sum);
    addIneq(vi(n,-1),-sum);
    F0R(i,n) {
        dist[i] = 0; dfs(i,-1);
        vi tmp(n);
        F0R(j,n) if (dist[j] <= x) tmp[j] = -1;
        addIneq(tmp,-1);
    }
    LPSolver L(A,B,C);
    vd x;
    ld res = L.solve(x);
    if (res == -inf) {
        cout << -1;
    } else cout << (ll)round(-res);
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/