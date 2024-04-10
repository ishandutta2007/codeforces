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
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int a[100005], sum[100005];
char S[100005];

int main()
{
	int n, i, ans, run;

	scanf("%d", &n);
	for(i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]);

		if(i) sum[i] = sum[i - 1] + a[i];
		else sum[i] = a[i];
	}

	scanf("%s", S);

	ans = 0;
	run = 0;
	for(i = n - 1; i >= 0; i--)
	{
		if(S[i] == '1' && i)
		{
			if(ans < run + sum[i - 1])
				ans = run + sum[i - 1];
		}
		
		if(S[i] == '1')
		{
			run += a[i];
		}

		ans = MAX(ans, run);
	}

	printf("%d\n", ans);

	return 0;
}