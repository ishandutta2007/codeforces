#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, q, k, a[300005], ak[300005], ql[300005], qr[300005];
LL ans[300005];
vector<int> qy[300005];

struct fwt
{
	int B;
	LL dat[300005], sum;
	void clear()
	{
		B = n / k + 2; sum = 0;
		for(int i = B; i >= 0; i --) dat[i] = 0;
	}
	void add(int id, LL val)
	{
		sum += val;
		for(; id <= B; id += id & -id) dat[id] += val;
	}
	LL query(int id)
	{
		LL ret = 0;
		for(; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
}t0, t1;
void add_t(int r, LL val)
{
	if(r == 0) return;
	t0.add(r, val); t1.add(r, 1LL * r * val);
}
LL query_t(int r)
{
	if(r == 0) return 0;
	return 1LL * r * (t0.sum - t0.query(r)) + t1.query(r);
}
void add_t(int l, int r, LL val)
{
	add_t(l, -val); add_t(r + 1, val);
}
LL query_t(int l, int r)
{
	return query_t(r + 1) - query_t(l);
}

PII sta[300005];
int siz;
deque<PII> que;
int main()
{
	scanf("%d%d%d", &n, &q, &k);
	rep1(i, n) scanf("%d", &a[i]);
	rep(i, q) scanf("%d%d", &ql[i], &qr[i]);
	
	for(int i = n; i >= 1; i --) {
		if(!que.empty() && que.front().second == i + k) que.pop_front();
		while(!que.empty() && que.back().first >= a[i]) que.pop_back();
		que.push_back(MP(a[i], i));
		ak[i] = que.front().first;
	}
	
	rep(i, q) {
		ans[i] = a[ql[i]];
		qr[i] = (qr[i] - ql[i]) / k;
		qy[ql[i] + 1].push_back(i);
	}
	
	for(int i = n; i > n - k; i --) {
		t0.clear(); t1.clear();
		siz = 1; sta[0] = MP(-1, i / k + 1);
		for(int j = i; j >= 1; j -= k) {
			while(sta[siz - 1].first >= ak[j]) {
				add_t(sta[siz - 1].second, sta[siz - 2].second - 1, ak[j] - sta[siz - 1].first);
				siz --;
			}
			int cj = j / k;
			sta[siz ++] = MP(ak[j], cj);
			add_t(cj, cj, ak[j]);
			rep(iq, qy[j].size()) {
				int cq = qy[j][iq], cv = a[j - 1];
				int cpos = lower_bound(sta, sta + siz, MP(cv, -1)) - sta - 1;
				if(cj + qr[cq] <= sta[cpos].second) ans[cq] += 1LL * cv * qr[cq];
				else ans[cq] += 1LL * cv * (sta[cpos].second - cj) + query_t(sta[cpos].second, cj + qr[cq] - 1);
			}
		}
	}
	
	rep(i, q) printf("%lld\n", ans[i]);
	return 0;
}