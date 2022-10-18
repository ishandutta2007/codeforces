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

char S[100];

int main()
{
	scanf("%s", S);
	int len = strlen(S);
	char ch = S[len - 1];
	S[len - 1] = 0;
	LL row;
	sscanf(S, "%I64d", &row);

	int col = ch - 'a';

	row--;

	LL ans = 0;
	ans = (row / 4) * 2 * 6;
	ans += (row / 4) * 4;
	row %= 4;
	if (row == 1 || row == 3) ans += 6;
	if (row == 1 || row == 3) ans++;

	if (col == 5) ans++;
	else if (col == 4) ans += 2;
	else if (col == 3) ans += 3;
	else if (col == 0) ans += 4;
	else if (col == 1) ans += 5;
	else ans += 6;

	printf("%I64d\n", ans);

	return 0;
}