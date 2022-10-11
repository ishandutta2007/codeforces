#include<iostream>
#include<algorithm>
using namespace std;
long long a[220000], b[220000], c[220000], f[220000], n, m, s[220000], t[220000];
pair<long long, long long>d[220000], e[220000];
bool used[220000], used2[220000];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { cin >> a[i]; d[i] = make_pair(a[i], i); }sort(d + 1, d + n + 1);
	for (int i = 1; i <= m; i++) { cin >> b[i]; e[i] = make_pair(b[i], i); }sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) { a[i] = d[i].first; c[i] = d[i].second; }
	for (int i = 1; i <= m; i++) { b[i] = e[i].first; f[i] = e[i].second; }
	int c1 = 0, c2 = 0;
	for (int i = 0; i < 32; i++) {
		int L = 1;
		for (int j = 1; j <= m; j++) {
			if (used2[j] == true)continue;
			while (L <= n && (used[L] == true || a[L] < b[j]))L++;
			if (L > n)break;
			if (a[L] == b[j]) { t[f[j]] = i; s[c[L]] = f[j]; used[L] = true; used2[j] = true; c1++; c2 += i; L++; }
		}
		for (int j = 1; j <= m; j++)b[j] = (b[j] + 1) / 2;
	}
	cout << c1 << ' ' << c2 << endl;
	for (int i = 1; i <= m; i++) { if (i >= 2)cout << ' '; cout << t[i]; } cout << endl;
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << s[i]; } cout << endl;
	return 0;
}