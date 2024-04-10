#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

int n, mod;
int a[100007];
vector<int> t;

int phi(int x){
	int ans = x;
	for (int i = 2; i * i <= x; i++) if (x % i == 0){
		ans -= ans / i;
		while(x % i == 0) x /= i;
	}
	if (x > 1) ans -= ans / x;
	return ans;
}

int magic = 10;

ll myMod(ll a, int mod){
	if (a >= magic){
		return magic + (a - magic) % mod;
	}
	return a;
}

ll bp(ll a, ll k, int mod){
	if (k == 1) return myMod(a, mod);
	if (k % 2 == 0){
		ll q = bp(a, k / 2, mod);
		return myMod(q * (ll)q, mod);
	} else {
		return myMod(a * (ll)bp(a, k - 1, mod), mod);
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> mod;
	for (int i = 0; i < n; i++) cin >> a[i];
	t.pub(mod);
	while(t.back() != 1) t.pub(phi(t.back()));
	int m;
	cin >> m;
	while(m--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		r = min(r, l + (int)t.size() - 1);
		ll ans = 1;
		for (int i = r; i >= l; i--){
			ans = bp(a[i], ans, t[i - l]);
		}
		cout << ans % mod << "\n";
	}
}