#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 1000000007;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = 1ll * a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return 1ll * a * b % jt; }

int dp[205][205][205];
int go[205][2];
int N;
char s[205];
int kmp[205];

int main() {
	scanf("%d", &N); N <<= 1;
	scanf("%s", s + 1);
	int M = strlen(s + 1);
	kmp[0] = -1; kmp[1] = 0;
	int now = 1;
	for (int i = 2; i <= N; ++i) {
		while (now && s[i] != s[now]) now = kmp[now - 1] + 1;
		kmp[i] = now++;
	}
	for (int i = 0; i < M; ++i) for (int j = 0; j < 2; ++j) {
		int now = i;
		while (~now && "()"[j] != s[now + 1]) now = kmp[now];
		++now;
		go[i][j] = now;
	}
	dp[0][0][0] = 1;
	for (int i = 1; i <= N; ++i) for (int j = 0; j <= 200; ++j) for (int k = 0; k <= M; ++k) {
		if (k == M) {
			add(dp[i][j + 1][k], dp[i - 1][j][k]);
			if (j) add(dp[i][j - 1][k], dp[i - 1][j][k]);
		}
		else {
			{
				// left
				int now = go[k][0];
				add(dp[i][j + 1][now], dp[i - 1][j][k]);
			}
			if (j) {
				// right
				int now = go[k][1];
				add(dp[i][j - 1][now], dp[i - 1][j][k]);
			}
		}
	}
	printf("%d\n", dp[N][0][M]);
	return 0;
}