#include <bits/stdc++.h>
#define long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int solve(vector<int> &v, int l, int r, int index) {

	if (l > r) return 0;
	if (l == r || index == -1) return 1;
	
	int a = 0, b = r - l + 2;
	while (b - a > 1) {
		int m = (a+b)/2;

		int Q = v[l + m - 1];
		if (!(Q&(1LL<<index))) a = m;
		else b = m;
	}

	int F = a, S = r - l + 1 - a;

	int r1 = solve(v, l, l + F - 1, index - 1);
	int r2 = solve(v, l + F, r, index - 1);

	//cout << r1 << " " << r2 << " " << index << " " << l << " " << r << " " << F << " " << S << endl;

	return max(r1, r2) + min({r1, r2, 1});

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	sort(all(v));
	cout << n - solve(v, 0, n-1, 29);


}