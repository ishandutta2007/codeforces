#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int C(int n, int k) {
	int ans = 1;
	for (int i = 0; i < k; ++i) ans *= (n-i);
	for (int i = 1; i <= k; ++i) ans /= i;
	return ans;
}

int vp (pair<int, int> &a, pair<int, int> &b) {
	return (a.first*b.second - a.second * b.first);
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second > 0 && b.second < 0) return true;
	if (a.second > 0 && b.second == 0) {
		if (b.first > 0) return false;
		return true;
	}

	if (a.second == 0 && b.second > 0) {
		if (a.first > 0) return true;
		return false;
	}

	if (a.second == 0 && b.second < 0) {
		return true;
	}

	if (a.second < 0 && b.second >= 0) return false;

	return (vp(a, b) > 0);

}

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	int ans = n * C(n-1, 4);

	cout.precision(15);

	for (int i = 0; i < n; ++i) {
		vector<pair<int, int> > d;
		for (int j = 0; j < n; ++j) {
			if (j==i) continue;
			d.push_back({v[j].first - v[i].first, v[j].second - v[i].second});
		}
		
		sort(d.begin(), d.end(), cmp);

	//	for (int j = 0; j < n-1; ++j) cout << d[j].first << " " << d[j].second << " == ";
	//	cout << endl;

	//cout << vp(d[0], d[4]) << endl;


		for (int j = 0; j < n-1; ++j) {
			int L = 1, R = n;
			while (R-L>1){
				int M = (L+R)/2;
				pair<int, int> A = d[j];
				pair<int, int> B = d[(j+M-1)%(n-1)];
				//if (i==3 && j==2) cout << fixed << B << " " << A << " " << PI << endl;
				if (vp(A, B) > 0) L = M;
				else R = M;
			}
			//if (i==2 && j==0) cout << L << endl; 
			ans -= C(L-1, 3);
		}
	}

	cout << ans;



}