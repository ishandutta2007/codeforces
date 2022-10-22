/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 3012;
int p[N], sz[N], sum[N], x[N];

int get_root(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = get_root(p[x]);
}

void merge (int x, int y) {
    x = get_root(x);
    y = get_root(y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y); 
    sz[y] += sz[x];
	sum[y] += sum[x];
    sz[x] = 0;
	sum[x] = 0;
    p[x] = y;
}

int32_t main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	vector <pair <int, pair <int, int>>> v;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
		cin >> x[i];
		sum[i] = x[i];
	}
	sort(v.begin(), v.end());
	int mx = v[0].F;
	for (int i = 0; i < (int)v.size() - 1; i++) {
		merge(v[i].S.S, v[i].S.F);
		int s = 0, mx2 = 0;
		for (int i = 1; i <= n; i++) {
			s += sum[i];
			mx2 = max(mx2, sum[i] + sz[i]);
		}
		if (mx2 > s)
			continue;
		mx = max(mx, v[i + 1].F);
	}
	cout << mx;
}