#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
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

const int MOD = 1000000007;
const int MX = 100000;

ll N,S;
ll s[MX], a[MX], b[MX];
map<ll,ll> pro;
vector<pll> p;
ll sum = 0, ans = 0, num,ad;

void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> S;
	F0R(i,N) {
	    cin >> s[i] >> a[i] >> b[i];
	    sum += s[i]; ans += s[i]*a[i];
	    pro[b[i]-a[i]] += s[i];
	}
	num = (sum+S-1)/S;
	for (auto a: pro) p.pb(a);
	reverse(p.begin(),p.end());
	p.pb({-MOD,0});
}

ll calc(ll nump) {
    if (nump > sum) return -MOD;
    ll cad = 0, csum = 0;
    F0R(i,p.size()) {
        if (csum + p[i].s >= nump) {
            cad += (nump-csum)*p[i].f;
            return cad;
        }
        csum += p[i].s;
        cad += p[i].f*p[i].s;
    }
    return -MOD;
}

int main() {
    init();
	F0R(i,p.size()) if (p[i].f > 0 && p[i+1].f <= 0) {
	    ll z = 0; F0R(j,i+1) z += p[j].s;
	    
	    ll num1 = z/S;
	    ad = max(ad,calc(num1*S));
	    ad = max(ad,calc(max(sum-(num-num1-1)*S,z)));
	    break;
	}
	cout << ans+ad;
}

// read!
// ll vs. int!