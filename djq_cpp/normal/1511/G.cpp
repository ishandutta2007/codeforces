#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, q, c[200005], cnt[200005], ql[200005], qr[200005], ans[200005];
vector<int> qs[200005];
bool val[1048576];

void insert_v(int x)
{
	rep1(i, 18) {
		int beg = 1 << (i + 1);
		int cur = (1 << i) + (x & ((1 << i) - 1));
		while(cur > 0) {
			val[beg + cur] ^= 1; cur >>= 1;
		}
	}
}

int query_v(int x)
{
	int ret = 0;
	rep1(i, 18) {
		int beg = 1 << (i + 1);
		if(!(x >> (i - 1) & 1)) ret ^= val[beg + 1] << (i - 1);
		int l = 1 << i, r = (1 << i) + ((x - 1) & ((1 << i) - 1));
		while(l <= r) {
			if(!(r & 1)) ret ^= val[beg + r] << (i - 1);
			l >>= 1; r = (r - 1) >> 1;
		}
		l = 1 << i; r = (1 << i) + (((x - 1) ^ 1 << (i - 1)) & ((1 << i) - 1));
		while(l <= r) {
			if(!(r & 1)) ret ^= val[beg + r] << (i - 1);
			l >>= 1; r = (r - 1) >> 1;
		}
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) {
		scanf("%d", &c[i]); cnt[c[i]] ++;
	}
	scanf("%d", &q);
	rep(i, q) {
		scanf("%d%d", &ql[i], &qr[i]);
		qs[qr[i] + 1].push_back(i);
		qs[ql[i]].push_back(i);
	}
	for(int i = m; i >= 1; i --) {
		rep(j, cnt[i]) insert_v(i);
		rep(j, qs[i].size()) {
			int cq = qs[i][j];
			ans[cq] ^= query_v(ql[cq]);
		}
	}
	rep(i, q) printf(ans[i] == 0 ? "B" : "A");
	printf("\n");
	return 0;
}