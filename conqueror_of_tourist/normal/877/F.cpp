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


typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;

const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 1e9+7;

int32_t main() { FAST
	ll n, k;
	cin >> n >> k;
	
	vll t(n);
	for (int i = 0; i < n; i++){
	    cin >> t[i];
	}
	
	vll a(n);
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	}
	
	vll pref (n + 1, 0);
	
	for (int i = 0; i < n; i++){
	    if (t[i] == 1){
	        pref[i + 1] = pref[i] + a[i];
	    } else {
	        pref[i + 1] = pref[i] - a[i];
	    }
	}
	
	ll q;
	cin >> q;
	
	int SPL = 400;
	
	vll out(q, 0);
	
	
	vector<tuple<ll,ll,ll,ll>> qs;
	for (ll i = 0; i < q; i++){
	    ll a,b;
	    cin >> a >> b;
	    ll u = a/SPL;
	    ll m = 1;
	    
	    if (u % 2){
	        m = -1;
	    }
	    
	    qs.pb(make_tuple((1000000LL * (a/SPL)) + m*b,i,a-1,b));
	}
	
	sort(qs.begin(), qs.end());
	
	int left = 0;
	int right = 0;
	
	
	
	ll res = 0;
	unordered_map<ll,int> count;
	count[0] += 1;
	
	for (auto tup : qs){
	    auto & [ w, i, l, r ] = tup;
	    
	   while (right < r){
            right += 1;
            res += count[pref[right] - k];
            count[pref[right]] += 1;
	   }
            
    
        while (left > l){
            ll rem = pref[left - 1] + k;
            res += count[rem];
            left -= 1;
            count[pref[left]] += 1;
        }
    
        while (right > r){
            count[pref[right]] -= 1;
            res -= count[pref[right] - k];
            right -= 1;
        }
            
    
        while (left < l){
            ll rem = pref[left] + k;
            count[pref[left]] -= 1;
            left += 1;
            res -= count[rem];
        }
	    
	    out[i] = res;
	}
	
	/*
	*/
	
	for(auto o : out){
	    cout << o << '\n';
	}
}