#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int LOG = 60;

int n, dp[2][MAXN];
ll a[MAXN];

void smin(int &x, int y){x = min(x, y);}

ll aux = 0;
bool cmp(ll u, ll v){
	return (u&aux)>(v&aux);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) a[i] = a[n-1]-a[i];
	
	memset(dp, 63, sizeof(dp));
	int cur = 0;
	dp[cur][0] = 0;
	for (int w = 0; w < LOG; w++, cur = !cur){
		memset(dp[!cur], 63, sizeof(dp[!cur]));

		int c[2] = {0, 0};
		for (int i = 0; i < n; i++)
			c[a[i]>>w&1]++;
		int cOver = 0;

		for (int t = 0; t <= n; t++){
			if (dp[cur][t] <= (int)1e9) {
				smin(dp[!cur][cOver], dp[cur][t] + c[1]);
				smin(dp[!cur][cOver + c[1]], dp[cur][t] + c[0]);
			}

			if (t < n){
				if (a[t]>>w&1)
					c[1]--, c[0]++, cOver++;
				else
					c[1]++, c[0]--;
			}
		}

		aux |= 1ll<<w;
		sort(a, a + n, cmp);
	}

	cout << dp[cur][0] << "\n";
	return 0;
}