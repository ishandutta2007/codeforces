//easy two pointers: solvable
//though I make a mistake when reading the statement

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct segt
{
	LL dat[2097152], tag[2097152];
	void init()
	{
		rep(i, 2097152) dat[i] = -INF;
	}
	void add(int l, int r, LL cd, int cv = 1, int cl = 0, int cr = 1048575)
	{
		if(l == cl && r == cr) {
			tag[cv] += cd;
			dat[cv] += cd;
			return;
		}
		int mid = cl + cr >> 1;
		if(r <= mid) add(l, r, cd, cv << 1, cl, mid);
		else if(l > mid) add(l, r, cd, cv << 1 | 1, mid + 1, cr);
		else {
			add(l, mid, cd, cv << 1, cl, mid);
			add(mid + 1, r, cd, cv << 1 | 1, mid + 1, cr);
		}
		dat[cv] = max(dat[cv << 1], dat[cv << 1 | 1]) + tag[cv];
	}
	LL query(int l, int r, int cv = 1, int cl = 0, int cr = 1048575)
	{
		if(l == cl && r == cr) return dat[cv];
		int mid = cl + cr >> 1;
		LL ret =  tag[cv];
		if(r <= mid) ret += query(l, r, cv << 1, cl, mid);
		else if(l > mid) ret += query(l, r, cv << 1 | 1, mid + 1, cr);
		else ret += max(query(l, mid, cv << 1, cl, mid), query(mid + 1, r, cv << 1 | 1, mid + 1, cr));
		return ret;
	}
}tre;

int n, m, p;
PII a[200005], b[200005];
pair<PII, int> z[200005];

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	rep(i, n) scanf("%d%d", &a[i].first, &a[i].second);
	rep(i, m) scanf("%d%d", &b[i].first, &b[i].second);
	sort(a, a + n);
	sort(b, b + m);
	rep(i, p) scanf("%d%d%d", &z[i].first.first, &z[i].first.second, &z[i].second);
	sort(z, z + p);
	
	tre.init();
	rep(i, m) if(i == 0 || b[i].first != b[i - 1].first)
	tre.add(b[i].first, b[i].first, INF - b[i].second);
	int pos = 0;
	LL ans = -INF;
	rep(i, n) {
		while(pos < p && z[pos].first.first < a[i].first) {
			tre.add(z[pos].first.second + 1, 1048575, z[pos].second);
			pos ++;
		}
		ans = max(ans, tre.query(0, 1048575) - a[i].second);
	}
	printf("%lld\n", ans);
	return 0;
}