














#include <bits/stdc++.h> 

using namespace std; 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define gi get_int() 
#define x1 xxx111
#define y1 yyy111
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll cnn = 800, md = 1000000007, sz_g = 200000, pq = 100000000, inf = 1000000000LL,
 mod2 = 5000000, ma = 128 * 1024, ma1 = 8, inf11 = 5LL * inf * inf;

void my_assert() {
	while(true);
}
ll llabs(int k) {
	if (k < 0) re -k;
	re k;
}
ll get_int() {
	int n;
	scanf("%d", &n);
	re n;
}


int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("sum.in", "r", stdin);
    //freopen("kingrook.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    ll k1 = 1, p = 7, k2 = 1, p2 = 7;
    while (p < n) {
    	p *= 7LL;
    	k1++;
    }
    while (p2 < m) {
    	p2 *= 7LL;
    	k2++;
    }
    int ans = 0;
    //cout << k1 << " " << k2 << endl;
    for (int i = 0; i < (1 << 7); i++) {
    	vector<int> cc;
    	for (int j = 0; j <= 6; j++)
    		if (i & (1 << j)) cc.push_back(j);
    	if (sz(cc) == k1 + k2) {
    		do {
    			ll kk = 0, pp = 0;
    			forn (i, k1) {
    				kk = kk * 7LL + cc[i];
    			}
    			forn (i, k2)
    				pp = pp * 7LL + cc[i + k1];
    			if (kk < n && pp < m) {
    				//cout << kk << " " << pp << endl;
    				ans++;
    			}
    		}
    		while (next_permutation(cc.begin(), cc.end()));
    	}
    }
    cout << ans;
    return 0;
}