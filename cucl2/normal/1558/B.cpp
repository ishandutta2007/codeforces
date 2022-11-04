#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int jt;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

int dp[4000005], pre[4000005];
int N;

int main() {
	scanf("%d%d", &N, &jt);
	dp[N] = pre[N] = 1;
	for (int i = N - 1; i; --i) {
		dp[i] = pre[i + 1];
		for (int j = 2; i * j <= N; ++j) {
			int lb = i * j, ub = i * j + j - 1;
			ub = min(ub, N);
			if (lb <= ub) add(dp[i], Sub(pre[lb], pre[ub + 1]));
		}
		pre[i] = Add(pre[i + 1], dp[i]);
	}
	printf("%d\n", dp[1]);
	return 0;
}