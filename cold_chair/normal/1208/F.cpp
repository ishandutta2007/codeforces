#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define ff(i, x, y) for(int i = x; i <  y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define pp printf
#define ll long long
using namespace std;

const int N = 1e6 + 10;

int n, a[N];
	
const int M = 1 << 21;

int f[M], g[M];

void add(int x, int i) {
	if(x > f[i]) {
		g[i] = f[i];
		f[i] = x;
	} else 
	if(x > g[i]){
		g[i] = x;
	}
}

const int inf = 1e9;

int main() {
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	fo(i, 0, 20) {
		ff(j, 0, 1 << 21) {
			if(!(j >> i & 1))	{
				add(f[j + (1 << i)], j);
				add(g[j + (1 << i)], j);
			}
		}
	}
	ff(j, 0, 1 << 21) {
		if(f[j] != g[j]) {
			f[j] = g[j];
		} else {
			f[j] = 0;
		}
	}
	int ans = 0;
	fo(i, 1, n - 2) {
		int x = 0;
		fd(j, 20, 0) {
			if(!(a[i] >> j & 1)) {
				x += 1 << j;
				if(g[x] <= i) {
					x -= 1 << j;
				}
			}
		}
		ans = max(ans, x | a[i]);
	}
	pp("%d", ans);
}