#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n;
ll w[MAXN], d[2][MAXN];
string s[MAXN], t[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> w[i];
	memset(d, 63, sizeof(d));
	for (int i = 0; i < n; i++)
		cin >> s[i], t[i] = s[i], reverse(t[i].begin(), t[i].end());
	d[0][1] = 0;
	d[1][1] = w[0];
	for (int i = 1; i < n; i++){
		if (s[i] >= s[i - 1])
			d[0][i + 1] = min(d[0][i + 1], d[0][i]);
		if (s[i] >= t[i - 1])
			d[0][i + 1] = min(d[0][i + 1], d[1][i]);
		if (t[i] >= s[i - 1])
			d[1][i + 1] = min(d[1][i + 1], d[0][i] + w[i]);
		if (t[i] >= t[i - 1])
			d[1][i + 1] = min(d[1][i + 1], d[1][i] + w[i]);
	}

	ll ans = min(d[0][n], d[1][n]);
	if (ans > 1e16)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}