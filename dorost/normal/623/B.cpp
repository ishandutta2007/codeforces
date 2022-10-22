/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 1012345, INF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
int a[N], b[N];
int n, ox, y;

vector <int> f(int x) {
	vector <int> v;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			v.push_back(i);
			while (x % i == 0)
				x /= i;
		}
	}
	if (x != 1)
		v.push_back(x);
	return v;
}

int ans(int x) {
	__int128_t wef = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % x == 0)
			b[i] = 0;
		else if ((a[i] % x == 1) || (a[i] % x == (x - 1)))
			b[i] = -y, wef += y;
		else
			b[i] = -INF, wef += INF;
		b[i] += ox;
	}
	__int128_t mx = 0, ps = 0;
	__int128_t mn = 0;
	for (int i = 0; i < n; i++) {
		ps += b[i];
		mx = max(mx, ps);
		mn = min(mn, ps - mx);
	}
	return (int)(wef + mn);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> ox >> y;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> v1 = f(a[0] - 1);
	vector <int> v2 = f(a[0]);
	vector <int> v3 = f(a[0] + 1);
	vector <int> v4 = f(a[n - 1] - 1);
	vector <int> v5 = f(a[n - 1]);
	vector <int> v6 = f(a[n - 1] + 1);
	set <int> st;
	for (int i : v1) 
		st.insert(i);
	for (int i : v2) 
		st.insert(i);
	for (int i : v3) 
		st.insert(i);
	for (int i : v4) 
		st.insert(i);
	for (int i : v5) 
		st.insert(i);
	for (int i : v6) 
		st.insert(i);
	int mn = INF;
	for (int i : st) {
		mn = min(mn, ans(i));
	}
	cout << mn << endl;
}