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
typedef long long int LL;
//typedef __int64 LL;


int main()
{
	int n, R[20], M[20], cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &M[i]);
	for (int i = 0; i < n; i++) scanf("%d", &R[i]);
	//for (int i = 0; i < n; i++) scanf("%d %d", &M[i], &R[i]);
	for (int i = 0; i < 720720; i++) {
		int f = 0;
		for (int j = 0; j < n; j++) {
			if (i % M[j] == R[j]) f = 1;
		}
		cnt += f;
	}
	printf("%lf\n", cnt / 720720.);
	return 0;
}