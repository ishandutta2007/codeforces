#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

struct jlst
{
	int adv[524288], eqv[524288];
	int max0[524288], max1[524288], mcnt[524288];
	LL sum[524288];
	void do_add(int cv, int x, int cl)
	{
		sum[cv] += 1LL * cl * x;
		adv[cv] += x;
		eqv[cv] += x;
		max0[cv] += x;
		if(max1[cv] != -1) max1[cv] += x;
	}
	void do_lmin(int cv, int x)
	{
		if(max0[cv] <= x) return;
		sum[cv] -= 1LL * mcnt[cv] * (max0[cv] - x);
		max0[cv] = x;
		eqv[cv] = x;
	}
	void pushdown(int cv, int cl)
	{
		do_add(cv << 1, adv[cv], cl);
		do_add(cv << 1 | 1, adv[cv], cl);
		do_lmin(cv << 1, eqv[cv]);
		do_lmin(cv << 1 | 1, eqv[cv]);
		adv[cv] = 0;
	}
	void pushup(int cv)
	{
		sum[cv] = sum[cv << 1] + sum[cv << 1 | 1];
		if(max0[cv << 1] == max0[cv << 1 | 1]) {
			max0[cv] = max0[cv << 1];
			mcnt[cv] = mcnt[cv << 1] + mcnt[cv << 1 | 1];
			max1[cv] = max(max1[cv << 1], max1[cv << 1 | 1]);
		} else if(max0[cv << 1] > max0[cv << 1 | 1]) {
			max0[cv] = max0[cv << 1];
			mcnt[cv] = mcnt[cv << 1];
			max1[cv] = max(max1[cv << 1], max0[cv << 1 | 1]);
		} else {
			max0[cv] = max0[cv << 1 | 1];
			mcnt[cv] = mcnt[cv << 1 | 1];
			max1[cv] = max(max0[cv << 1], max1[cv << 1 | 1]);
		}
		adv[cv] = 0;
		eqv[cv] = max0[cv];
	}
	void init()
	{
		memset(adv, 0, sizeof(adv));
		memset(eqv, 0, sizeof(eqv));
		memset(max0, 0, sizeof(max0));
		memset(max1, -1, sizeof(max1));
		for(int i = 524287; i >= 0; i --) mcnt[i] = i >= 262144 ? 1 : (mcnt[i << 1] << 1);
		memset(sum, 0, sizeof(sum));
	}
	void modify(int id, int x, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(cl == cr) {
			adv[cv] = 0;
			eqv[cv] = x;
			max0[cv] = x;
			max1[cv] = -1;
			mcnt[cv] = 1;
			sum[cv] = x;
			return;
		}
		pushdown(cv, (cr - cl + 1) / 2);
		int mid = cl + cr >> 1;
		if(id <= mid) modify(id, x, cv << 1, cl, mid);
		else modify(id, x, cv << 1 | 1, mid + 1, cr);
		pushup(cv);
	}
	void add(int l, int r, int x, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(l > r) return;
		if(l == cl && r == cr) {
			do_add(cv, x, cr - cl + 1);
			return;
		}
		pushdown(cv, (cr - cl + 1) / 2);
		int mid = cl + cr >> 1;
		if(l <= mid) add(l, min(r, mid), x, cv << 1, cl, mid);
		if(r > mid) add(max(l, mid + 1), r, x, cv << 1 | 1, mid + 1, cr);
		pushup(cv);
	}
	void getmin(int l, int r, int x, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(l > r) return;
		if(l == cl && r == cr && max1[cv] < x) {
			do_lmin(cv, x);
			return;
		}
		pushdown(cv, (cr - cl + 1) / 2);
		int mid = cl + cr >> 1;
		if(l <= mid) getmin(l, min(r, mid), x, cv << 1, cl, mid);
		if(r > mid) getmin(max(l, mid + 1), r, x, cv << 1 | 1, mid + 1, cr);
		pushup(cv);
	}
	LL query(int l, int r, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(l > r) return 0;
		if(l == cl && r == cr) return sum[cv];
		pushdown(cv, (cr - cl + 1) / 2);
		int mid = cl + cr >> 1;
		LL ret = 0;
		if(l <= mid) ret += query(l, min(r, mid), cv << 1, cl, mid);
		if(r > mid) ret += query(max(l, mid + 1), r, cv << 1 | 1, mid + 1, cr);
		return ret;
	}
}tl, tr;
int n, a[150005], pos[150005];

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) pos[a[i]] = i;
	rep1(i, n) {
		tl.modify(i, n);
		tr.modify(i, 0);
	}
	
	rep1(i, n) {
		tl.add(pos[i] + 1, n, -1);
		tr.add(pos[i] + 1, n, 1);
		int cur = tr.query(pos[i], pos[i]);
		tl.modify(pos[i], n);
		tr.modify(pos[i], i);
		tr.getmin(1, pos[i] - 1, cur);
		tl.getmin(pos[i] + 1, n, n - cur - 1);
		printf("%lld\n", tr.query(1, n) + tl.query(1, n) - 1LL * n * n);
	}
	return 0;
}