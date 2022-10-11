#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>x[100000], G[100000]; int n, a[100000], col[100000], cnt, p[2001][1000]; long long ret = 1, ret2 = 0;
long long gcd(long long r, long long s) {
	if (s == 0)return r;
	return gcd(s, r%s);
}
void dfs(int pos) {
	if (col[pos] >= 1)return;
	col[pos] = cnt; G[cnt].push_back(pos);
	for (int i = 0; i < x[pos].size(); i++)dfs(x[pos][i]);
}
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i]; a[i]--; x[i].push_back(a[i]); x[a[i]].push_back(i); }
	for (int i = 0; i < n; i++) { if (col[i] >= 1)continue; cnt++; dfs(i); }
	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j <= 2000; j++) { for (int k = 0; k < 1000; k++)p[j][k] = 0; }
		for (int j : G[i])p[0][j] = j;
		for (int j = 0; j < 2000; j++) {
			for (int k : G[i]) {
				p[j + 1][k] = a[p[j][k]];
			}
		}
		long long cnt2 = 0, cnt3 = 0;
		for (int j = 1; j <= 1000; j++) {
			bool OK = true; for (int k = 0; k < n; k++) { if (p[j][k] != p[2 * j][k])OK = false; }
			if (OK == true) {
				if (cnt2 == 0)cnt2 = j;
				else { cnt3 = j; break; }
			}
		}
		ret = ret / gcd(ret, cnt3 - cnt2)*(cnt3 - cnt2);
		ret2 = max(ret2, cnt2);
	}
	long long B = ret;
	while (ret2 > B)B += ret;
	cout << B << endl;
	return 0;
}