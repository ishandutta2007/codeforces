#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
typedef long long ll;
using namespace std;
const int N = 200005;
int n, m, ans[N], l[N], r[N], res[N], sum[N], t[N];
char s[N];
int main() {
	cin.tie(0);
	cin >> n >> m >> s + 1;
	for (int i = 0; i < m; i++) 
		cin >> l[i] >> r[i], res[i] = n;
	vector<int> ord(3);
	iota(ord.begin(), ord.end(), 0);
	do {
		t[1] = ord[0];
		t[2] = ord[1];
		t[3] = ord[2];
		for (int i = 4; i <= n; i++) 
			t[i] = t[i - 3];	
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + (s[i] - 'a' != t[i]);
		for (int i = 0; i < m; i++)
			res[i] = min(res[i], sum[r[i]] - sum[l[i] - 1]);
	} while (next_permutation(ord.begin(), ord.end()));
	for (int i = 0; i < m; i++)
		cout << res[i] << "\n";
	return 0;
}