#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

string in[500050];
char u[500050];

vector <pii> dp[500050];
pii mn[500050];

int pos[500050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		in[i] = string(u);
		dp[i].resize(in[i].size());
	}
	
	for (i = 0; i < in[1].size(); i++) dp[1][i] = pii((int)in[1].size() - 1 - i, 0);
	for (i = 2; i <= N; i++) {
		mn[0] = pii(dp[i-1][0].first, 0);
		for (j = 1; j < in[i - 1].size(); j++) mn[j] = min(mn[j - 1], pii(dp[i-1][j].first, j));
		
		int a;
		for (a = 0; a < in[i].size() && a < in[i - 1].size(); a++) if (in[i][a] != in[i - 1][a]) break;
		
		bool c = false;
		if (a < in[i - 1].size() && (a == in[i].size() || in[i - 1][a] > in[i][a])) c = true;

		for (j = 0; j < in[i].size(); j++) {
			if (j < a) dp[i][j] = mn[j];
			else if (c) dp[i][j] = mn[a-1];
			else dp[i][j] = mn[(int)in[i - 1].size() - 1];
			dp[i][j].first += (int)in[i].size() - j - 1;
		}
	}
	
	pii ans = pii(INF, INF);
	for (i = 0; i < in[N].size(); i++) {
		if (ans > dp[N][i]) {
			ans = dp[N][i];
			pos[N] = i;
		}
	}
	
	for (i = N; i > 1; i--) {
		pos[i - 1] = ans.second;
		ans = dp[i - 1][pos[i - 1]];
	}
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= pos[i]; j++) printf("%c", in[i][j]);
		printf("\n");
	}
	return 0;
}