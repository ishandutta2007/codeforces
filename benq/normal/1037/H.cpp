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

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

void io(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (sz(s)) {
    	setIn(s+".in");
    	setOut(s+".out");
    }
}


template<class T, int SZ> struct RMQ {
    T stor[SZ][32-__builtin_clz(SZ)];
    
    T comb(T a, T b) {
        return min(a,b);
    }
    
    void build(vector<T>& x) {
        F0R(i,sz(x)) stor[i][0] = x[i];
        FOR(j,1,32-__builtin_clz(SZ)) F0R(i,SZ-(1<<(j-1))) 
            stor[i][j] = comb(stor[i][j-1],
                        stor[i+(1<<(j-1))][j-1]);
    }
    
    T query(int l, int r) {
        int x = 31-__builtin_clz(r-l+1);
        return comb(stor[l][x],stor[r-(1<<x)+1][x]);
    }
};

template<class T, int SZ> struct pseg {
    static const int LIMIT = 10000000;
    int l[LIMIT], r[LIMIT], nex = 0;
    T val[LIMIT];
    
    //// HELPER
    int copy(int cur) {
        int x = nex++;
        val[x] = val[cur], l[x] = l[cur], r[x] = r[cur];
        return x;
    }
    T comb(T a, T b) { return a+b; }
    void pull(int x) { val[x] = comb(val[l[x]],val[r[x]]); }

    //// IMPORTANT
    T query(int cur, int lo, int hi, int L, int R) {  
        if (lo <= L && R <= hi) return val[cur];
        if (R < lo || hi < L) return 0;
        int M = (L+R)/2;
        return comb(query(l[cur],lo,hi,L,M),query(r[cur],lo,hi,M+1,R));
    }
    int upd(int cur, int pos, T v, int L, int R) {
        if (R < pos || pos < L) return cur;
        
        int x = copy(cur);
        if (pos <= L && R <= pos) { val[x] += v; return x; }
        
        int M = (L+R)/2;
        l[x] = upd(l[x],pos,v,L,M), r[x] = upd(r[x],pos,v,M+1,R);
        pull(x); return x;
    }
    int build(vector<T>& arr, int L, int R) {
        int cur = nex++;
        if (L == R) {
            if (L < sz(arr)) val[cur] = arr[L];
            return cur;
        }
        
        int M = (L+R)/2;
        l[cur] = build(arr,L,M), r[cur] = build(arr,M+1,R);
        pull(cur); return cur;
    }
    
    //// PUBLIC
    vi loc;
    void upd(int pos, T v) { loc.pb(upd(loc.back(),pos,v,0,SZ-1)); }
    T query(int ti, int lo, int hi) { return query(loc[ti+1],lo,hi,0,SZ-1); }
    void build(vector<T>& arr) { loc.pb(build(arr,0,SZ-1)); }
};

pseg<int,MX> pers;

struct suffix_array {
    int N;
    RMQ<int,MX> rm;
    vector<vi> P;
    vector<array<int,3>> L;
    vi idx;
    string str;
    
    void bucket_sort(vector<array<int,3>>& v, int ind) {
        int mn = MOD, mx = -MOD;
        for (auto a: v) mn = min(mn,a[ind]), mx = max(mx,a[ind]);
        
        vi tmp(mx-mn+1), st(mx-mn+1);
        F0R(i,sz(v)) tmp[L[i][ind]-mn] ++;
        FOR(i,1,mx-mn+1) st[i] = st[i-1]+tmp[i-1];
        
        vector<array<int,3>> V(sz(v));
        F0R(i,sz(v)) V[st[v[i][ind]-mn]++] = v[i];
        v = V;
    }
    
    int lcp(int x, int y) {
        int res = 0;
        if (x == y) return N-x;
        for (int k = sz(P) - 1; k >= 0 && x < N && y < N; k--) {
            if (P[k][x] == P[k][y]) {
                x += 1 << k;
                y += 1 << k;
                res += 1 << k;
            }
        }
        return res;
    }
    
    void build (string _str) {
        str = _str; N = sz(str);
        P.pb(vi(N)); L.resize(N);
        F0R(i,N) P[0][i] = str[i];
        
        for (int stp = 1, cnt = 1; cnt < N; stp ++, cnt *= 2) {
            P.pb(vi(N));
            F0R(i,N) L[i] = {P[stp-1][i],i+cnt < N ? P[stp-1][i+cnt] : -1,i};
            bucket_sort(L,1); bucket_sort(L,0); // sort(all(L));
            F0R(i,N) {
                if (i && mp(L[i][0],L[i][1]) == mp(L[i-1][0],L[i-1][1])) P[stp][L[i][2]] = P[stp][L[i-1][2]];
                else P[stp][L[i][2]] = i;
            }
        }
        
        idx.resize(N);
        F0R(i,sz(P.back())) idx[P.back()[i]] = i;
        
        vi tmp; F0R(i,sz(idx)-1) tmp.pb(lcp(idx[i],idx[i+1]));
        vi arr; pers.build(arr);
        F0R(i,sz(idx)) pers.upd(idx[i],1);
        rm.build(tmp);
    }
    
    int LCP(int L, int R) {
		return rm.query(L,R-1);
	}
    
    int common(int mid, string x) {
		mid = idx[mid];
		int len = 0;
		while (len < sz(x) && mid+len < sz(str) && x[len] == str[mid+len]) len ++;
		return len;
	}
	
    bool greater(int mid, string x) {
		int len = common(mid,x);
		mid = idx[mid];
		if (mid+len == sz(str)) return 0;
		if (len == sz(x)) return 1;
		return str[mid+len] > x[len];
	}
};

suffix_array S;

int get(int x0, int x1, int y0, int y1) {
    if (y0 > y1) return -1;
	int lo = x0, hi = x1+1;
	int ori = pers.query(x0-1,y0,y1);
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (pers.query(mid,y0,y1) > ori) hi = mid;
		else lo = mid+1;
	}
	if (lo == x1+1) return -1;
	return S.idx[lo];
}

pi getNex(int cur, int mxlen) {
	int lo = cur+1, hi = sz(S.str);
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (S.LCP(cur,mid) <= mxlen) hi = mid;
		else lo = mid+1;
	}
	return {lo,S.LCP(cur,lo)};
}

string solve(int l, int r, string x) {
    int lo = 0, hi = sz(S.str); // first one >
    while (lo < hi) {
		int mid = (lo+hi)/2;
		if (S.greater(mid,x)) hi = mid;
		else lo = mid+1;
	}
	if (lo == sz(S.str)) return "-1";
	int share = S.common(lo,x);
	while (lo < sz(S.str)) {
		pi tmp = getNex(lo,share-1);
		int t = get(lo,tmp.f-1,l,r-share);
		if (t != -1) return S.str.substr(t,share+1);
		lo = tmp.f; share = tmp.s;
	}
	return "-1";
}

int main() {
    io();
    string s; cin >> s;
    S.build(s);
    
    int q; cin >> q;
    F0R(i,q) {
        int l,r; string x; l = 1, r = 1;
        // int len = rand() % 100+1; F0R(j,len) x += char('a'+(rand()%2)); 
        cin >> l >> r >> x;
        cout << solve(l-1,r-1,x) << "\n";
    }
}

/* 
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/