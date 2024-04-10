#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, le[MAXN], ri[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b, a--, b--;
		if (a > b)	swap(a, b);
		ri[a]++;
		le[b]++;
	}
	int ans = 0;
	int tl = 0, tr = m;
	for (int i = 0; i < n - 1; i++){
		tr -= ri[i];
		tl += le[i];
		if (!tl && !tr)	ans++;
	}
	cout << ans << "\n";
	return 0;
}