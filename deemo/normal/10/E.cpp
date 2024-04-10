#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 400 + 5;

int n, a[MAXN];

int main(){
	cin >> n;	for (int i = 0; i < n; i++)	cin >> a[i];
	ll ans = 1e18;
	for (int i = 1; i < n; i++)
		for (int j = i; j < n; j++){
			int x = a[i - 1] - 1, cnt = 1;
			ll tt = a[j];
			for (int w = 0; x && w <= j; w++){
				tt += x/a[w]*a[w];
				cnt += x/a[w];
				x %= a[w];
			}
			x = tt;
			int cnt2 = 0;
			for (int w = 0; x && w < n; w++)
				cnt2 += x/a[w], x %= a[w];
			if (cnt < cnt2)
				ans = min(ans, tt);
		}

	if (ans > 1e17)
		ans = -1;
	cout << ans << endl;
	return 0;
}