#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
#define MUL(i, j) tre[id][i][j] = max(max(tre[id << 1][i][0] + tre[id << 1 | 1][0][j], \
			tre[id << 1][i][1] + tre[id << 1 | 1][1][j]), \
			tre[id << 1][i][2] + tre[id << 1 | 1][2][j]);
#define TL(i) tmp[i] = max(max(tl[0] + tre[l][0][i], tl[1] + tre[l][1][i]), tl[2] + tre[l][2][i]);
#define TR(i) tmp[i] = max(max(tr[0] + tre[r][i][0], tr[1] + tre[r][i][1]), tr[2] + tre[r][i][2]);
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const double INF = 1e18;

int n, q, x, y, a[200005];
double fx, fy;

struct segt
{
	double tre[524288][3][3];
	segt()
	{
		rep1(i, 524287) rep(j, 3) rep(k, 3) tre[i][j][k] = -INF;
	}
	void sett(int pos)
	{
		int id = pos | 262144;
		tre[id][0][0] = 0;
		tre[id][0][2] = a[pos] * fx;
		tre[id][2][0] = 0;
		tre[id][0][1] = tre[id][1][1] = a[pos] * fy;
		tre[id][1][0] = 0;
	}
	void modify(int id)
	{
		id |= 262144;
		for(id >>= 1; id >= 1; id >>= 1) {
			MUL(0, 0); MUL(0, 1); MUL(0, 2);
			MUL(1, 0); MUL(1, 1); MUL(1, 2);
			MUL(2, 0); MUL(2, 1); MUL(2, 2);
		}
	}
	void build()
	{
		for(int id = 262143; id >= 1; id --) {
			MUL(0, 0); MUL(0, 1); MUL(0, 2);
			MUL(1, 0); MUL(1, 1); MUL(1, 2);
			MUL(2, 0); MUL(2, 1); MUL(2, 2);
		}
	}
	double query(int l, int r)
	{
		double tl[3] = {0, -INF, -INF}, tr[3] = {}, tmp[3] = {};
		for(l |= 262144, r |= 262144; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				TL(0); TL(1); TL(2);
				tl[0] = tmp[0]; tl[1] = tmp[1]; tl[2] = tmp[2];
				l ++;
			}
			if(!(r & 1)) {
				TR(0); TR(1); TR(2);
				tr[0] = tmp[0]; tr[1] = tmp[1]; tr[2] = tmp[2];
				r --;
			}
		}
		if(l == r) {
			TL(0); TL(1); TL(2);
			tl[0] = tmp[0]; tl[1] = tmp[1]; tl[2] = tmp[2];
		}
		return max(max(tl[0] + tr[0], tl[1] + tr[1]), tl[2] + tr[2]);
	}
}t;

int main()
{
	scanf("%d%d%d%d", &n, &q, &x, &y);
	if(x < y) swap(x, y);
	fx = 1.0 / x; fy = 1.0 / (x + y);
	
	rep(i, n) {
		scanf("%d", &a[i]);
		t.sett(i);
	}
	t.build();
	rep(i, q) {
		int tp, u, v;
		scanf("%d%d%d", &tp, &u, &v);
		if(tp == 1) {
			u --; a[u] = v;
			t.sett(u); t.modify(u);
		} else {
			u --; v --;
			printf("%.10lf\n", t.query(u, v));
		}
	}
	return 0;
}