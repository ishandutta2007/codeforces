#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 3e5 + 5;

int T, a[N], n;

int main() {
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) scanf("%d", &a[i]);
		pp("%s\n", a[1] > a[n] ? "NO" : "YES");
	}
}