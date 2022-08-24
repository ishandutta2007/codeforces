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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}

	if (n == 1) {
		for (int i = 0; i < 3; ++i) {
			cout << "1 1\n";
			cout << -v[0] << '\n';
			v[0] = 0;
		}
	}

	else {
		cout << n << " " << n << endl;
		cout << (n - v[n-1]) << endl;
		v[n-1] = n;

		cout << 1 << " " << n << endl;
		for (int i = 0; i < n; ++i) {
			if (i+1 < n) {
				cout << -(n*v[i]) << " ";
				v[i] += (-(n*v[i])); 
			}
			else {
				cout << -v[i] << endl;
			}
		}

		cout << 1 << " " << n-1 << endl;
		for (int i = 0; i < n-1; ++i) {
			cout << -v[i] << " ";
		}

	}

}