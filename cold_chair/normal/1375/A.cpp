#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main() {
//	freopen("a.in", "r", stdin);
	int T;
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n)	;
		fo(i, 1, n) {
			scanf("%d", &a[i]);
			int x = abs(a[i]);
			pp("%d ", x * (i % 2 ? -1 : 1));
		}
		hh;
	}
}