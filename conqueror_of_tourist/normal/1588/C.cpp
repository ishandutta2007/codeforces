#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a)*(a))
 
#define MOO(i,a,b) for (int i=a; i<b; i++)
#define M00(i,a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define per(i,a,b) for (int i = (b)-1; i >= a; i--)
#define rep(i,a,b) for (int i=a; i<b; i++)
 
#define FOR(i,a,b) for (int i=a; i<b; i++)
#define F0R(i,a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << endl, 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _<< " _ " <<
 
//#define int long long
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
 
const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 998244353;

typedef tuple<int,ll,ll,ll,ll,ll> T;

T comb(T l, T r){
    int sz = get<0>(l); 
    ll ct  = get<1>(l);
    ll mno = get<2>(l);
    ll mxo = get<3>(l);
    ll mne = get<4>(l);
    ll mxe = get<5>(l);
    
    int sz_ = get<0>(r); 
    ll ct_  = get<1>(r);
    ll mno_ = get<2>(r);
    ll mxo_ = get<3>(r);
    ll mne_ = get<4>(r);
    ll mxe_ = get<5>(r);
    
    if (get<0>(l) % 2){
        return make_tuple(sz + sz_,
                ct - ct_,
                min(mno, ct - mxe_),
                max(mxo, ct - mne_),
                min(mne, ct - mxo_),
                max(mxe, ct - mno_));
    } else {
        return make_tuple(sz + sz_,
        ct + ct_,
        min(mno, ct + mno_),
        max(mxo, ct + mxo_),
        min(mne, ct + mne_),
        max(mxe, ct + mxe_));
    }
}


struct Tree {
	static constexpr T unit = make_tuple(0,0,0,0,0,0);
	T f(T a, T b) { return comb(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() { FAST
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi out;
        out.pb(0);
        ll op = 0;
        vll a;
        Tree seg(n);
        map<ll, int> seen;
        seen[0] = 0;
        ll curr = 0;
        for (int i = 0; i < n; i++){
            ll v;
            v = 1;
            cin >> v;
            //v = 1;
            a.pb(v);
            seg.update(i, make_tuple(1,v,v,v,0,0));
            
            if (i % 2){
                curr -= v;
            } else {
                curr += v;
            }
            
            if (seen.count(curr) > 0){
                int idx = seen[curr];
                T res = seg.query(idx, i + 1);
                //cout << idx << ' ' << i + 1 << '\n';
                if (get<2>(res) >= 0 && get<5>(res) <= 0){
                    out.pb(out[idx] + 1);
                    op += out[idx] + 1;
                } else {
                    out.pb(0);
                }
            } else{
                out.pb(0);
            }
            
            seen[curr] = i + 1;
        }
        
        cout << op << '\n';
    }
}