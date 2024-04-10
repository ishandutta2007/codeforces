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


template<int SZ> struct sieve { 
	bitset<SZ> comp;
	vi pr;
	int sp[SZ];
	vpi tmp[SZ];
	vi res[SZ];

	sieve() {
		FOR(i,2,SZ) { // O(N) sieve
			if (sp[i] == 0) { sp[i] = i; pr.pb(i); }
			for (int p : pr) {
				if (p > sp[i] || i*p >= SZ) break;
				sp[i*p] = p;
			}
		}
	}
};

sieve<1000001> S;
// map<vi,map<int,int>> dist;

using namespace io;

int numDivi(vi v) {
    int res = 1;
    for (auto a: v) res *= a+1;
    return res;
}

int sum(vi v) {
    int t = 0; for (int i: v) t += i;
    return t;
}

map<vi,int> al;
int diviCount[MX];
vi adj[MX], dist[MX];

ld getmn(vi v) {
    reverse(all(v));
    ld t = 1;
    F0R(i,sz(v)) F0R(j,v[i]) t *= S.pr[i];
    return t;
}

void search(vi v) {
    if (getmn(v) > 1e12) return;
    if (al.count(v)) return;
    al[v] = 0;
    F0R(i,sz(v)) if (i == sz(v)-1 || v[i] <= v[i+1]) {
        vi V = v; V[i] ++;
        search(V);
    }
    v.insert(v.begin(),1); search(v);
}

void init() {
    setIO();
    FOR(i,2,1000001) {
        vpi v = S.tmp[i/S.sp[i]];
        if (!sz(v) || v.back().f != S.sp[i]) v.pb({S.sp[i],0});
        v.back().s ++;
        S.tmp[i] = v;
        
        vi res; for (auto a: v) res.pb(a.s); sort(all(res));
        S.res[i] = res;
    }
    search({});
    int co = 0;
    for (auto& a: al) a.s = co++;
    vi z;
    for (auto a: al) {
        diviCount[a.s] = numDivi(a.f);
        z.pb(diviCount[a.s]);
        vi v = a.f;
        F0R(i,sz(v)) if (i == sz(v)-1 || v[i] <= v[i+1]) {
            vi V = v; V[i] ++;
            if (al.count(V)) adj[a.s].pb(al[V]), adj[al[V]].pb(a.s);
        }
        v.insert(v.begin(),1); 
        if (al.count(v)) adj[a.s].pb(al[v]), adj[al[v]].pb(a.s);
    }
    sort(all(z)); z.erase(unique(all(z)),z.end());
    // cout << sz(al) << " " << sz(z) << "\n" << z;
    for (int i: z) {
        F0R(j,sz(al)) dist[j].pb(MOD);
        queue<int> q;
        F0R(j,sz(al)) if (diviCount[j] == i) {
            dist[j].back() = 0; q.push(j);
        }
        while (sz(q)) {
            int x = q.front(); q.pop();
            for (int i: adj[x]) if (dist[i].back() == MOD) {
                dist[i].back() = dist[x].back()+1;
                q.push(i);
            }
        }
    }
}

int main() {
    init();
    int Q; re(Q);
    F0R(i,Q) {
        int a,b; re(a,b);
        int A = al[S.res[a]], B = al[S.res[b]];
        // cout << A << " " << 
        int ans = MOD;
        F0R(j,sz(dist[A])) ans = min(ans,dist[A][j]+dist[B][j]);
        cout << ans << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/