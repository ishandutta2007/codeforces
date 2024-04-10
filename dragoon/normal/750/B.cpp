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

int ok() {
	int n;
	scanf("%d", &n);
	int at = 0;
	for (int i = 1; i <= n; i++) {
		int t; char dir[100];
		scanf("%d %s", &t, dir);

		if (dir[0] == 'N') {
			if (at == 0) return 0;
			at -= t;
			if (at < 0) return 0;
		}
		else if (dir[0] == 'S') {
			if (at == 20000) return 0;
			at += t;
			if (at > 20000) return 0;
		}
		else if (dir[0] == 'E') {
			if (at == 0 || at == 20000) return 0;
		}
		else if (dir[0] == 'W') {
			if (at == 0 || at == 20000) return 0;
		}
	}
	return at == 0;
}

int main()
{
	if (ok()) printf("YES\n");
	else printf("NO\n");
	return 0;
}