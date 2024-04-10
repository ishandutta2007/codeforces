#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const long double INF = 1.0 / 0.0;

struct treap
{
	int cnt;
	long double c2[12005], c1[12005], c0[12005], pos[12005];
	
	void init()
	{
		cnt = 2;
		c1[0] = -INF;
	}
	void add(long double n2, long double n1, long double n0)
	{
		rep(i, cnt) {
			c2[i] += n2; c1[i] += n1; c0[i] += n0;
		}
	}
	long double findl()
	{
		rep(i, cnt) if(i == cnt - 1 || 2 * c2[i] * pos[i] + c1[i] >= 0) {
			long double cpos = c2[i] == 0 ? pos[i - 1] : -c1[i] / (2 * c2[i]);
			if(i > 0) cpos = max(cpos, pos[i - 1]);
			return cpos;
		}
	}
	long double getans(long double cpos)
	{
		for(int i = cnt - 1; i >= 0; i --) if(i == 0 || pos[i - 1] <= cpos)
		return c2[i] * cpos * cpos + c1[i] * cpos + c0[i];
	}
	void putl(long double cpos, int len)
	{
		for(int i = cnt - 1; i >= 0; i --) if(i == 0 || pos[i - 1] <= cpos) {
			long double cc0 = c0[i], cc1 = c1[i], cc2 = c2[i];
			int ccnt = (i == 0 || cpos > pos[i - 1]) + (len > 0) + (i == cnt - 1 || cpos < pos[i]) - 1;
			for(int j = cnt - 1; j >= i; j --) {
				pos[j + ccnt] = pos[j] + len;
				c0[j + ccnt] = c0[j] - c1[j] * len + c2[j] * len * len;
				c1[j + ccnt] = c1[j] - 2 * c2[j] * len;
				c2[j + ccnt] = c2[j];
			}
			cnt += ccnt;
			ccnt = 0;
			if(i == 0 || cpos > pos[i - 1]) {
				pos[i + ccnt] = cpos; ccnt ++;
			}
			if(len > 0) {
				pos[i + ccnt] = cpos + len; c2[i + ccnt] = c1[i + ccnt] = 0; 
				c0[i + ccnt] = cc2 * cpos * cpos + cc1 * cpos + cc0; ccnt ++;
			}
			break;
		}
	}
}tre;

int n, q, a, b, x[6005];
long double tpos[6005], ans[6005];

int main()
{
	scanf("%d%d%d%d", &n, &q, &a, &b);
	b -= a; q -= 1 + (n - 1) * a;
	rep(i, n) {
		scanf("%d", &x[i]);
		x[i] -= i * a + 1;
	}
	tre.init();
	rep(i, n) {
		tre.add(1.0, -2.0 * x[i], 1.0 * x[i] * x[i]);
		tpos[i] = tre.findl();
		if(i < n - 1) tre.putl(tpos[i], b);
	}
	
	ans[n - 1] = min(tpos[n - 1], (long double)(1) * q);
	for(int i = n - 2; i >= 0; i --)
	if(ans[i + 1] >= tpos[i] + b) ans[i] = ans[i + 1] - b;
	else if(ans[i + 1] >= tpos[i]) ans[i] = tpos[i];
	else ans[i] = ans[i + 1];
	rep(i, n) printf("%.6lf ", (double)ans[i] + i * a + 1);
	printf("\n%.6lf\n", (double)tre.getans(ans[n - 1]));
	return 0;
}