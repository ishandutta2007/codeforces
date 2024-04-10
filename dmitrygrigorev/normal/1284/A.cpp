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
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int j = 0; j < m; ++j) cin >> b[j];

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		t--;
		cout << a[t%n] << b[t%m] << "\n";
	}

}