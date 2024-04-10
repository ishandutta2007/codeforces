#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a, a + 2*n);
	
	ll ans = 1ll*(a[n-1]-a[0])*(a[2*n-1]-a[n]);
	int mn = 1e9;
	for (int i = 1; i + n - 1 < 2*n-1; i++)
		mn = min(mn, a[i+n-1] - a[i]);
	ans = min(ans, 1ll*mn*(a[2*n-1]-a[0]));
	cout << ans << "\n";
	return 0;
}