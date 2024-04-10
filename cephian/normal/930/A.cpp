#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
vector<int> child[N];
bool depth[N] = {};

void dfs(int v, int d) {
	depth[d] ^= 1;
	for(int c : child[v])
		dfs(c, d+1);
}

int main() {
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		child[p].push_back(i);
	}
	dfs(1, 0);
	int ans = 0;
	for(int d = 0; d < n; ++d)
		ans += depth[d];
	cout << ans << "\n";
}