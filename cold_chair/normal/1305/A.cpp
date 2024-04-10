#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 105;

int T, n, a[N], b[N];

int main() {
	for(scanf("%d", &T); T; T --)	 {
		scanf("%d", &n);
		fo(i, 1, n) scanf("%d", &a[i]);
		fo(i, 1, n) scanf("%d", &b[i]);
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		fo(i, 1, n) pp("%d ", a[i]); hh;
		fo(i, 1, n) pp("%d ", b[i]); hh;
	}
}