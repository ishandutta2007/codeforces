#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 50 + 3;
const int LOG = 60;

int n, k;
ll a[MAXN], pt[MAXN];
bool d[MAXN][MAXN];

bool ok(ll ans){
	memset(d, 0, sizeof(d));
	d[0][0] = true;
	for (int i = 1; i <= n; i++)
		for (int t = 1; t <= i; t++)
			for (int c = 1; c <= i; c++){
				ll sm = pt[i] - pt[i-c];
				if ((sm&ans) == ans)
					d[i][t] |= d[i-c][t-1];
			}
	return d[n][k];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i], pt[i+1] = pt[i] + a[i];

	ll ans = 0;
	for (int i = LOG-1; ~i; i--){
		ans ^= 1ll<<i;
		if (ok(ans)) continue;
		ans ^= 1ll<<i;
	}
	cout << ans << "\n";
	return 0;
}