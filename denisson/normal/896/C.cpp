#include <bits/stdc++.h>
                   
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

struct st{
	int l, r;
	ll x;
	st() {}
	st(int l1, int r1, ll x1) { l = l1, r = r1, x = x1; }
	bool operator< (st nxt) const { return l < nxt.l; }
};

int n, m, seed, vmax;
int a[100007];
set<st> se;

int rnd(){
	int ret = seed;
	seed = ((ll)seed * 7 + 13) % 1000000007;
	return ret;
}

int bp(ll a, int k, int mod){
    a %= mod;
	if (k == 1) return a % mod;
	if (k % 2 == 0){
		int q = bp(a, k / 2, mod);
		return q * (ll)q % mod;
	} else {
		return a * (ll)bp(a, k - 1, mod) % mod;
	}
}

st tmp[100007];
pair<ll, int> tt[100007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> seed >> vmax;

    for (int i = 1; i <= n; i++) a[i] = rnd() % vmax + 1;


    int last = 1;
	for (int i = 2; i <= n; i++){
		if (a[i] != a[i - 1]){
			se.insert(st(last, i - 1, a[last]));
			last = i;
		}
	}
	se.insert(st(last, n, a[n]));


    for (int i = 1; i <= m; i++){
    	int type = rnd() % 4 + 1;
    	int l = rnd() % n + 1;
    	int r = rnd() % n + 1;
    	if (l > r) swap(l, r);
    	int x, y = -1;
    	if (type == 3) x = rnd() % (r - l + 1) + 1;
    	else x = rnd() % vmax + 1;
    	if (type == 4) y = rnd() % vmax + 1;
    	
    	//cout << type << ' ' << l << ' ' << r << ' ' << x << ' ' << y << endl;

    	if (type == 1){
    		auto pos = se.upper_bound(st(l, -1, -1)); pos--;
    		int kk = 0;
    		while(1){
    			if (pos == se.end()) break;
    			if (pos->l > r) break;
    			tmp[kk++] = *pos;
    			pos++;
    		}
    		for (int s = 0; s < kk; s++){
    			se.erase(tmp[s]);
    			if (tmp[s].l < l){
    				se.insert(st(tmp[s].l, l - 1, tmp[s].x));
    			}
    			if (tmp[s].r > r){
    				se.insert(st(r + 1, tmp[s].r, tmp[s].x));
    			}
    			int ln = max(l, tmp[s].l);
    			int rn = min(r, tmp[s].r);
    			se.insert(st(ln, rn, tmp[s].x + (ll)x));
    		}
    	} else if (type == 2){
    		auto pos = se.upper_bound(st(l, -1, -1)); pos--;
    		int kk = 0;
    		while(1){
    			if (pos == se.end()) break;
    			if (pos->l > r) break;
    			tmp[kk++] = *pos;
    			pos++;
    		}
    		//cout << kk << endl;
    		for (int s = 0; s < kk; s++){
    			se.erase(tmp[s]);
    			if (tmp[s].l < l){
    				se.insert(st(tmp[s].l, l - 1, tmp[s].x));
    			}
    			if (tmp[s].r > r){
    				se.insert(st(r + 1, tmp[s].r, tmp[s].x));
    			}
    		}
    		se.insert(st(l, r, x));
    	} else if (type == 3){
    		auto pos = se.upper_bound(st(l, -1, -1)); pos--;
    		int kk = 0;
    		while(1){
    			if (pos == se.end()) break;
    			if (pos->l > r) break;
    			tmp[kk++] = *pos;
    			tmp[kk - 1].l = max(tmp[kk - 1].l, l);
    			tmp[kk - 1].r = min(tmp[kk - 1].r, r);
    			pos++;
    		}
    		int ww = 0;
    		for (int s = 0; s < kk; s++) tt[ww++] = mp(tmp[s].x, tmp[s].r - tmp[s].l + 1);
    		sort(tt, tt + ww);
    		ll ans = -1;
    		for (int s = 0; s < ww; s++){
    			if (tt[s].y >= x){
    				ans = tt[s].x;
    				break;
    			} else x -= tt[s].y;
    		}
    		cout << ans << "\n";
    	} else {
    		int ans = 0;
    		auto pos = se.upper_bound(st(l, -1, -1)); pos--;
    		while(1){
    			if (pos == se.end()) break;
    			int ln = max(l, pos->l);
    			int rn = min(r, pos->r);
    			if (ln > rn) break;
    			ans += bp(pos->x, x, y) * (ll)(rn - ln + 1) % y;
    			if (ans >= y) ans -= y;
    			pos++;
    		}
    		cout << ans << "\n";
    	}
	//for (auto c : se) cout << c.l << ' ' << c.r << ' ' << c.x << endl;

    }
}