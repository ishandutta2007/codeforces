#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

struct st{
	int a, b, cost, day;

	bool operator< (st nxt) const { return day < nxt.day; }
};

int n, m, k;
st a[100007];
ll dp[100007];
ll dp2[100007];
int last[100007];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) cin >> a[i].day >> a[i].a >> a[i].b >> a[i].cost;
	sort(a, a + m);
	
	for (int i = 1; i <= n; i++) last[i] = -1;
	int cnt = 0;
	ll sum = 0;

	for (int i = 0; i < m; i++){
		if (a[i].a != 0){
			if (last[a[i].a] == -1){
				cnt++;
				sum += a[i].cost;
				last[a[i].a] = a[i].cost;
			}
			if (a[i].cost < last[a[i].a]){
				sum -= last[a[i].a];
				last[a[i].a] = a[i].cost;
				sum += last[a[i].a];
			}
		}
		if (cnt < n) dp[i] = -1;
		else dp[i] = sum;
	}

	for (int i = 1; i <= n; i++) last[i] = -1;
	cnt = 0;
	sum = 0;

	for (int i = m - 1; i >= 0; i--){
		if (a[i].b != 0){
			if (last[a[i].b] == -1){
				cnt++;
				sum += a[i].cost;
				last[a[i].b] = a[i].cost;
			}
			if (a[i].cost < last[a[i].b]){
				sum -= last[a[i].b];
				last[a[i].b] = a[i].cost;
				sum += last[a[i].b];
			}
		}
		if (cnt < n) dp2[i] = -1;
		else dp2[i] = sum;
	}
	ll ans = -1;
	int uk = 0;


	for (int i = 0; i < m; i++) if (dp[i] != -1){
		ll now = dp[i];

		while(uk < m && a[i].day + k + 1 > a[uk].day) uk++;
		if (uk == m) break;
		if (dp2[uk] == -1) break;

		now += dp2[uk];


		if (ans == -1) ans = now; else ans = min(ans, now);
	}

	cout << ans;
}