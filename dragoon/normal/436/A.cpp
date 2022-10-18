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

int solve(VP A, VP B, int init)
{
	priority_queue<int> PA, PB;
	int ret = 0;
	int cur = init;

	int i = 0, j = 0, z;
	while(1)
	{
		for(; i < SZ(A); i++)
			if(A[i].first <= cur)
			{
				PA.push(A[i].second);
			}
			else
			{
				break;
			}

		if(PA.empty()) return ret;
		z = PA.top(); PA.pop();
		cur += z;
		ret++;

		for(; j < SZ(B); j++)
			if(B[j].first <= cur)
			{
				PB.push(B[j].second);
			}
			else
			{
				break;
			}

		if(PB.empty()) return ret;
		z = PB.top(); PB.pop();
		cur += z;
		ret++;
	}

	return ret;
}

bool cmp(PII A, PII B)
{
	if(A.first != B.first) return A.first < B.first;
	return A.second > B.second;
}

int main()
{
	int i, n, x;
	VP A, B;
	int t, h, m;
	int ans1, ans2;
	
	scanf("%d %d", &n, &x);
	FORN(i, n)
	{
		scanf("%d %d %d", &t, &h, &m);
		if(t == 0) A.push_back(PII(h, m));
		else B.push_back(PII(h, m));
	}

	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end(), cmp);

	ans1 = solve(A, B, x);
	ans2 = solve(B, A, x);

	printf("%d\n", MAX(ans1, ans2));

	return 0;
}