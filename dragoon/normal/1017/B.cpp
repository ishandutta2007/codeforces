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
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

int n;
char S[2][100005];
int cnt[3][3];
int main()
{
#ifdef LOCAL
	//freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	scanf("%d %s %s", &n, S[0], S[1]);
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		int b0 = S[0][i] - '0';
		int b1 = S[1][i] - '0';

		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				if (((b0 | b1) != (x | b1)) || ((x|y) != (b0 | y))) {
					ans += cnt[x][y];
				}
			}
		}
		//printf(">>%d %lld\n", i, ans);
		cnt[b0][b1]++;
	}
	printf("%lld\n", ans);
	return 0;
}