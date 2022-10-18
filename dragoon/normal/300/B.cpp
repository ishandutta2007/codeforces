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

struct Trio
{
	int a, b, c;

	Trio(int x, int y, int z)
	{
		a = x;
		b = y;
		c = z;

	}

	Trio()
	{
	}
};

vector<Trio> VV;

int w[50][50];
int cnt, cnt2;

int main()
{
	int n, m, i, a, b;
	int j, k, id, id1;

	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		w[a][b] = w[b][a] = 1;
	}

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			for(k = 1; k <=n; k++)
				if(w[j][i] && w[i][k])
					w[j][k] = 1;
	}

	vector<int> V1;
	vector<PII> V2;

	cnt = 0;
	cnt2 = 0;
	for(i = 1; i <= n; i++)
	{
		cnt = 0;
		for(j = 1; j <= n; j++)
		{
			if(i == j)
				continue;

			cnt += w[i][j];
			if(w[i][j] && j < i)
				break;

			if(w[i][j])
			{
				id1 = id;
				id = j;				
			}
		}

		if(j <= n) continue;

		if(cnt == 2)
		{
			VV.push_back( Trio(i, id, id1) );
		}

		if(cnt > 2)
		{
			printf("-1\n");
			return 0;
		}

		if(cnt == 1)
		{
			cnt2++;
			V2.push_back( PII(i, id) );
		}

		if(cnt == 0)
		{
			V1.push_back( i );
		}
	}

	if(cnt2 > n/3 - VV.size())
	{
			printf("-1\n");
			return 0;
	}

	for(i = 0; i < VV.size(); i++)
	{
		printf("%d %d %d\n",VV[i].a, VV[i].b, VV[i].c);
	}

	for(i = 0; i < cnt2; i++)
	{
		printf("%d %d %d\n",V2[i].first, V2[i].second, V1[i]);
	}

	for(i = i; i < V1.size(); i+=3)
	{
		printf("%d %d %d\n", V1[i], V1[i+1], V1[i + 2]);
	}

	return 0;
}