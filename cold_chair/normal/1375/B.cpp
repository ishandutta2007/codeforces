#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 305;

int n, m;
int a[N][N], b[N][N];

int mov[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
//	freopen("a.in", "r", stdin);
	int T;
	for(scanf("%d", &T); T; T --) {
		scanf("%d", &n);
		scanf("%d", &m);
		fo(i, 1, n) {
			fo(j, 1, m) scanf("%d", &a[i][j]);
		}
		int ye = 1;
		fo(i, 1, n) {
			fo(j, 1, m) {
				int s = 0;
				fo(k, 0, 3) {
					int x = i + mov[k][0], y = j + mov[k][1];
					if(x >= 1 && x <= n && y >= 1 && y <= m) {
						s ++;
					}
				}
				b[i][j] = s;
				if(a[i][j] > b[i][j]) ye = 0;
			}
		}
		if(ye) {
			pp("YES\n");
			fo(i, 1, n) {
				fo(j, 1, m) pp("%d ", b[i][j]);
				hh;
			}
		} else {
			pp("NO\n");
		}
	}
}