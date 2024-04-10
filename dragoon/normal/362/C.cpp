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

int tree[5003];

//return cf[idx]
int read(int idx)
{
	int sum = 0;

	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

//add val to f[idx].
//MaxVal = Just max value of index
void update(int idx ,int val)
{
	while (idx <= 5000)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int num[5003];

int main()
{
	int n, i, ans, cnt, add, sub, j;
	int sx, sy, bx, by, gain;

	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
		num[i]++;
	}

	int z = 0;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i; j++)
			if(num[j] > num[i])
				z++;

	ans = 0;
	cnt = 0;
	for(i = 1; i <= n; i++)
	{
		if(ans == 0) cnt++;

		CLR(tree);
		add = 0;
		for(j = i + 1; j <= n; j++)
		{
			if(num[j] < num[i])
			{
				sx = (j - i - 1) - add;
				bx = add;

				sub = read(num[j]);

				sy = sub;
				by = (j - i - 1) - sub;

				gain = by - sy - bx + sx + 1;

				if(gain == ans) cnt++;
				else if(gain > ans) {cnt = 1; ans = gain;}
			}

			if(num[j] > num[i]) add++;
			if(i != j) update(num[j], 1);
		}
	}

	printf("%d %d\n", z - ans, cnt);

	return 0;
}