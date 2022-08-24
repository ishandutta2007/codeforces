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

	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	while (true) {
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0;i<n;++i) {
			if (v[i].first % 2 == 0 && v[i].second % 2 == 0) {
				a++;
			}
			if (v[i].first % 2 != 0 && v[i].second % 2 != 0) {
				b++;
			}
			if (v[i].first % 2 != 0 && v[i].second % 2 == 0) {
				c++;
			}
			if (v[i].first % 2 == 0 && v[i].second % 2 != 0) {
				d++;
			}
		}
		if (a+b > 0 && c+d > 0) {
			cout << a+b << endl;
			for (int i=0;i<n;++i) {
				if (v[i].first % 2 == 0 && v[i].second % 2 == 0) {
					cout << i+1 << " ";
				}
				if (v[i].first % 2 != 0 && v[i].second % 2 != 0) {
					cout << i+1 << " ";
				}
			}
			exit(0);
		}
		if (c+d > 0) {
			for (int i=0;i<n;++i) {
				v[i].first++;
			}
			swap(a, c);
			swap(b, d);
		}
		if (a > 0 && b > 0) {
			cout << a << endl;
			for (int i=0;i<n;++i) {
				if (v[i].first % 2 == 0 && v[i].second % 2 == 0) {
					cout << i+1 << " ";
				}
			}
			exit(0);
		}
		if (b > 0) {
			for (int i=0;i<n;++i) {
				v[i].first++, v[i].second++;
			}
		}
		for (int i=0;i<n;++i) {
			v[i].first/=2, v[i].second /= 2;
		}
	}

}