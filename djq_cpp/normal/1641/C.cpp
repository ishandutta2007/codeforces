#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, q, qt[200005], ql[200005], qr[200005], qx[200005];
int nxt[200005], tim[200005], tim2[200005];
int root(int x)
{
	return x == nxt[x] ? x : nxt[x] = root(nxt[x]);
}
 
PII st[25][400005];
PII rmq(int l, int r)
{
	if(l > r) return MP(-1, 0);
	int len = __lg(r - l + 1);
	return max(st[len][l], st[len][r - (1 << len) + 1]);
}
int main()
{
	scanf("%d%d", &n, &q);
	rep(i, q) {
		scanf("%d", &qt[i]);
		if(!qt[i]) scanf("%d%d", &ql[i], &qr[i]);
		scanf("%d", &qx[i]);
	}
	
	rep1(i, n + 1) {
		nxt[i] = i; tim[i] = q;
	}
	rep(i, q) if(!qt[i] && !qx[i]) for(int j = root(ql[i]); j <= qr[i]; j = root(j)) {
		tim[j] = i; nxt[j] = j + 1;
	}
	
	rep1(i, n) st[0][i] = MP(tim[i], i);
	rep1(i, 17) rep1(j, n) st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	
	rep1(i, n) tim2[i] = q;
	rep(i, q) if(!qt[i] && qx[i]) {
		int pos = rmq(ql[i], qr[i]).second;
		PII p2 = max(rmq(ql[i], pos - 1), rmq(pos + 1, qr[i]));
		tim2[pos] = min(tim2[pos], max(i, p2.first));
	}
	
	rep(i, q) if(qt[i]) {
		if(tim[qx[i]] < i) printf("NO\n");
		else if(tim2[qx[i]] < i) printf("YES\n");
		else printf("N/A\n");
	}
	return 0;
}