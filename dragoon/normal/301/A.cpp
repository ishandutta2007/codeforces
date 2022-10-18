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
//typedef __int64 LL;

int num[500];

int n, i, sum = 0;
int pos, zero, neg, a;
int vis[1000];
int x, y, u, v;
queue<int> Q;

int main()
{

	scanf("%d", &n);
	int nn = 2*n - 1;

	for(i = 0; i < nn; i++)
	{
		scanf("%d", &num[i]);
		sum += ABS(num[i]);

		if(num[i] < 0) neg++;
		else if(num[i]==0) zero++;
		else pos++;
	}

	if(neg >= n)
	{
		int cnt = 0;
		for(i =0; i < nn; i++) if(num[i] < 0)
		{
			num[i] = -num[i];
			cnt++;

			if(cnt == n) break;
		}
	}


	for(i = 0; i <= zero; i++)
	{
		vis[ pos + i ] = 1;
		Q.push( pos + i );
	}

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		for(i = 0; i <= n; i++)
		{
			if(i > u) continue;
			v = nn - u;
			if(n - i > v) continue;

			x = u - i + (n - i);
			y = v - (n - i) + i;

			if(vis[x]) continue;
			vis[x] = 1;
			Q.push( x );
		}
	}

	if(vis[nn]) printf("%d\n", sum);
	else
	{
		a = 1000000;
		for(i = 0; i < nn; i++)
			a = MIN(a, ABS(num[i]));

		printf("%d\n", sum - 2*a);
	}

	return 0;
}