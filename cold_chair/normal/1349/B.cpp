#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;


int T, n, k, a[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &T);
	fo(ii, 1, T) {
		scanf("%d %d", &n, &k);
		int h = 0;
		fo(i, 1, n) {
			scanf("%d", &a[i]);
			if(a[i] == k) h = 1;
		}
		if(!h) {
			pp("no\n"); continue;
		}
		if(n == 1) {
			pp("yes\n");
			continue;
		}
		h = 0;
		fo(i, 1, n - 1)  if(a[i] >= k && a[i + 1] >= k)
			h = 1;
		fo(i, 1, n - 2) if(a[i] >= k && a[i + 2] >= k)
			h = 1;
		pp("%s\n", h ? "yes" : "no");
	}
}