#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

int T, n;

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		if(n == 1) {
			pp("-1\n");
		} else {
			fo(i, 1, n - 1) pp("5");
			pp("4\n");
		}
	}
}