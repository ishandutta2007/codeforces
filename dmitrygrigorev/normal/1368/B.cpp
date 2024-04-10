#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int get(vector<int> v) {
	int k = 1;
	for (int i = 0; i < v.size(); ++i) k *= v[i];
	return k;
}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	vector<int> v(10, 1);

	int u = 0;

	while (get(v) < k) {
		v[u++]++;
		u %= 10;
	}

	string kek = "codeforces";

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < v[i]; ++j) cout << kek[i];
	}

}