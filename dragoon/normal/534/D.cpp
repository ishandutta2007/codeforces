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

int n;
int cnt[200005];
stack<int> S[200005];

int main()
{
	scanf("%d", &n);

	int num;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		S[num].push(i + 1);
		cnt[num]++;
	}

	int sz = -1;
	VI V;
	while (1)
	{
		if (cnt[sz + 1] > 0) {
			V.push_back(S[sz + 1].top());
			S[sz + 1].pop();
			cnt[sz + 1]--;
			sz++;
		}
		else {
			if (sz < 2) break;
			sz -= 3;
		}
	}
	if (SZ(V) != n) {
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	for (int j = 0; j < SZ(V); j++) {
		if (j) printf(" ");
		printf("%d", V[j]);
	}
	printf("\n");
	return 0;

	return 0;
}