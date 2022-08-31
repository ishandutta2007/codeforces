#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int tre[8388608], tag[8388608];

int query_t(int l, int r, int cv, int cl, int cr)
{
	if(l == cl && r == cr) return tre[cv];
	int mid = cl + cr >> 1;
	if(l > mid) return max(tag[cv], query_t(l, r, cv << 1 | 1, mid + 1, cr));
	else if(r <= mid) return max(tag[cv], query_t(l, r, cv << 1, cl, mid));
	else return max(tag[cv], min(query_t(l, mid, cv << 1, cl, mid), query_t(mid + 1, r, cv << 1 | 1, mid + 1, cr)));
}

void modify_t(int l, int r, int dat, int cv, int cl, int cr)
{
	if(l == cl && r == cr) {
		tag[cv] = max(tag[cv], dat);
		tre[cv] = max(tre[cv], dat);
		return;
	}
	int mid = cl + cr >> 1;
	if(l > mid) modify_t(l, r, dat, cv << 1 | 1, mid + 1, cr);
	else if(r <= mid) modify_t(l, r, dat, cv << 1, cl, mid);
	else {
		modify_t(l, mid, dat, cv << 1, cl, mid);
		modify_t(mid + 1, r, dat, cv << 1 | 1, mid + 1, cr);
	}
	tre[cv] = max(tag[cv], min(tre[cv << 1], tre[cv << 1 | 1]));
}

int update_t(int cl, int cr, int cdat)
{
	int ret = max(cdat - query_t(cl, cr, 1, 0, 4194303), 0);
	modify_t(cl, cr, cdat, 1, 0, 4194303);
	return ret;
}

int n, vx, vy;
int h[1005][1005];
int tim[1005][1005];
int l[1005][1005], r[1005][1005];
vector<int> vi, vt;
vector<PII> qys[1000005];

int main()
{
	scanf("%d%d%d", &n, &vx, &vy);
	rep(i, n) rep(j, n) scanf("%d", &h[i][j]);
	
	rep(i, n) rep(j, n) {
		l[i][j] = INF;
		r[i][j] = -INF;
		rep(ni, 2) rep(nj, 2) {
			int cx = -vy * (i + ni) + vx * (j + nj);
			l[i][j] = min(l[i][j], cx);
			r[i][j] = max(r[i][j], cx);
		}
		tim[i][j] = vx * i + vy * j;
		
		vi.push_back(l[i][j] * 2);
		vi.push_back(l[i][j] * 2 - 1);
		vi.push_back(r[i][j] * 2 + 1);
		vi.push_back(r[i][j] * 2);
		vt.push_back(tim[i][j]);
	}
	
	sort(vi.begin(), vi.end());
	vi.resize(unique(vi.begin(), vi.end()) - vi.begin());
	sort(vt.begin(), vt.end());
	vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
	
	rep(i, n) rep(j, n) {
		l[i][j] = lower_bound(vi.begin(), vi.end(), l[i][j] * 2) - vi.begin();
		r[i][j] = lower_bound(vi.begin(), vi.end(), r[i][j] * 2) - vi.begin();
		tim[i][j] = lower_bound(vt.begin(), vt.end(), tim[i][j]) - vt.begin();
	}
	
	rep(i, n) rep(j, n) qys[tim[i][j]].push_back(MP(i, j));
	
	LL ans = 0;
	rep(i, vt.size()) rep(j, qys[i].size()) {
		int cx = qys[i][j].first, cy = qys[i][j].second;
		ans += update_t(l[cx][cy], r[cx][cy], h[cx][cy]);
	}
	printf("%I64d\n", ans);
	return 0;
}