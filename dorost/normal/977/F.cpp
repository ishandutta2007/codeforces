/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], b[N], c[N], n;
vector <int> v[N];
map <int, int> w;
bool f[N], f2[N];

void comp() {
	sort(c, c + n);
	int x = 1;
	b[0] = x;
	for (int i = 1; i < n; i++) {
		if (c[i] != c[i - 1]) {
			x++;
		}
		b[i] = x;
	}
	for (int i = 0; i < n; i++) {
		w[c[i]] = b[i];
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[i] = a[i];
	}
	comp();
	for (int i = 0; i < n; i++) {
		v[w[a[i]]].push_back(i);
	}
	int mx = 0;
	vector <int> va;
	for (int i = 0; i < n; i++) {
		if (f[i] || f2[w[a[i]]])
			continue;
		f[i] = true;
		f2[w[a[i]]] = true;
		vector <int> vv;
		int ans = 1, lx = i;
		vv.push_back(i + 1);
		for (int j = a[i] + 1;; j++) {
			if (w[j] == 0) {
				break;
			}
			int x = w[j];
			int in = upper_bound(v[x].begin(), v[x].end(), lx) - v[x].begin();
			if (in == v[x].size()) {
				break;
			}
			lx = v[x][in];
			vv.push_back(v[x][in] + 1);
			f[v[x][in]] = true;
			ans++;
		}
		if (ans > mx) {
			mx = ans;
			va = vv;
		}
	}
	cout << mx << '\n';
	for (int i = 0; i < mx; i++) 
		cout << va[i] << ' ';
}