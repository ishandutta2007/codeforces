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

int a[303], w[303][303], mark[303];

int main()
{
//	freopen("a.out", "w", stdout);
	 
	int n, m, k, x, y, z;
	int cnt,i, j;

	scanf("%d %d %d", &n, &m, &k);

	for(i = 1; i <= k; i++) 
	{
		scanf("%d", &a[i]);
		mark[a[i]] = 1;
	}


	int out = n - k;

	if(k == n || m > (n - 1) * (n - 2) / 2 + out)
	{
		printf("-1\n");
		return 0;
	}

	for(i = 1; i <= n; i++)
	{
		if(!mark[i]) break;
	}

	x = i;
	y = a[1];
	z = a[2];

	cnt = 0;
	for(i = 1; i <= n; i++) if(i != x) 
	{
		cnt++;
		printf("%d %d\n", x, i);

		w[x][i] = 1;
		w[i][x] = 1;
	}

	for(i = 1; i <= n; i++) if(i != x && mark[i]==0)
	{
		if(cnt == m) 
		{
			return 0;
		}

		cnt++;
		printf("%d %d\n", z, i);

		w[z][i] = 1;
		w[i][z] = 1;
	}

	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
		{
			if(cnt == m) 
			{
				return 0;
			}

			if(i == j || w[i][j]) continue;
			if(i == z || j == z) continue;

			printf("%d %d\n", i, j);

			w[i][j] = w[j][i] = 1;
			cnt++;
		}

	

	

	return 0;
}