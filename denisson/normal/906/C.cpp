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

int dp[1 << 22];
pair<int, int> p[1 << 22];
vector<int> dd[1 << 22];


int ss[22];
int n, m;
int g[22][22];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;	
		g[a][b] = 1;
		g[b][a] = 1;
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (g[i][j]) ss[i] ^= (1 << j);

	for (int i = 0; i < (1 << 22); i++) dp[i] = -1;
	//for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) if ((i >> j) & 1) dd[i].pub(j);

	for (int mask = 1; mask < (1 << n); mask++){
		bool ok = 1;
		for (int i = 0; i < n; i++) if (ok && ((mask >> i) & 1)){
			int now = mask ^ (1 << i);
			if ((now & ss[i]) != now){
				ok = 0;
				break;
			}
		}
		if (ok){
			for (int i = 0; i < n; i++) if (!((mask >> i) & 1)){
				if ((mask & ss[i]) == mask){
					ok = 0;
					break;
				}
			}
			if (ok) dp[mask] = 0;
		}
	}

	for (int mask = 0; mask < (1 << n); mask++) if (dp[mask] != -1){
		for (int i = 0; i < n; i++) if ((mask >> i) & 1){
			int nowmask = mask | ss[i];
			//for (int to = 0; to < n; to++) if (!((mask >> to) & 1) && g[i][to]) nowmask ^= (1 << to);

			if (dp[nowmask] == -1 || dp[nowmask] > dp[mask] + 1){
				dp[nowmask] = dp[mask] + 1;
				p[nowmask] = mp(mask, i);
			}
		}
	}

	int mask = (1 << n) - 1;
	cout << dp[mask] << "\n";
	vector<int> ans;
	for (int it = 0; it < dp[(1 << n) - 1]; it++){
		auto now = p[mask];
		ans.pub(now.y);
		mask = now.x;
	}
	reverse(all(ans));
	for (int x : ans) cout << x + 1 << ' ';
}