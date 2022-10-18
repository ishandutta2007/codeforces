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
//typedef long long int LL;
//typedef __int64 LL;

// return 1 if first player wins
int f(int n0, int n1, int k) {
	if (k == 0) {
		if (n1 % 2) return 1;
		return 0;
	}
	int move_second = k / 2;
	int move_first = k - move_second;

	if (move_second >= n1) return 0;

	if (k % 2 == 0) {
		if (move_first < n0) return 0;
		if ((n0 + n1 - k) % 2) return 1;
		return 0;
	}

	if (k % 2 == 1) {
		if (move_second < n0) return 1;
		if ((n0 + n1 - k) % 2) return 1;
		return 0;
	}

	assert(0);
}

int DP[55][55][55][2];
int dp(int n0, int n1, int k, int pl = 1) {
	if (k == 0) {
		if (n1 % 2) return 1;
		return 0;
	}
	if (DP[n0][n1][k][pl] != -1) return DP[n0][n1][k][pl];
	int &ret = DP[n0][n1][k][pl];
	
	if (n0) {
		if(dp(n0 - 1, n1, k - 1, pl ^ 1) == 1 && pl == 1) return ret = 1;
		if (dp(n0 - 1, n1, k - 1, pl ^ 1) == 0 && pl == 0) return ret = 0;
	}
	if (n1) {
		if (dp(n0, n1 - 1, k - 1, pl ^ 1) == 0 && pl == 0) return ret = 0;
		if (dp(n0, n1 - 1, k - 1, pl ^ 1) == 1 && pl == 1) return ret = 1;
	}
	return ret = pl ^ 1;
}

int main()
{
	int n, k;
	int x;

	MEM(DP, -1);

	scanf("%d %d", &n, &k);
	int n0 = 0, n1 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x & 1) n1++; else n0++;
	}
	k = n - k;

	if (f(n0, n1, k)) printf("Stannis\n");
	else printf("Daenerys\n");
	/*
	for (int n = 1; n <= 50; n++) {
		for (int n0 = 0; n0 <= n; n0++) {
			for (int k = 0; k <= n; k++) {
				if (f(n0, n - n0, k) != dp(n0, n - n0, k))
					printf("%d %d %d\n", n0, n - n0, k);
			}
		}
	}*/

	return 0;
}