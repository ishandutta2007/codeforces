#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, t, w, q, b, len, a[10000005], xa[10000005], xa1[10000005], cnt, bcnt;
vector<int> arr[35];

void updf(int cur, int id, int coef)
{
	if(cur == 0) {
		cnt += coef * (arr[cur][id] == -1); return;
	}
	int nid = id & ((1 << (cur - 1)) - 1);
	int ct = t >> (cur - 1) & 1;
	int u = arr[cur][nid], v = arr[cur][nid | 1 << (cur - 1)];
	if(ct == 1) bcnt += coef * (u != -1 && v != -1 && u != v);
	else cnt += coef * (arr[cur][nid] == -1 && arr[cur][nid | 1 << (cur - 1)] == -1);
	updf(cur - 1, nid, coef);
}

void upd(int cur, int id)
{
	if(cur == 0) return;
	int nid = id & ((1 << (cur - 1)) - 1);
	int ct = t >> (cur - 1) & 1;
	int u = arr[cur][nid], v = arr[cur][nid | 1 << (cur - 1)];
	if(ct == 1) arr[cur - 1][nid] = u != -1 ? u : v;
	else arr[cur - 1][nid] = u == -1 ? -1 : (v == -1 ? -1 : u ^ v);
	upd(cur - 1, nid);
}

void adda(int id, int val)
{
	cnt -= max(xa1[id % b] - 1, 0);
	if(a[id] == -1) xa1[id % b] --;
	else xa[id % b] ^= a[id];
	a[id] = val;
	if(a[id] == -1) xa1[id % b] ++;
	else xa[id % b] ^= a[id];
	if(t == b) bcnt -= arr[len][id % b] != 0 && arr[len][id % b] != -1;
	else updf(len, id % b, -1);
	arr[len][id % b] = xa1[id % b] == 0 ? xa[id % b] : -1;
	upd(len, id % b);
	if(t == b) bcnt += arr[len][id % b] != 0 && arr[len][id % b] != -1;
	else updf(len, id % b, 1);
	cnt += max(xa1[id % b] - 1, 0);
}

int power(int x, int r, int p)
{
	int ret = 1;
	while(r > 0) {
		if(r & 1) ret = 1ULL * ret * x % p;
		x = 1ULL * x * x % p;
		r >>= 1;
	}
	return ret;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &t, &w);
	rep(i, n) a[i] = -1;
	b = ((n ^ (n - 1)) + 1) >> 1;
	t = min(t, b);
	for(; (1 << len) < b; len ++) ;
	rep(i, len + 1) arr[i].resize(1 << i, -1);
	rep(i, b) xa1[i] = n / b;
	cnt = n - t;
	rep(i, m) {
		int d, e;
		scanf("%d%d", &d, &e);
		adda(d - 1, e);
	}
	scanf("%d", &q);
	rep(i, q) {
		int f, g, p;
		scanf("%d%d%d", &f, &g, &p);
		adda(f - 1, g);
		printf("%d\n", bcnt ? 0 : power(1 << w, cnt, p));
	}
	return 0;
}