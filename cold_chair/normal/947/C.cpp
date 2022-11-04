#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 3e5 + 5;

int n, a[N], b[N], a2[31];
int son[N * 30][2], siz[N * 30], tot;

int main() {
//	freopen("c.in", "r", stdin);
	a2[0] = 1; fo(i, 1, 30) a2[i] = a2[i - 1] * 2;
	scanf("%d", &n);
	fo(i, 1, n)
		scanf("%d", &a[i]);
	tot = 1;
	fo(i, 1, n) {
		scanf("%d", &b[i]);
		int x = 1;
		fd(j, 29, 0) {
			int c = ((b[i] & a2[j]) > 0);
			if(!son[x][c]) son[x][c] = ++ tot;
			x = son[x][c]; siz[x] ++;
		}
	}
	fo(i, 1, n) {
		int x = 1, y = 0;
		fd(j, 29, 0) {
			int c = ((a[i] & a2[j]) > 0);
			if(siz[son[x][c]]) {
				x = son[x][c];
				y += c * a2[j];
			} else {
				x = son[x][!c];
				y += (!c) * a2[j];
			}
		}
		printf("%d ", a[i] ^ y);
		x = 1;
		fd(j, 29, 0) {
			int c = ((y & a2[j]) > 0);
			x = son[x][c]; siz[x] --;
		}
	}
}