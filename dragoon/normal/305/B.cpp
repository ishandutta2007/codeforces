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
	LL p, q, b, a;
	int n, i;

	scanf("%I64d%I64d", &p, &q);
	scanf("%d", &n);

	if(n == 1)
	{
		scanf("%I64d", &b);
		if(p%q==0 && p/q==b)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}

	for(i = 1; i < n; i++)
	{
		scanf("%I64d", &b);
		if(b > p/q)
		{
			printf("NO\n");
			return 0;
		}

		p = p - b*q;
		q = q;

		swap(p, q);

		if(p==0 || q==0)
		{
			printf("NO\n");
			return 0;
		}

	}

	scanf("%I64d", &b);

	if(q && p%b==0 && (p/b) == q)
		printf("YES\n");
	else
		printf("NO\n");


	return 0;
}