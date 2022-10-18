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
typedef __int64 LL;

int who[100005], wheres[100005];

int main()
{
	int n, m, k;
	int i;

	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		a--;
		who[i] = a;
		wheres[a] = i;
	}

	LL ans = 0;
	for(i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		a--;

		int y = wheres[a];
		ans += (y / k) + 1;
		if(y == 0) continue;
		int b = who[y - 1];
		int yy = y - 1;

		who[yy] = a;
		who[y] = b;
		wheres[a] = yy;
		wheres[b] = y;
	}

	printf("%I64d\n", ans);

	return 0;
}