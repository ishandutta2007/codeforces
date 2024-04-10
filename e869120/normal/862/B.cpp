#include<iostream>
#include<vector>
using namespace std;
long long n, col[100009], a, b, P; vector<int>x[100009];
void dfs(int pos, int depth) {
	if (col[pos] >= 0)return;
	col[pos] = depth; if (depth == 0)P++;
	for (int i = 0; i < x[pos].size(); i++) {
		dfs(x[pos][i], depth ^ 1);
	}
}
int main() {
	cin >> n; for (int i = 1; i <= n; i++)col[i] = -1;
	for (int i = 1; i < n; i++) { cin >> a >> b; x[a].push_back(b); x[b].push_back(a); }
	dfs(1, 0);
	cout << 1LL * P*(n - P) - (n - 1) << endl;
	return 0;
}