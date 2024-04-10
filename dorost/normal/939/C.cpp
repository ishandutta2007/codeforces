/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int f, s;
	cin >> f >> s;
	int x = s - f;
	for (int i = 0; i < N; i++) 
		a[i] = a[i % n];
	int mx = 0, an = 0;
	for (int i = 0; i < x; i++) 
		an += a[i];
	if (mx < an) {
		mx = an;
	}
	for (int i = x; i < N; i++) {
		an += a[i];
		an -= a[i - x];
		if (mx < an) {
			mx = an;
		}
	}
	an = 0;
	for (int i = 0; i < x; i++) 
		an += a[i];
	vector <int> v;
	if (an == mx)
		v.push_back(1);
	for (int i = x; i < n + x; i++) {
		an += a[i];
		an -= a[i - x];
		if (mx == an) {
			v.push_back(i - x + 2);
		}
	}
	int mn = 100000000;
	for (int i = 0; i < v.size(); i++)  {
		int ans = v[i];
		ans = f - ans + 1;
		if (ans <= 0)
			ans += n;
		mn = min(mn, ans);
	}
	cout << mn << endl;
}