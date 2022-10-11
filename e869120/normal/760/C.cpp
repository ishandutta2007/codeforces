#include<iostream>
#include<vector>
using namespace std;
int n, a[250000], b[250000]; vector<int>x[250000]; bool used[250000];
void dfs(int p) { if (used[p] == true)return; used[p] = true; for (int i : x[p])dfs(i); }
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i]; x[a[i]].push_back(i); x[i].push_back(a[i]); }
	int s = 0; for (int i = 1; i <= n; i++) { cin >> b[i]; s += b[i]; }
	int r = 0; for (int i = 1; i <= n; i++) { if (used[i] == true)continue; r++; dfs(i); }if (r == 1)r = 0;
	cout << r + (s + 1) % 2 << endl;
	return 0;
}