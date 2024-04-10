#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

struct simp_t
{
	int dat[524288];
	
	void upd(int id, int v)
	{
		id += 262144;
		dat[id] = v;
		while(id > 1) {
			id >>= 1;
			dat[id] = max(dat[id << 1], dat[id << 1 | 1]);
		}
	}
	
	int rmq(int l, int r)
	{
		l += 262144;
		r += 262144;
		int ret = 0;
		while(l < r) {
			if(l & 1) ret = max(ret, dat[l]);
			if(!(r & 1)) ret = max(ret, dat[r]);
			l = l + 1 >> 1;
			r = r - 1 >> 1;
		}
		if(l == r) ret = max(ret, dat[l]);
		return ret;
	}
}cmin;

int rmq[524288], cnt[524288], lpos[524288], rpos[524288];
int tag[524288];

int armq[524288], alpos[524288], arpos[524288], acnt[524288];

struct segt
{
	void init()
	{
		rep(i, 262144) {
			cnt[262144 + i] = 0;
			lpos[262144 + i] = rpos[262144 + i] = i;
		}
		for(int i = 262143; i >= 1; i --) pushup(i);
	}
	
	void pushdown(int cur)
	{
		rmq[cur << 1] += tag[cur];
		tag[cur << 1] += tag[cur];
		rmq[cur << 1 | 1] += tag[cur];
		tag[cur << 1 | 1] += tag[cur];
		tag[cur] = 0;
	}
	
	void pushup(int cur, int* rmq = rmq, int* cnt = cnt, int* lpos = lpos, int* rpos = rpos)
	{
		rmq[cur] = min(rmq[cur << 1], rmq[cur << 1 | 1]);
		if(rmq[cur << 1 | 1] != rmq[cur]) {
			cnt[cur] = cnt[cur << 1];
			lpos[cur] = lpos[cur << 1];
			rpos[cur] = rpos[cur << 1];
		} else if(rmq[cur << 1] != rmq[cur]) {
			cnt[cur] = cnt[cur << 1 | 1];
			lpos[cur] = lpos[cur << 1 | 1];
			rpos[cur] = rpos[cur << 1 | 1];
		} else {
			cnt[cur] = cnt[cur << 1] + cnt[cur << 1 | 1] + cmin.rmq(rpos[cur << 1], lpos[cur << 1 | 1] - 1);
			lpos[cur] = lpos[cur << 1];
			rpos[cur] = rpos[cur << 1 | 1];
		}
	}
	
	void add(int l, int r, int v, int cur = 1, int cl = 0, int cr = 262143)
	{
		if(l == cl && r == cr) {
			tag[cur] += v;
			rmq[cur] += v;
			return;
		}
		pushdown(cur);
		int mid = cl + cr >> 1;
		if(l <= mid) add(l, min(mid, r), v, cur << 1, cl, mid);
		if(r > mid) add(max(mid + 1, l), r, v, cur << 1 | 1, mid + 1, cr);
		pushup(cur);
	}
	
	void uwei(int id, int v, int cur = 1, int cl = 0, int cr = 262143)
	{
		if(id == cl && id == cr) {
			cmin.upd(id, v);
			return;
		}
		pushdown(cur);
		int mid = cl + cr >> 1;
		if(id <= mid) uwei(id, v, cur << 1, cl, mid);
		else uwei(id, v, cur << 1 | 1, mid + 1, cr);
		pushup(cur);
	}
	
	void query(int l, int r, int cur = 1, int cl = 0, int cr = 262143)
	{
		if(l == cl && r == cr) {
			armq[cur] = rmq[cur];
			acnt[cur] = cnt[cur];
			alpos[cur] = lpos[cur];
			arpos[cur] = rpos[cur];
			return;
		}
		pushdown(cur);
		int mid = cl + cr >> 1;
		armq[cur << 1] = armq[cur << 1 | 1] = INF;
		if(r <= mid) query(l, min(mid, r), cur << 1, cl, mid);
		else if(l > mid) query(max(mid + 1, l), r, cur << 1 | 1, mid + 1, cr);
		else {
			int minvr, cntvr;
			query(l, min(mid, r), cur << 1, cl, mid);
			query(max(mid + 1, l), r, cur << 1 | 1, mid + 1, cr);
		}
		pushup(cur, armq, acnt, alpos, arpos);
	}
}tre;

int n, q;
int a[200005];

set<int> S[200005];

void update(const set<int>& cs, int coef)
{
	if(!cs.empty()) {
		if(coef == -1) tre.uwei(*(cs.begin()), 0);
		else tre.uwei(*(cs.begin()), cs.size());
	}
	if(cs.size() >= 2) tre.add(*(cs.begin()) + 1, *(cs.rbegin()), coef);
}

int query()
{
	tre.query(1, n);
	return n - acnt[1] - cmin.rmq(1, alpos[1] - 1) - cmin.rmq(arpos[1], n);
}

int main()
{
	scanf("%d%d", &n, &q);
	rep1(i, n) {
		scanf("%d", &a[i]);
		S[a[i]].insert(i);
	}
	
	tre.init();
	rep1(i, 200000) update(S[i], 1);
	
	printf("%d\n", query());
	
	rep1(i, q) {
		int id, v;
		scanf("%d%d", &id, &v);
		update(S[a[id]], -1);
		update(S[v], -1);
		S[a[id]].erase(id);
		S[v].insert(id);
		update(S[a[id]], 1);
		update(S[v], 1);
		a[id] = v;
		printf("%d\n", query());
	}
	return 0;
}