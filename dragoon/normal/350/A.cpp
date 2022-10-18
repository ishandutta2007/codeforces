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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int ac[102], wa[102];
int n, m, i, v, flag;

int main()
{
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) scanf("%d",&ac[i]);
	for(i = 0; i < m; i++) scanf("%d",&wa[i]);

	for(v = 1; v <= 300; v++)
	{
		flag = 1;
		for(i = 0; i < n; i++) if(ac[i] > v) flag = 0;
		if(!flag) continue;

		flag = 0;
		for(i = 0; i < n; i++) if(2*ac[i] <= v) flag = 1;
		if(!flag) continue;

		flag = 0;
		for(i = 0; i < m; i++) if(wa[i] <= v) flag = 1;
		if(flag) continue;

		break;
	}


	if(v > 300) printf("-1\n");
	else printf("%d\n", v);

	return 0;
}