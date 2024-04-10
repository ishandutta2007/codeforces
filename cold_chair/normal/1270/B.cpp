#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2e5 + 5;

int T;
int n;
int a[N];
int t1[N * 4], t2[N * 4];
#define i0 i + i
#define i1 i + i + 1

void add(int i, int x, int y) {
	if(x == y) {
		t1[i] = a[x] + x;
		t2[i] = a[x] - x;
		return;
	}
	int m = x + y >> 1;
	add(i0, x, m); add(i1, m + 1, y);
	t1[i] = max(t1[i0], t1[i1]);
	t2[i] = max(t2[i0], t2[i1]);
}

int pl, pr, px, py;

void ft(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		px = max(px, t1[i]);
		py = max(py, t2[i]);
		return;
	}
	int m = x + y >> 1;
	ft(i0, x, m); ft(i1,  m + 1, y);
}

int z[N], z0, t[N];

int ye;

int main() {
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		fo(i, 1, n) scanf("%d", &a[i]);
		add(1, 1, n);
		int ans = 0;
		z0 = 0;
		fo(i, 1, n) {
			int w = 1;
			while(z0 > 0 && a[z[z0]] < a[i])
				w = z[z0] + 1, z0 --;
			z[++ z0] = i;
			px = py = -1e9;
			pl = w, pr = i;
			ft(1, 1, n);
			if(px >= a[i] + i + 1) {
				ans = 1;
				px = py = -1e9;
				fo(j, pl, pr) if(a[j] + j > py)
					px = j, py = a[j] + j;
				pp("YES\n");
				pp("%d %d\n", px, i);
				break;
			}
		}
		if(ans) continue;
		z0 = 0;
		fd(i, n, 1) {
			int w = n;
			while(z0 < 0 && a[z[z0]] <= a[i])
				w = z[z0] - 1, z0 --;
			z[++ z0] = i;
			pl = i, pr = w;
			px = py = -1e9;
			ft(1, 1, n);
			if(py >= a[i] - i + 1) {
				ans = 1;
				px = py = -1e9;
				fo(j, pl, pr) if(a[j] - j > py)
					px = j, py = a[j] - j;
				pp("YES\n");
				pp("%d %d\n", i, px);
				break;
			}
		}
		if(ans) continue;
		pp("NO\n");
	}
}