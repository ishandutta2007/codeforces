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

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define SZ(V) (int)V.size()

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
//typedef __int64 LL;

char s[2000006];
char t[2000006];
int c00, c01, c10, c11;

int main()
{
	int n, i;

	scanf("%d", &n);

	scanf("%s%s", s, t);

	for(i = 0; i < 2*n; i++)
	{
		if(s[i]=='0' && t[i]=='0') c00++;
		if(s[i]=='0' && t[i]=='1') c01++;
		if(s[i]=='1' && t[i]=='0') c10++;
		if(s[i]=='1' && t[i]=='1') c11++;
	}

	if(c11%2==0)
	{
		if(c01 == c10 || c10 == c01-1) { printf("Draw\n"); return 0; }
		if(c10 > c01)  { printf("First\n"); return 0; }
		if(c10 < c01) { printf("Second\n"); return 0; }
	}

	if(c11%2)
	{
		if(c01==c10+2 || c01==c10+1) { printf("Draw\n"); return 0; }
		if(c01-1 < c10 ) { printf("First\n"); return 0; }
		{ printf("Second\n"); return 0; }
	}

	return 0;
}