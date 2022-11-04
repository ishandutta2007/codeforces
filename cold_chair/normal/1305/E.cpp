#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 5005;

const int inf = 1e9;

int n, m;
int a[N];

int main() {
	scanf("%d %d", &n, &m);
	int s = 0;
	fo(i, 1, n)	s += (i - 1) / 2;
	if(m > s) {
		pp("-1\n"); return 0;
	}
	fo(i, 1, n) a[i] = i;
	fd(i, n, 1) {
		int x = (i - 1) / 2;
		if(s - m >= x) {
			a[i] = inf - (n - i) * 10000;
			s -= x;
		} else {
			for(int j = i; j <= inf; j ++) {
				int c = 0;
				fo(k, 1, i - 1) {
					if(j - k > k && j - k < i)
						c ++;
				}
				if(c == m - (s - x)) {
					a[i] = j; break;
				}
			}
			break;
		}
	}
	fo(i, 1, n) pp("%d ", a[i]); hh;
}