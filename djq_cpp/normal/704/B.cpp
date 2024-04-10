#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, s, t, x[100005], a[100005], b[100005], c[100005], d[100005];

priority_queue<LL, vector<LL>, greater<LL> > que;
LL val1, tag;
void conv_r(LL v)
{
	que.push(v - tag);
}
void conv_l(LL v)
{
	que.push(-v - tag);
	val1 += v + que.top() + tag;
	que.pop();
}
void add0(LL v)
{
	val1 += v;
	if(!que.empty()) {
		v = que.top() - v;
		que.pop(); que.push(v);
	}
}

int main()
{
	scanf("%d%d%d", &n, &s, &t);
	rep1(i, n) scanf("%d", &x[i]);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) scanf("%d", &b[i]);
	rep1(i, n) scanf("%d", &c[i]);
	rep1(i, n) scanf("%d", &d[i]);
	if(s > t) {
		swap(s, t);
		rep1(i, n) {
			swap(a[i], c[i]); swap(b[i], d[i]);
		}
	}
	val1 = s == 1 ? d[1] : b[1] + d[1];
	for(int i = 2; i <= n; i ++) {
		val1 += (i > s && i <= t ? 1 : 2) * (x[i] - x[i - 1]); tag += 2 * (x[i] - x[i - 1]);
		if(i == n) break;
		if(i == s) {
			val1 += c[i]; conv_r(d[i] - c[i]);
		} else if(i == t) {
			val1 += b[i]; conv_l(a[i] - b[i]);
		} else {
			int f = min(a[i] + d[i], b[i] + c[i]);
			val1 += f;
			conv_r(b[i] + d[i] - f);
			if(i > s && i < t) add0(a[i] + d[i] - f);
			conv_l(a[i] + c[i] - f);
		}
	}
	LL ans = val1 + (t == n ? a[n] : a[n] + c[n]);
	printf("%lld\n", ans);
	return 0;
}