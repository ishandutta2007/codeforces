#pragma warning(disable:4786)
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
//typedef __int64 LL;

int n, a[400000], id[400000];

bool cmp(int x, int y)
{
	return a[x] < a[y];
}

int main()
{
	int i,last,x;
	scanf("%d", &n);
	FORN(i, n)
	{
		id[i] = i;
		scanf("%d", &a[i]);
	}

	sort(id, id + n, cmp);

	last = -10;
	FORN(i , n)
	{
		x = id[i];
		if(last < a[x]) {a[x] = a[x]; last = a[x];}
		else {a[x] = last + 1; last = last + 1;}
	}

	FORN(i, n)
	{
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");

	return 0;
}