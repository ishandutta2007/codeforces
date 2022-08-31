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
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	multiset <int> q;
	int add;
	ll res = 0;
	vector <int> a(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> add;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		q.insert(c[i]);
		while (!q.empty() && k < a[i]) {
			k += add;
			res += *q.begin();
			q.erase(q.begin());
		}
		if (k < a[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << res << "\n";
}