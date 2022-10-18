#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;
int a, b, h, w, n;
VI Z;
int dp[100005][36];

int check(int a, int b, int h, int w) {
	a = (a + h - 1) / h;
	b = (b + w - 1) / w;

	for (int i = 0; i <= 34; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (j >= a && dp[j][i] >= b) {
				return i;
			}
		}
	}
	return 100000000;
}

void dptable() {
	MEM(dp, -1);
	dp[1][0] = 1;
	int k = 0;
	for (int z : Z) {
		for (int j = k; j >= 0; j--) {
			for (int i = 1; i <= 100000; i++) {
				if (dp[i][j] == -1) continue;
				// two options:
				dp[MIN(100000, (1LL * i) * z)][j + 1] = MAX(dp[MIN(100000, (1LL * i) * z)][j + 1], dp[i][j]);
				dp[i][j + 1] = MAX(dp[i][j + 1], MIN((1LL * dp[i][j]) * z, 100000));
			}
		}
		k++;
	}
}

int main()
{
	scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
	VI V;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		V.push_back(x);
	}
	sort(ALL(V));
	for (int i = SZ(V) - 1, j = 1; i >= 0 && j <= 34; i--, j++) {
		Z.push_back(V[i]);
	}
	dptable();
	int ans1 = check(a, b, h, w);
	int ans2 = check(b, a, h, w);
	int ans = MIN(ans1, ans2);
	if (ans > 1000) ans = -1;
	printf("%d\n", ans);

	return 0;
}