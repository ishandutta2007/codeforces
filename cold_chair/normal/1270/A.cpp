#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 105;

int T;
int n, k1, k2;
int a[N], b[N];

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d %d %d", &n, &k1, &k2);
		int ma = 0, mb = 0;
		fo(i, 1, k1) scanf("%d", &a[i]), ma = max(ma, a[i]);
		fo(i, 1, k2) scanf("%d", &b[i]), mb = max(mb, b[i]);
		pp("%s\n", ma > mb ? "YES" : "NO");
	}
}