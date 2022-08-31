#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int matrix[n][n];
	for (int i=0;i<n;++i) for (int j=0; j < n; ++j) cin >> matrix[i][j];
	int p = (matrix[0][2] * matrix[1][2]) / matrix[0][1];
	int cur = 1;
	while (cur*cur < p) cur++;
	vector<int> ans(n);
	ans[2] = cur;
	for (int i=0;i<n;++i){
		if (i==2) continue;
		ans[i] = matrix[i][2] / ans[2];
	}
	for (int i=0;i<n;++i) cout << ans[i] << " ";

}