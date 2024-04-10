#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, k, p, a[MAXN], sec[MAXN], vec[MAXN], s1, s2, gec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> p;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < k; i++){
		int x;	cin >> x;
		if (x >= p)
			sec[s1++] = x;
		else
			vec[s2++] = x;
	}
	sort(a, a + n);
	sort(sec, sec + s1);
	sort(vec, vec + s2);
	reverse(vec, vec + s2);
	ll ans = 1e18;
	for (int t = 0; t <= min(n, s2); t++){
		if (t + s1 < n) continue;
		int sz = 0;
		for (int i = 0; i < t; i++) gec[sz++] = vec[i];
		for (int i = 0; i < n-t; i++) gec[sz++] = sec[i];
		sort(gec, gec + sz);
		ll ret = 0;
		for (int i = 0; i < n; i++)
			ret = max(ret, (ll)abs(a[i]-gec[i]) + abs(gec[i]-p));
		ans = min(ans, ret);
	}
	cout << ans << "\n";
	return 0;
}