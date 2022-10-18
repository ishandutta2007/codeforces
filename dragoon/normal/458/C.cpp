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

int cntTree[400005];
int sumTree[400005];

VI T, V[100005], SUM[100005];
VP Z;

void insert(int value, int at, int left, int right)
{
	if(left == right)
	{
		cntTree[at] = 1;
		sumTree[at] = T[left];
		return;
	}

	int mid = (left + right) / 2;
	if(value <= mid) insert(value, at * 2, left, mid);
	else insert(value, at * 2 + 1, mid + 1, right);
	cntTree[at] = cntTree[at * 2] + cntTree[at * 2 + 1];
	sumTree[at] = sumTree[at * 2] + sumTree[at * 2 + 1];
}

int query(int value, int at, int left, int right)
{
	if(value > cntTree[at]) return 1000000000;
	if(value == 0) return 0;
	if(value == cntTree[at]) return sumTree[at];

	int mid = (left + right) / 2;
	if(cntTree[at * 2] >= value) return query(value, at * 2, left, mid);
	return sumTree[at * 2] + query(value - cntTree[at * 2], at * 2 + 1, mid + 1, right);
}

int M[100005];

void insert(int value)
{
	insert(M[value], 1, 0, SZ(T) - 1);
	M[value]++;
}

int query(int value)
{
	return query(value, 1, 0, SZ(T) - 1);
}

int consumed[100005];

int main()
{
	int n, a, b, i;
	int sz, sum, j, nBuckets;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		V[a].push_back(b);
		if(a) T.push_back(b);
	}

	for(i = 1; i <= 100000; i++)
	{
		Z.push_back(PII(SZ(V[i]), i));
		sort(ALL(V[i]));
		sz = SZ(V[i]);
		sum = 0;
		for(j = 0; j < sz; j++)
		{
			sum += V[i][j];
			SUM[i].push_back(sum);
		}
	}

	sort(ALL(Z));
	sort(ALL(T));

	for(i = SZ(T) - 1; i >= 0; i--)
	{
		M[T[i]] = i;
	}

	int cnt, id;

	cnt = 0;
	sum = 0;
	sz = SZ(V[0]);

	nBuckets = SZ(Z);
	for(i = 0; i < nBuckets; i++)
	{
		id = Z[i].second;
		if(Z[i].first >= sz && Z[i].first != 0) 
		{
			int xx = MIN(Z[i].first - sz + 1, Z[i].first);
			cnt += xx, sum += SUM[id][xx - 1];
			consumed[id] = xx;
		}

		for(j = consumed[id]; j < Z[i].first; j++)
			insert(V[id][j]);
	}

	int ans = 2000000000;
	for(i = SZ(V[0]); i <= n; i++)
	{
		int additional = i - sz;
		if(additional >= cnt)
		{
			int now = sum + query(additional - cnt);
			ans = MIN(ans, now);
		}
		else
			ans = MIN(ans, sum);

		if(i > 0)
		for(j = nBuckets - 1; j >= 0; j--)
		{
			id = Z[j].second;
			if(consumed[id] == 0) break;
			cnt--;
			sum -= V[Z[j].second][consumed[id] - 1];
			insert(V[Z[j].second][consumed[id] - 1]);
			consumed[id]--;
		}
	}

	printf("%d\n", ans);

	return 0;
}