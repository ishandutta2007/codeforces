#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int na, nb;
LL la[105], ra[105], lb[105], rb[105];
int cnt;
pair<LL, LL> hv[10000005];

void add_qy(LL l, LL r, LL val)
{
	LL cb = 0;
	while(l < r) {
		hv[cnt ++] = MP((l ^ val) << cb, ((l ^ val) + 1 << cb) - 1);
		hv[cnt ++] = MP((r ^ val) << cb, ((r ^ val) + 1 << cb) - 1);
		l = l + 1 >> 1;
		r = r - 1 >> 1;
		val >>= 1;
		cb ++;
	}
	if(l == r) hv[cnt ++] = MP((l ^ val) << cb, ((l ^ val) + 1 << cb) - 1);
}

void add_qy2(LL l0, LL r0, LL l1, LL r1)
{
	LL cb = 0;
	while(l0 < r0 && l1 < r1) {
		hv[cnt ++] = MP((l0 ^ l1) << cb, ((l0 ^ l1) + 1 << cb) - 1);
		hv[cnt ++] = MP((l0 ^ r1) << cb, ((l0 ^ r1) + 1 << cb) - 1);
		hv[cnt ++] = MP((r0 ^ l1) << cb, ((r0 ^ l1) + 1 << cb) - 1);
		hv[cnt ++] = MP((r0 ^ r1) << cb, ((r0 ^ r1) + 1 << cb) - 1);
		l0 = l0 + 1 >> 1;
		r0 = r0 - 1 >> 1;
		l1 = l1 + 1 >> 1;
		r1 = r1 - 1 >> 1;
		cb ++;
	}
	if(l0 <= r0 && l1 <= r1) {
		hv[cnt ++] = MP((l0 ^ l1) << cb, ((l0 ^ l1) + 1 << cb) - 1);
		hv[cnt ++] = MP((l0 ^ r1) << cb, ((l0 ^ r1) + 1 << cb) - 1);
		hv[cnt ++] = MP((r0 ^ l1) << cb, ((r0 ^ l1) + 1 << cb) - 1);
		hv[cnt ++] = MP((r0 ^ r1) << cb, ((r0 ^ r1) + 1 << cb) - 1);
	}
}

int gsum(LL cl, LL cr)
{
	LL c0 = (cr - cl + 1) % MOD;
	LL c1 = (cl + cr) % MOD;
	if(c0 & 1) c0 += MOD;
	return c0 * c1 / 2 % MOD;
}

int main()
{
	scanf("%d", &na);
	rep(i, na) scanf("%lld%lld", &la[i], &ra[i]);
	scanf("%d", &nb);
	rep(i, nb) scanf("%lld%lld", &lb[i], &rb[i]);
	
	rep(i, na) rep(j, nb) {
		add_qy(la[i], ra[i], lb[j]);
		add_qy(la[i], ra[i], rb[j]);
		add_qy(lb[j], rb[j], la[i]);
		add_qy(lb[j], rb[j], ra[i]);
		add_qy2(la[i], ra[i], lb[j], rb[j]);
	}
	
	sort(hv, hv + cnt);
	int ans = 0;
	rep(i, cnt) {
		LL cl = hv[i].first, cr = hv[i].second;
		while(i + 1 < cnt && cr >= hv[i + 1].first) {
			i ++;
			cr = max(cr, hv[i].second);
		}
		ans = (ans + gsum(cl, cr)) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}