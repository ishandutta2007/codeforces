#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXM = 10;
const int MAXN = 1e5 + 10;

int n, m, a[MAXM][MAXN], pos[MAXM][MAXN], dp[MAXN];

int get(int val){
	if (dp[val]) return dp[val];
	dp[val] = 1;
	if (pos[0][val] < n-1){
		int nxt = a[0][pos[0][val]+1];
		for (int i = 0; i < m; i++)
			if (pos[i][val]+1 != pos[i][nxt]) return dp[val];
		dp[val] += get(nxt);
	}
	return dp[val];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j], a[i][j]--, pos[i][a[i][j]] = j;

	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += get(i);
	cout << ans << "\n";
	return 0;
}