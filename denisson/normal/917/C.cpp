#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const ll LINF = (ll)1e18 + 7;

int w1, w2, n, q;
ll cost[11];

struct st{
	ll a[77][77];
	st() { for (int i = 0; i < 77; i++) for (int j = 0; j < 77; j++) a[i][j] = 0; }
};

st t;
ll dp[77];
vector<int> w;

st func(st &a, st b){
	st ans;
	for (int i = 0; i < w.size(); i++){
		for (int j = 0; j < w.size(); j++){
			ans.a[i][j] = LINF;
			for (int s = 0; s < w.size(); s++) ans.a[i][j] = min(ans.a[i][j], a.a[i][s] + b.a[s][j]);
		}
	}
	return ans;
}

st bp(st a, int k){
	if (k == 1) return a;
	if (k % 2 == 1){
		return func(a, bp(a, k - 1));
	} else {
		auto tmp = bp(a, k >> 1);
		return func(tmp, tmp);
	}
}

ll tmp[77];

int x[77];
ll cc[77];

int main(){
   //	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> w1 >> w2 >> n >> q;
    for (int i = 0; i < w2; i++) cin >> cost[i];
	for (int mask = 0; mask < (1 << w2); mask++) if (__builtin_popcount(mask) == w1) w.pb(mask);
	for (int i = 0; i < 77; i++) for (int j = 0; j < 77; j++) t.a[i][j] = LINF;
	map<int, int> to;
	for (int i = 0; i < w.size(); i++) to[w[i]] = i;
	for (int i = 0; i < w.size(); i++){
		int mask = w[i];
		if (mask % 2 == 0){
			t.a[i][to[mask >> 1]] = 0;
		} else {
			for (int len = 0; len < w2; len++){
				int now = mask >> 1;
				if (!((now >> len) & 1)) t.a[i][to[now ^ (1 << len)]] = cost[len];
			}
		}
	}

	for (int i = 0; i < 77; i++) dp[i] = LINF;
	int startMask = 0;
	for (int i = 0; i < w1; i++) startMask ^= (1 << i);

	dp[to[startMask]] = 0;
	
	int pos = 1;
	map<int, ll> getFunc;
	vector<pair<int, int> > suki(q);
	for (int i = 0; i < q; i++) cin >> suki[i].x >> suki[i].y;
	sort(all(suki));
	for (int i = 0; i < q; i++) x[i] = suki[i].x, cc[i] = suki[i].y, getFunc[x[i]] = cc[i];


	int uk = 0;

	while(1){
		while(uk < q && x[uk] < pos) uk++;
		int can;
		if (uk == q){
			can = (n - w1 + 1) - pos;
		} else {
			can = (x[uk] - 1) - (pos + w2 - 1);
		}
		can = max(can, 0);
		//cout << "wtf" << can << endl;
		//if (can < 0) assert(0);
		if (can != 0){
			
			/*while(can--){
				for (int i = 0; i < 77; i++) tmp[i] = LINF;
				for (int i = 0; i < w.size(); i++){
					if (w[i] % 2 == 0){
						tmp[to[w[i] >> 1]] = min(tmp[to[w[i] >> 1]], dp[i]);
					} else {
						for (int len = 0; len < w2; len++){
							int gg = w[i] >> 1;
							if (!((gg >> len) & 1)){
								gg ^= (1 << len);
								tmp[to[gg]] = min(tmp[to[gg]], dp[i] + cost[len] + getFunc[pos + len + 1]);
							}
						}
					}
				}
				for (int i = 0; i < 77; i++) dp[i] = tmp[i];
				pos++;
			}*/

			auto now = bp(t, can);

			/*for (int i1 = 0; i1 < 3; i1++){
				for (int j1 = 0; j1 < 3; j1++){
					cout << now.a[i1][j1] << ' ';
				}
				cout << endl;
			}*/

			for (int i = 0; i < w.size(); i++){
				tmp[i] = LINF;
				for (int j = 0; j < w.size(); j++){
					tmp[i] = min(tmp[i], dp[j] + now.a[j][i]);
				}
			}
			for (int i = 0; i < w.size(); i++) dp[i] = tmp[i];
			pos += can;
		}
		//cout << pos << endl;
		//for (int i = 0; i < w.size(); i++){
		//	cout << w[i] << ' ' << dp[i] << endl;
		//}
		//exit(0);
		if (pos + w1 - 1 == n) break;
		while(1){
			for (int i = 0; i < 77; i++) tmp[i] = LINF;
			for (int i = 0; i < w.size(); i++){
				if (w[i] % 2 == 0){
					tmp[to[w[i] >> 1]] = min(tmp[to[w[i] >> 1]], dp[i]);
				} else {
					for (int len = 0; len < w2; len++){
						int gg = w[i] >> 1;
						if (!((gg >> len) & 1)){
							gg ^= (1 << len);
							tmp[to[gg]] = min(tmp[to[gg]], dp[i] + cost[len] + getFunc[pos + len + 1]);
						}
					}
				}
			}
			for (int i = 0; i < 77; i++) dp[i] = tmp[i];
			pos++;
			if (pos + w1 - 1 == n) break;
			bool need = 0;
			for (int i = 0; i < q; i++){
				int l = pos, r = pos + w2 - 1;
				if (x[i] >= l && x[i] <= r){
					need = 1;
					break;
				}
			}
			if (!need) break;
		}
		//cout << pos << endl;
		//for (int i = 0; i < w.size(); i++){
		//	cout << w[i] << ' ' << dp[i] << endl;
		//}
		if (pos + w1 - 1 == n) break;
	}
	cout << dp[to[startMask]];
}