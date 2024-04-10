#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN], p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	p[i + 1] = p[i] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (p[i-1] <= p[n] - p[i])
			ans = i;
	cout << ans << " " << n - ans << endl;
	return 0;
}