#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1005;

int T, n, n0;
int a[N];

int b[N];

int d[N * 2], d0;

int calc() {
	fo(i, 0, n)	b[i] = 0;
	fo(i, 1, n) b[a[i]] ++;
	fo(i, 0, n) if(!b[i]) return i;
}

int main() {
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n); n0 = n;
		fo(i, 1, n)	scanf("%d", &a[i]);
		d0 = 0;
		while(1) {
			int ye = 0;
			fo(i, 1, n - 1) if(a[i] > a[i - 1]) ye = 1;
			if(!ye) break;
			while(1) {
				int x = calc();
				if(x == n) {
					a[n] = n;
					d[++ d0] = n;
					n --;
					break;
				}
				a[x + 1] = x;
				d[++ d0] = x + 1;
				break;
			}
		}
		pp("%d\n", d0);
		fo(i, 1, d0) pp("%d ", d[i]); hh;
//		fo(i, 1, n0) pp("%d ", a[i]); hh;
	}
}