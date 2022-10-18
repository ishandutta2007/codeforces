#pragma warning(disable:4786)
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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
typedef __int64 LL;

int main()
{
	LL x, y, m;
	LL ans = 0;

	scanf("%I64d %I64d %I64d", &x, &y, &m);

	if(x >= m || y >= m)
	{
		printf("0\n");
		return 0;
	}

	if(x > y) swap(x, y);

	if(y <= 0)
	{
		printf("-1\n");
		return 0;
	}

	if(x <= 0)
	{
		//make x positive
		LL xx = -x;
		ans = (xx + y - 1)/y;
		x += ans * y;
	}


	while(1)
	{
		if(x > y) swap(x, y);
		if(y >= m) break;

		//x < y
		
		x += y;
		ans++;
	}

	printf("%I64d\n", ans);

	return 0;
}