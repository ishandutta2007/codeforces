#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int LOG = 70;

ll cnt[2][LOG];

void show(ll x){
	ll lv = 0, temp = x;
	while (temp>1){
		temp >>= 1;
		lv++;
	}

	while (x > 1){
		cout << x << " ";
		ll mx = (1ll<<lv+1) - 1;
		x += cnt[0][lv];
		if (x > mx)
			x -= 1ll<<lv;
	
		x /= 2;
		mx = (1ll<<lv) - 1;
		x += cnt[1][lv];
		if (x > mx)
			x -= 1ll<<lv-1;
		lv--;
	}

	cout << "1\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--){
		int type; cin >> type;
		if (type == 3){
			ll x; cin >> x;
			show(x);
		}
		else if (type == 2){
			ll x, k; cin >> x >> k;
			ll lv = 0, temp = x;
			while (temp>1){
				temp >>= 1;
				lv++;
			}
			k = -k;

			ll MOD = 1ll<<lv;
			cnt[0][lv] -= k;
			cnt[0][lv] = (cnt[0][lv]%MOD+MOD)%MOD;
		}
		else{
			ll x, k; cin >> x >> k;
			ll lv = 0, temp = x;
			while (temp>1){
				temp >>= 1;
				lv++;
			}
			k = -k;

			ll MOD = 1ll<<lv;
			cnt[0][lv] -= k;
			cnt[0][lv] = (cnt[0][lv]%MOD+MOD)%MOD;
			cnt[1][lv+1] += k;
			cnt[1][lv+1] = (cnt[1][lv+1]%MOD+MOD)%MOD;
		}
	}
	return 0;
}