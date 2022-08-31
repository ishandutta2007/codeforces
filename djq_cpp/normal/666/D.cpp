#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int x[4], y[4];
int retx[4], rety[4];

int absv(int c)
{
	return max(c, -c);
}

int perm[4];
void solve()
{
	rep(i, 4) scanf("%d%d", &x[i], &y[i]);
	
	int cans = INF;
	rep(i, 16) {
		map<int, int> cx, cy;
		rep(j, 4) if(i >> j & 1) cx[x[j]] ++;
		else cy[y[j]] ++;
		if(max(cx.size(), cy.size()) != 2) continue;
		int ans;
		bool fli = false;
		if(cx.size() < 2) {
			fli = true;
			swap(cx, cy);
			i ^= 15;
			rep(i, 4) swap(x[i], y[i]);
		}
		int lx = cx.begin()->first, rx = cx.rbegin()->first, dif = rx - lx;
		int ly, ry;
		if(cy.size() == 0) {
			vector<int> yu, yd;
			rep(j, 4) if(x[j] == lx) yu.push_back(y[j]);
			else yd.push_back(y[j]);
			if(yu.size() != 2) continue;
			sort(yu.begin(), yu.end());
			sort(yd.begin(), yd.end());
			yu[1] -= dif;
			yd[1] -= dif;
			rep(i, 2) yu.push_back(yd[i]);
			sort(yu.begin(), yu.end());
			ans = (yu[3] - yu[0] + 1) / 2;
			ly = yu[0] + ans;
			ry = ly + dif;
		} else if(cy.size() == 1) {
			int py = cy.begin()->first;
			vector<int> yu, yd, xs;
			rep(j, 4) if(!(i >> j & 1)) xs.push_back(x[j]);
			else if(x[j] == lx) yu.push_back(y[j]);
			else yd.push_back(y[j]);
			sort(xs.begin(), xs.end());
			sort(yu.begin(), yu.end());
			sort(yd.begin(), yd.end());
			if(xs.size() == 2) {
				ans = max(max(xs[0] - lx, lx - xs[0]), max(xs[1] - rx, rx - xs[1]));
				ans = max(ans, min(max(absv(yu[0] - py - dif), absv(yd[0] - py - dif)),
								   max(absv(yu[0] - py + dif), absv(yd[0] - py + dif))));
				ly = ans >= max(absv(yu[0] - py - dif), absv(yd[0] - py - dif)) ? py : py - dif;
				ry = ly + dif;
			} else if(yu.size() == 1) {
				ans = max(xs[0] - lx, lx - xs[0]);
				ans = max(ans, min(max(max(absv(yd[0] - py), absv(yd[1] - py - dif)), absv(yu[0] - py - dif)),
								   max(max(absv(yd[0] - py + dif), absv(yd[1] - py)), absv(yu[0] - py + dif))));
				ly = ans >= max(max(absv(yd[0] - py), absv(yd[1] - py - dif)), absv(yu[0] - py - dif)) ? py : py - dif;
				ry = ly + dif;
			} else {
				ans = max(xs[0] - rx, rx - xs[0]);
				ans = max(ans, min(max(max(absv(yu[0] - py), absv(yu[1] - py - dif)), absv(yd[0] - py - dif)),
								   max(max(absv(yu[0] - py + dif), absv(yu[1] - py)), absv(yd[0] - py + dif))));
				ly = ans >= max(max(absv(yu[0] - py), absv(yu[1] - py - dif)), absv(yd[0] - py - dif)) ? py : py - dif;
				ry = ly + dif;
			}
		} else {
			ly = cy.begin()->first;
			ry = cy.rbegin()->first;
			if(ry - ly != dif) continue;
			vector<PII> rs, cs;
			rep(j, 4) if(i >> j & 1) rs.push_back(MP(x[j], y[j]));
			else cs.push_back(MP(y[j], x[j]));
			sort(rs.begin(), rs.end());
			sort(cs.begin(), cs.end());
			ans = min(max(max(absv(rs[0].second - ly), absv(rs[1].second - ry)), max(absv(cs[0].second - rx), absv(cs[1].second - lx))),
					  max(max(absv(rs[0].second - ry), absv(rs[1].second - ly)), max(absv(cs[0].second - lx), absv(cs[1].second - rx))));
		}
		if(fli) {
			i ^= 15;
			rep(i, 4) swap(x[i], y[i]);
			swap(lx, ly);
			swap(rx, ry);
		}
		cans = min(cans, ans);
		if(cans == ans) {
			retx[0] = retx[1] = lx;
			retx[2] = retx[3] = rx;
			rety[0] = rety[2] = ly;
			rety[1] = rety[3] = ry;
		}
	}
	
	printf("%d\n", cans == INF ? -1 : cans);
	if(cans != INF) {
		rep(i, 4) perm[i] = i;
		do {
			bool ok = true;
			rep(i, 4) {
				int dx = absv(retx[perm[i]] - x[i]), dy = absv(rety[perm[i]] - y[i]);
				ok &= dx == 0 && dy <= cans || dy == 0 && dx <= cans;
			}
			if(ok) break;
		} while(next_permutation(perm, perm + 4));
		rep(i, 4) printf("%d %d\n", retx[perm[i]], rety[perm[i]]);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}