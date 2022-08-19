#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAGIC = 640;

int n, q, p[200005];
int tp[200005], qa[200005], qb[200005];
LL ans[200005];
LL a[200005];

LL pre[645], mat[645][645], tag[645];
int grp[200005], nxt[645], tot;
int pos[645], cnt;
int invp[200005];
bool ok[200005];
void solve(int l, int r)
{
	rep1(i, n) invp[p[i]] = i;
	rep1(i, n) ok[i] = true;
	for(int i = l; i <= r; i ++) if(tp[i] == 3) ok[qa[i]] = ok[qb[i]] = false;
	else if(tp[i] == 2) ok[qa[i]] = false;
	rep1(i, n) grp[i] = 0;
	tot = 0;
	rep1(i, n) if(!ok[i]) {
		int j = i; tot ++;
		do {
			grp[j] = tot; j = invp[j];
		} while(ok[j]);
	}
	rep1(i, n) if(!ok[i]) nxt[grp[i]] = grp[p[i]];
	
	cnt = 0;
	for(int i = l; i <= r; i ++) if(tp[i] == 1) {
		pos[cnt ++] = qa[i] - 1; pos[cnt ++] = qb[i];
	}
	sort(pos, pos + cnt);
	cnt = unique(pos, pos + cnt) - pos;
	
	for(int i = 0; i <= cnt; i ++) pre[i] = 0;
	for(int i = 0; i <= cnt; i ++) for(int j = 0; j <= tot; j ++) mat[i][j] = 0;
	for(int i = 0; i <= tot; i ++) tag[i] = 0;
	
	int cp = 0;
	rep1(i, n) {
		while(cp < cnt && i > pos[cp]) cp ++;
		pre[cp] += a[i];
		mat[cp][grp[i]] ++;
	}
	rep1(i, cnt) pre[i] += pre[i - 1];
	rep1(i, cnt) for(int j = 0; j <= tot; j ++) mat[i][j] += mat[i - 1][j];
	
	for(int i = l; i <= r; i ++) if(tp[i] == 1) {
		int cq = lower_bound(pos, pos + cnt, qa[i] - 1) - pos;
		ans[i] -= pre[cq];
		for(int j = 0; j <= tot; j ++) ans[i] -= mat[cq][j] * tag[j];
		cq = lower_bound(pos, pos + cnt, qb[i]) - pos;
		ans[i] += pre[cq];
		for(int j = 0; j <= tot; j ++) ans[i] += mat[cq][j] * tag[j];
	} else if(tp[i] == 2) {
		int cur = grp[qa[i]], j = cur;
		do {
			tag[j] += qb[i]; j = nxt[j];
		} while(j != cur);
	} else if(tp[i] == 3) {
		swap(nxt[grp[qa[i]]], nxt[grp[qb[i]]]); swap(p[qa[i]], p[qb[i]]);
	}
	rep1(i, n) a[i] += tag[grp[i]];
}

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%lld", &a[i]);
	rep1(i, n) scanf("%d", &p[i]);
	scanf("%d", &q);
	rep(i, q) scanf("%d%d%d", &tp[i], &qa[i], &qb[i]);
	for(int i = 0; i < q; i += MAGIC / 2)
	solve(i, min(q, i + MAGIC / 2) - 1);
	rep(i, q) if(tp[i] == 1) printf("%lld\n", ans[i]);
	return 0;
}