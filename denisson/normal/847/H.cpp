#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n;
ll a[100007];
pair<ll, ll> dp1[100007];
pair<ll, ll> dp2[200007];

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp1[0] = mp(0, 0);
	dp2[n + 1] = mp(0, 0);
	for (int i = 1; i <= n; i++){
		ll add = max(dp1[i - 1].y + 1 - a[i], (ll)0);
		dp1[i] = mp(dp1[i - 1].x + add, max(dp1[i - 1].y + 1, a[i]));
	}
	for (int i = n; i >= 1; i--){
		ll add = max(dp2[i + 1].y + 1 - a[i], (ll)0);
		dp2[i] = mp(dp2[i + 1].x + add, max(dp2[i + 1].y + 1, a[i]));
	}

	ll ans = (ll)1e18 + 7;
	for (int i = 0; i <= n; i++){
		ll now = dp1[i].x + dp2[i + 1].x;
		ll val1 = dp1[i].y;
		ll val2 = dp2[i + 1].y;
		if (val1 == val2) now++;
		ans = min(ans, now);
	}
	cout << ans;
}