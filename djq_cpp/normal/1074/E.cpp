#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, m, dat[25][25], cnt;
bool rx, ry, tr;
vector<int> V[30005];
void rotate_m(vector<PII> cur)
{
	if(rx) rep(i, cur.size()) cur[i].first = n + 1 - cur[i].first;
	if(ry) rep(i, cur.size()) cur[i].second = m + 1 - cur[i].second;
	if(tr) rep(i, cur.size()) swap(cur[i].first, cur[i].second);
	
	rep(i, cur.size()) V[cnt].push_back(dat[cur[i].first][cur[i].second]);
	rep(i, cur.size()) if(i != 0) swap(dat[cur[0].first][cur[0].second], dat[cur[i].first][cur[i].second]);
	cnt ++;
}
void swap_h(int x, int ly)
{
	rx = ry = false;
	if(x == n) {
		rx = true; x = n + 1 - x;
	}
	if(ly == m - 1) {
		ry = true; ly = m - ly;
	}
	rotate_m({MP(x, ly), MP(x, ly + 1), MP(x, ly + 2), MP(x + 1, ly + 2), MP(x + 1, ly + 1), MP(x + 1, ly)});
	rotate_m({MP(x, ly + 1), MP(x + 1, ly + 1), MP(x + 1, ly + 2), MP(x, ly + 2)});
	rotate_m({MP(x + 1, ly + 1), MP(x, ly + 1), MP(x, ly), MP(x + 1, ly)});
	rx = ry = false;
}
void swap_v(int lx, int y)
{
	tr = true; swap(n, m);
	swap_h(y, lx);
	tr = false; swap(n, m);
}
 
int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) rep1(j, m) scanf("%d", &dat[i][j]);
	
	int tot = 0;
	rep1(i, n) rep1(j, m) {
		int cur = ++ tot, x, y;
		rep1(k, n) rep1(l, m) if(dat[k][l] == cur) {
			x = k; y = l;
		}
		while(y < j) {
			if(x < n && x > i) {
				rotate_m({MP(x, y), MP(x, y + 1), MP(x + 1, y + 1), MP(x + 1, y)}); y ++; continue;
			} else if(x > i + 1) {
				rotate_m({MP(x, y), MP(x, y + 1), MP(x - 1, y + 1), MP(x - 1, y)}); y ++; continue;
			}
			swap_h(x, y); y ++;
		}
		while(y > j) {
			if(x < n && x > i) {
				rotate_m({MP(x, y), MP(x, y - 1), MP(x + 1, y - 1), MP(x + 1, y)}); y --; continue;
			} else if(x > i + 1) {
				rotate_m({MP(x, y), MP(x, y - 1), MP(x - 1, y - 1), MP(x - 1, y)}); y --; continue;
			}
			swap_h(x, y - 1); y --;
		}
		while(x > i) {
			if(x > i + 1) {
				if(y == m) rotate_m({MP(x, y), MP(x - 1, y), MP(x - 1, y - 1), MP(x, y - 1)});
				else rotate_m({MP(x, y), MP(x - 1, y), MP(x - 1, y + 1), MP(x, y + 1)}); x --; continue;
			}
			swap_v(x - 1, y); x --;
		}
	}
	
	printf("%d\n", cnt);
	rep(i, cnt) {
		printf("%d", V[i].size());
		rep(j, V[i].size()) printf(" %d", V[i][j]); printf("\n");
	}
	return 0;
}