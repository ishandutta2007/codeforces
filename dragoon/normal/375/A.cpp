#pragma warning(disable:4786)
#include<list>
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

int cnt[12];
char S[1000006];

int main()
{
	int len, i, j;

	scanf("%s", S);
	len = strlen(S);
	for(i = 0; i < len; i++)
		cnt[ S[i] - '0' ]++;

	cnt[1]--;
	cnt[6]--;
	cnt[8]--;
	cnt[9]--;

	int x = 0;
	for(i = 1; i <= 9; i++)
		for(j = 1; j <= cnt[i]; j++)
		{
			x = (x * 10 + i) % 7;
			printf("%d", i);
		}

	int num[] = {1, 6, 8, 9};

	do
	{
		int y = 0;
		for(i = 0; i < 4; i++) y = y * 10 + num[i];
		if( (x * 10000 + y) % 7 == 0 )
		{
			printf("%d%d%d%d", num[0], num[1], num[2], num[3]);
			break;
		}
	}while(next_permutation(num, num + 4));

	for(i = 1; i <= cnt[0]; i++) printf("0");
	printf("\n");

	return 0;
}