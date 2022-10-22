#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 30 + 2;

ll n, l, c[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(c, 63, sizeof(c));
	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 1; i < MAXN; i++)
		c[i] = min(c[i], c[i-1] + c[i-1]);
	ll ans = c[MAXN-1];
	ll t = 0, cur = 0;
	for (int i = MAXN-2; ~i; i--){
		if (l>>i&1){
			t += c[i];
			cur += 1ll<<i;
		}
		else{
			ans = min(ans, t + c[i]);
		}
	}
	ans = min(ans, t);
	cout << ans << "\n";
	return 0;
}