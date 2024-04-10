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

int tree[200005];
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
	while (idx <= 200004)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}



int id[200005];
int ans[200005];
vector<int> V[200005];
vector<PII> query[200005];
int n;

void gen()
{
	int i, j;

	for(i = 1; i <= n; i++)
	{
		for(j = i; j <= n; j += i)
		{
			V[MAX(id[i], id[j])].push_back( MIN(id[i], id[j]) );
		}
	}
}

int main()
{
	int m, i, a, x, y, sz, j, q;
	int total;

	scanf("%d %d", &n, &m);

	for(i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		id[a] = i;
	}

	gen();

	for(i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		query[y].push_back(PII(x, i));
	}

	total = 0;
	for(i = 1; i <= n; i++)
	{
		sz = V[i].size();
		for(j = 0; j < sz; j++)
		{
			update(V[i][j], 1);
			total++;
		}

		sz = query[i].size();
		for(j = 0; j < sz; j++)
		{
			q = read(query[i][j].first - 1);
			ans[ query[i][j].second ] = total - q;
		}
	}

	for(i = 1; i <= m; i++)
		printf("%d\n", ans[i]);

	return 0;
}