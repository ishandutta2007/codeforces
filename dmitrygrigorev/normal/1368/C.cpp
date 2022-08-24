#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int> > ans;
	for (int i = -1; i <= 1; ++i) for (int j = -1; j <= 1; ++j) {
		if (i == 1 && j== -1) continue;
		if (i == -1 && j==1) continue;
		ans.push_back(mp(i, j));
	}

	for (int i = 0; i < n-1; ++i) {
		ans.push_back(make_pair(-i-2, -i-2));
		ans.push_back(make_pair(-i-1, -i-2));
		ans.push_back(make_pair(-i-2, -i-1));
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].x << " " << ans[i].y << "\n";
	}

}