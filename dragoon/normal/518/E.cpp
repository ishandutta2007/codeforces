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
typedef __int64 LL;

int num[100005];
char word[20];
int pos;

void refine(VI &V, int i, int j, LL valI, LL valJ)
{
	if(valJ - valI - 1 < j - i + 1)
	{
		pos = 0;
		return;
	}

	int imp = 0;
	int mid = (i + j) / 2;
	for(int z = i; z <= j; z++)
	{
		int f = z - mid;
		if(valI < f && f < valJ);
		else imp = 1;
		V[z] = f;
	}

	if(!imp) return;

	if((j - i + 1) % 2 == 0)
	{
		mid = mid + 1;
		for(int z = i; z <= j; z++)
		{
			int f = z - mid;
			if(valI < f && f < valJ);
			else imp = 1;
			V[z] = f;
		}
		if(!imp) return;
	}

	LL sum[2];

	sum[0] = 0;
	for(int z = i; z <= j; z++)
	{
		sum[0] += ABS(valI + 1 + (z - i));
	}

	sum[1] = 0;
	for(int z = i; z <= j; z++)
	{
		sum[1] += ABS(valJ - 1 - (j - z));
	}

	for(int z = i; z <= j; z++)
	{
		if(sum[0] < sum[1])
			V[z] = valI + 1 + (z - i);
		else
			V[z] = valJ - 1 - (j - z);
	}
}

VI find(VI V)
{
	VI ans = V;
	int sz = SZ(V);
	int lastId = -1;
	int lastValue = -2000000000;
	for(int i = 0; i < sz; i++)
	{
		if(V[i] == 2000000000) continue;
		if(lastId != i - 1)
		{
			refine(ans, lastId + 1, i - 1, lastValue, V[i]);
		}
		if(lastValue >= V[i])
			pos = 0;
		lastId = i;
		lastValue = V[i];
	}
	if(lastId != sz - 1)
	{
		refine(ans, lastId + 1, sz - 1, lastValue, 2000000000);
	}
	return ans;
}

int main()
{
	int i, k, n, j, p;

	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
	{
		scanf("%s", word);
		if(strcmp(word, "?") == 0) num[i] = 2000000000;
		else sscanf(word, "%d", &num[i]);
	}

	pos = 1;
	for(i = 0; i < k; i++)
	{
		VI V;
		for(j = i; j < n; j += k) V.push_back(num[j]);
		V = find(V);
		for(j = i, p = 0; j < n; j += k, p++) num[j] = V[p];
	}

	if(pos == 0)
	{
		printf("Incorrect sequence\n");
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			if(i) printf(" ");
			printf("%d", num[i]);
		}
		printf("\n");
	}

	return 0;
}