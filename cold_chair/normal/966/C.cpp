#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 1e5 + 5;

ll a2[65];
int n; ll a[N], s, ans[N];
int son[N * 60][2], tot, siz[N * 60];

int main() {
//	freopen("c.in", "r", stdin);
//	freopen("c.out", "w", stdout);
	a2[0] = 1; fo(i, 1, 61) a2[i] = a2[i - 1] * 2;
	scanf("%d", &n);
	fo(i, 1, n) scanf("%I64d", &a[i]), s ^= a[i];
	tot = 1;
	fo(i, 1, n)	{
		int x = 1;
		fd(j, 59, 0) {
			int c = ((a[i] & a2[j]) > 0);
//			printf("%d", c);
			if(!son[x][c]) son[x][c] = ++ tot;
			x = son[x][c]; siz[x] ++;
//			printf("%d ", x);
		}
//		printf("\n");
	}
	fo(i, 1, n) {
		ll y = 0; int x;
		fo(j, 0, 59) if(s & a2[j]) {
			x = 1;
			fd(k, 59, j + 1) x = son[x][0];
			x = son[x][1]; y = a2[j];
			fd(k, j - 1, 0) {
				int c = ((s & a2[j]) > 0);
				if(siz[son[x][!c]]) {
					x = son[x][!c]; y |= (!c) * a2[k];
				} else {
					x = son[x][c]; y |= c * a2[k];
				}
			}	
			if(!siz[x]) y = 0;
			if(siz[x]) break;
		}
		if(!y) {
			printf("No"); return 0;
		}
//		printf("%I64d %I64d %I64d\n", y, s, s ^ y);
//		printf("%I64d\n", s);
		s ^= y; ans[n - i + 1] = y;
		x = 1;
		fd(j, 59, 0) {
			int c = ((y & a2[j]) > 0);
			x = son[x][c]; siz[x] --;
		}
	}
	printf("Yes\n");
	fo(i, 1, n) printf("%I64d ", ans[i]);
}