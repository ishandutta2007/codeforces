#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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
#define M_PIl 3.141592653589793238462643383279502884L 

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

namespace FFT {
    int get(int s) {
        return s > 1 ? 32 - __builtin_clz(s - 1) : 0;
    }
    
    void fft(vcd& a, bool inv){
    	int n = sz(a), j = 0;
    	vcd roots(n/2);
    	FOR(i,1,n) {
    		int bit = (n >> 1);
    		while (j >= bit){
    			j -= bit;
    			bit >>= 1;
    		}
    		j += bit;
    		if(i < j) swap(a[i], a[j]);
    	}

    	ld ang = 2 * M_PIl / n * (inv ? -1 : 1);
    	F0R(i,n/2) roots[i] = cd(cos(ang * i), sin(ang * i));
    
    	for (int i=2; i<=n; i<<=1){
    		int step = n / i;
    		for(int j=0; j<n; j+=i){
    			for(int k=0; k<i/2; k++){
    				cd u = a[j+k], v = a[j+k+i/2] * roots[step * k];
    				a[j+k] = u+v;
    				a[j+k+i/2] = u-v;
    			}
    		}
    	}
    	
    	if (inv) F0R(i,n) a[i] /= n;
    }
    
    vl conv(vl a, vl b, ll mod){
        int s = sz(a)+sz(b)-1, L = get(s), n = 1<<L;
        
    	vcd v1(n), v2(n), r1(n), r2(n);
    	F0R(i,sz(a)) v1[i] = cd(a[i] >> 15, a[i] & 32767);
    	F0R(i,sz(b)) v2[i] = cd(b[i] >> 15, b[i] & 32767);
    	fft(v1, 0); fft(v2, 0);
    	
    	F0R(i,n) {
    		int j = (i ? (n - i) : i);
    		cd ans1 = (v1[i] + conj(v1[j])) * cd(0.5, 0);
    		cd ans2 = (v1[i] - conj(v1[j])) * cd(0, -0.5);
    		cd ans3 = (v2[i] + conj(v2[j])) * cd(0.5, 0);
    		cd ans4 = (v2[i] - conj(v2[j])) * cd(0, -0.5);
    		r1[i] = (ans1 * ans3) + (ans1 * ans4) * cd(0, 1);
    		r2[i] = (ans2 * ans3) + (ans2 * ans4) * cd(0, 1);
    	}
    	fft(r1, 1); fft(r2, 1);
        vl ret(n);
    	F0R(i,n) {
    		ll av = (ll)round(r1[i].real());
    		ll bv = (ll)round(r1[i].imag()) + (ll)round(r2[i].real());
    		ll cv = (ll)round(r2[i].imag());
    		av %= mod, bv %= mod, cv %= mod;
    		ret[i] = (av << 30) + (bv << 15) + cv;
    		ret[i] %= mod; ret[i] += mod; ret[i] %= mod;
    	}
    	ret.resize(s);
    	return ret;
    }
}

ll n,x;
vl v, V;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x; v.resize(n+1); V.resize(n+1);
    int cur = 0; v[cur] ++; V[n-cur] ++;
    
    F0R(i,n) {
        int a; cin >> a;
        if (a < x) cur ++;
        v[cur] ++;
        V[n-cur] ++;
    }
    
    vl t = FFT::conv(v,V,1e12);
    ll tot = n*(n+1)/2;
    FOR(i,n+1,2*n+1) tot -= t[i];
    t[n] = tot;
    FOR(i,n,2*n+1) cout << t[i] << " ";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS