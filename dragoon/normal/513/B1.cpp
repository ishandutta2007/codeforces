#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
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

int arr[100];
LL p2[100];

int main()
{
	int i;
	int n;
	LL m;
	scanf("%d %I64d", &n, &m);
	if(n == 1)
	{
		printf("1\n");
		return 0;
	}

	int left = 1, right = n;
	p2[0] = 1;
	for(i = 1; i < 100; i++) p2[i] = (p2[i - 1] * 2);
	for(i = 1; i <= n; i++)
	{
		if( m <= p2[n - i - 1] )
		{
			arr[left++] = i;
		}
		else
		{
			arr[right--] = i;
			m -= p2[n - i - 1];
		}
	}

	for(i = 1; i <= n; i++)
	{
		if(i > 1) printf(" ");
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}