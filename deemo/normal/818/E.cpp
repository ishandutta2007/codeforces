#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const int LOG = 20;

int n, k, a[MAXN], ss[LOG][MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> a[i], ss[0][i] = __gcd(a[i], k);
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			if (i+(1<<w-1) >= n)
				ss[w][i] = ss[w-1][i];
			else
				ss[w][i] = __gcd((ll)k, 1ll*ss[w-1][i]*ss[w-1][i+(1<<w-1)]);

	ll ans = 0;
	for (int i = 0; i < n; i++){
		ll cur = 1;
		int pos = i;
		for (int w = LOG-1; ~w; w--)
			if (pos+(1<<w) <= n && __gcd(cur*ss[w][pos], (ll)k) < k){
				cur = __gcd(cur*ss[w][pos], (ll)k);
				pos += 1<<w;
			}
		ans += n-pos;
	}
	cout << ans << endl;
	return 0;
}