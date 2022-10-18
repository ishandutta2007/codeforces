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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

struct ANS
{
	int a, b, c;
	ANS(){}
	ANS(int x, int y, int z) { a=x; b = y; c = z;}
};

vector<ANS> V;
int cnt[100];

int main()
{
	int n, i, a;

	scanf("%d", &n);
	for(i = 0; i < n; i++) {scanf("%d", &a); cnt[a]++;}

	for(i = 1; i <= n/3; i++)
	{
		if(cnt[1] && cnt[3] && cnt[6]) 
		{
			cnt[1]--; cnt[3]--; cnt[6]--;
			V.push_back(ANS(1,3,6));
		}
		else if(cnt[1] && cnt[2] && cnt[6]) 
		{
			cnt[1]--; cnt[2]--; cnt[6]--;
			V.push_back(ANS(1,2,6));
		}
		else if(cnt[1] && cnt[2] && cnt[4]) 
		{
			cnt[1]--; cnt[2]--; cnt[4]--;
			V.push_back(ANS(1,2,4));
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}

	for(i = 0; i < n/3; i++)
		printf("%d %d %d\n", V[i].a, V[i].b, V[i].c);
	
	return 0;
}