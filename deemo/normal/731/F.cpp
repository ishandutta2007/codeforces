#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n, a[MAXN], cnt[MAXN], p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++;

	for (int i = 1; i < MAXN; i++)
		p[i] = p[i - 1] + cnt[i];

	ll ans = 0;
	for (int i = 1; i < MAXN; i++)
		if (cnt[i]){
			ll ret = 0;
			for (int j = i; j < MAXN; j += i){
				int temp = min(MAXN, j + i);
				ret += 1ll * (p[temp-1] - p[j-1]) * j;
			}
			ans = max(ans, ret);
		}

	cout << ans << "\n";
	return 0;
}