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

int k, n[4], t[4];

VI process(VI V, int n, int t)
{
	VI ret = V;
	for(int i = 0; i < SZ(V); i++)
	{
		if(i < n) ret[i] = ret[i] + t;
		else ret[i] = MAX(ret[i] + t, ret[i - n] + t);
	}
	return ret;
}

int main()
{
	int i;

	scanf("%d", &k);
	FORN(i, 3) scanf("%d", &n[i]);
	FORN(i, 3) scanf("%d", &t[i]);

	VI V = VI(k, 0);
	V = process(V, n[0], t[0]);
	V = process(V, n[1], t[1]);
	V = process(V, n[2], t[2]);

	printf("%d\n", V[k - 1]);

	return 0;
}