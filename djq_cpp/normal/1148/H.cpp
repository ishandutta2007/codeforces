//hao kun a
//bu hui xie dai ma le
///gen ben lai bu ji
//zhi neng da bao li le
//jia xun
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

struct segt
{
	PII dat[524288];
	segt()
	{
		rep(i, 262144) dat[262144 | i] = MP(0, i);
		for(int i = 262143; i >= 1; i --) dat[i] = min(dat[i << 1], dat[i << 1 | 1]);
	}
	void modify(int id, int val, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(cl == cr) {
			dat[cv] = MP(val, id); return;
		}
		int mid = (cl + cr) >> 1;
		if(id <= mid) modify(id, val, cv << 1, cl, mid);
		else modify(id, val, cv << 1 | 1, mid + 1, cr);
		dat[cv] = min(dat[cv << 1], dat[cv << 1 | 1]);
	}
	PII query(int id, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(id < cl) return MP(INF, -1);
		if(id >= cr) return dat[cv];
		int mid = (cl + cr) >> 1;
		return min(query(id, cv << 1, cl, mid), query(id, cv << 1 | 1, mid + 1, cr));
	}
	PII findf(int val, int cv = 1, int cl = 0, int cr = 262143)
	{
		if(dat[cv].first >= val) return MP(INF, -1);
		if(cl == cr) return dat[cv];
		int mid = (cl + cr) >> 1;
		PII ret = findf(val, cv << 1, cl, mid);
		if(ret.second == -1) ret = findf(val, cv << 1 | 1, mid + 1, cr);
		return ret;
	}
}rmq;

struct tnode
{
	tnode* ls,* rs;
	LL tag0, tag1, s0, s1;
	tnode()
	{
		ls = rs = NULL; tag0 = tag1 = s0 = s1 = 0;
	}
};

tnode* modify(tnode* cur, int l, int r, LL c0, LL c1, int cl = 0, int cr = 262143)
{
	if(r < cl || l > cr) return cur;
	tnode* ret = new tnode();
	if(cur != NULL) *ret = *cur;
	if(l <= cl && r >= cr) {
		ret->tag0 += c0; ret->tag1 += c1;
		ret->s0 += (cr - cl + 1) * c0; ret->s1 += (cr - cl + 1) * c1;
	} else {
		int mid = (cl + cr) >> 1;
		ret->ls = modify(ret->ls, l, r, c0, c1, cl, mid);
		ret->rs = modify(ret->rs, l, r, c0, c1, mid + 1, cr);
		ret->s0 += (min(cr, r) - max(cl, l) + 1) * c0;
		ret->s1 += (min(cr, r) - max(cl, l) + 1) * c1;
	}
	return ret;
}
LL query(tnode* cur, int l, int r, LL c0, LL c1, int cl = 0, int cr = 262143)
{
	if(r < cl || l > cr || cur == NULL) return 0;
	if(l <= cl && r >= cr) return cur->s0 * c0 + cur->s1 * c1;
	int mid = (cl + cr) >> 1;
	LL ret = cur->tag0 * c0 * (min(cr, r) - max(cl, l) + 1) + cur->tag1 * c1 * (min(cr, r) - max(cl, l) + 1);
	ret += query(cur->ls, l, r, c0, c1, cl, mid);
	ret += query(cur->rs, l, r, c0, c1, mid + 1, cr);
	return ret;
}

bool operator<(const pair<int, tnode*> A, pair<int, tnode*> B)
{
	return A.first < B.first;
}

int n, op;
LL ans;
vector<pair<int, tnode*> > tre[200005];
void addsg(int tim, int cm, int l, int r, int coef)
{
	if(tre[cm].empty() || tre[cm].back().first != tim) {
		tnode* cur = tre[cm].empty() ? NULL : tre[cm].back().second;
		tre[cm].push_back(MP(tim, cur));
	}
	tre[cm][(int)tre[cm].size() - 1].second = modify(tre[cm][(int)tre[cm].size() - 1].second, l, r, coef, coef * tim);
}
LL querysg(int cm, int l, int r)
{
	LL ret = 0;
	vector<pair<int, tnode*> >::iterator it = lower_bound(tre[cm].begin(), tre[cm].end(), MP(l, (tnode*)NULL));
	if(it != tre[cm].begin()) ret += query((it - 1)->second, l, r, -l, 1);
	it = upper_bound(tre[cm].begin(), tre[cm].end(), MP(r, (tnode*)NULL));
	if(it != tre[cm].begin()) ret += query((it - 1)->second, l, r, r + 1, -1);
	return ret;
}

int main()
{
	scanf("%d", &n); op = 1;
	rep1(i, n) {
		int a, l, r, k;
		scanf("%d%d%d%d", &a, &l, &r, &k);
		a = (a + op * ans) % (n + 1);
		l = (l + op * ans) % i + 1;
		r = (r + op * ans) % i + 1;
		k = (k + op * ans) % (n + 1);
		if(l > r) swap(l, r);
		
		PII lm = rmq.query(a - 1), lm1 = rmq.dat[262144 | a];
		addsg(i, a == 0, i, i, 1);
		if(i >= 2 && lm.first > lm1.first && lm1.first != i - 1) {
			if(lm.second == -1) lm.first = i - 1;
			addsg(i, lm1.second, lm1.first + 1, lm.first, -1);
			rmq.modify(a, i);
			PII cur = lm;
			while(true) {
				PII nxt = rmq.findf(cur.first);
				if(nxt.first > lm1.first) addsg(i, nxt.second, nxt.first + 1, cur.first, 1);
				else {
					addsg(i, nxt.second, lm1.first + 1, cur.first, 1); break;
				}
				cur = nxt;
			}
		} else rmq.modify(a, i);
		
		ans = querysg(k, l, r);
		printf("%lld\n", ans);
	}
	return 0;
}