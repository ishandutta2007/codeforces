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
//typedef __int64 LL;

int done[100];
int ans[100];

int main()
{
	char S[100];
	int k, A[100];
	int i, j;

	scanf("%s %d", S, &k);
	for(i = 0; S[i]; i++)
		A[i] = S[i] - '0';

	int L = strlen(S);

	for(i = 0; i < L; i++)
	{
		for(j = 9; j >= 0; j--)
		{
			int alive = 0, t;
			for(t = 0; t < L; t++)
				if(A[t] == j && done[t] == 0)
					break;
				else if(done[t] == 0)
					alive++;

			if(t == L) continue;
			if(alive > k) continue;
			k -= alive;
			ans[i] = j;
			done[t] = 1;
			break;
		}
	}

	for(i = 0; i < L; i++)
		printf("%d", ans[i]);
	printf("\n");


	return 0;
}