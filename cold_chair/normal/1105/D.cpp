#include<cstdio>
#include<cstring>
#include<algorithm>
#define pp printf
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int n, m, k, v[10];
char s[1005][1005];
int d[10][1005 * 1005][2], st[10], en[10];
int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int sum, bz[1005][1005], dis[1005 * 1005];

void bfs(int c) {
	int nst = en[c]	+ 1;
	fo(i, st[c], en[c]) dis[i] = 0;
	fo(i, st[c], en[c]) {
		if(dis[i] == v[c]) break;
		int x = d[c][i][0], y = d[c][i][1];
		fo(j, 0, 3) {
			int u = x + mov[j][0], v = y + mov[j][1];
			if(u > 0 && u <= n && v > 0&& v <= m && bz[u][v] == 0) {
				dis[++ en[c]] = dis[i] + 1;
				d[c][en[c]][0] = u;
				d[c][en[c]][1] = v;
				bz[u][v] = c;
				sum ++;
			}
		}
	}
	st[c] = nst;
}

int ans[10];

int la = 0;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	fo(i, 1, k) scanf("%d", &v[i]);
	fo(i, 1, n) scanf("%s", s[i] + 1);
	fo(i, 1, n) fo(j, 1, m) {
		int c = s[i][j];
		if(c == '#') bz[i][j] = -1;
		if(c >= '1' && c <= '9') {
			c -= '0';
			d[c][++ en[c]][0] = i;
			d[c][en[c]][1] = j;
			bz[i][j] = c;
		}
	}
	int ii = 1;
	while(la < k) {
		sum = 0;
		bfs(ii);
		if(sum) la = 0; else la ++;
		ii = ii % k + 1;
	}
	fo(i, 1, n) fo(j, 1, m)
		if(bz[i][j] > 0) ans[bz[i][j]] ++;
	fo(i, 1, k) pp("%d ", ans[i]);
}