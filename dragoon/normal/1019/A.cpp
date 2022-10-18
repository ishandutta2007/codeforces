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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int p[3003], c[3003];
VI V[3003];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &p[i], &c[i]);
		V[p[i]].push_back(c[i]);
		ans += c[i];
	}
	for (int i = 1; i <= m; i++) {
		sort(ALL(V[i]));
		reverse(ALL(V[i]));
	}
	for (int k = 1; k <= n; k++) {
		LL now = 0;
		int cnt = SZ(V[1]);
		VI Z;
		for (int j = 2; j <= m; j++) {
			for (int i = 0; i < SZ(V[j]); i++) {
				if (i < k - 1) Z.push_back(V[j][i]);
				else {
					cnt++;
					now += V[j][i];
				}
			}
		}
		sort(ALL(Z));
		for (int i = 0; i < SZ(Z); i++) {
			if (cnt >= k) break;
			cnt++;
			now += Z[i];
		}
		if (cnt < k) continue;
		ans = MIN(ans, now);
	}
	printf("%lld\n", ans);
	return 0;
}