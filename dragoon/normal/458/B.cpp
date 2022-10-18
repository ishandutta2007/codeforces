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

LL solve(VI A, VI B)
{
	int szA, szB, i;

	szA = SZ(A);
	szB = SZ(B);

	LL sum = 0;
	for(i = 0; i < szB; i++) sum += B[i];

	LL sumd = 0;
	for(i = 0; i < szA; i++) sumd += A[i];

	unsigned long long ret = sum + sumd;
	for(i = szA - 1; i >= 0; i--)
	{
		sumd -= A[i];
		unsigned long long xx = sum;
		xx *= szA - i;
		xx += sumd;
		if(xx > ret) continue;
		ret = MIN(ret, sum * (szA - i) + sumd);
	}

	return ret;
}

VI V1, V2;

int main()
{
	int n1, n2;
	int i, a;

	scanf("%d %d", &n1, &n2);
	for(i = 0; i < n1; i++)
	{
		scanf("%d", &a);
		V1.push_back(a);	
	}
	for(i = 0; i < n2; i++)
	{
		scanf("%d", &a);
		V2.push_back(a);	
	}

	sort(ALL(V1)); sort(ALL(V2));

	LL ans1 = solve(V1, V2);
	LL ans2 = solve(V2, V1);

	printf("%I64d\n", MIN(ans1, ans2));

	return 0;
}