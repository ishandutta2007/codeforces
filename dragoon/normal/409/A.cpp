#pragma warning(disable:4786)
#pragma warning(disable:4996)
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

int check(char ch)
{
	if(ch == '[') return 0; //paper
	if(ch == '(') return 1; //rock
	return 2; //scissor
}

int main()
{
	char S[100], T[100];
	int p1, p2, i, a, b;

	scanf("%s %s", S, T);
	p1 = p2 = 0;
	for(i = 0; S[i]; i += 2)
	{
		a = check(S[i]);
		b = check(T[i]);

		if(a == 0 && b == 1) p1++;
		else if(a == 1 && b == 2) p1++;
		else if(a == 2 && b == 0) p1++;

		if(b == 0 && a == 1) p2++;
		else if(b == 1 && a == 2) p2++;
		else if(b == 2 && a == 0) p2++;
	}

	if(p1 == p2) printf("TIE\n");
	else if(p1 > p2) printf("TEAM 1 WINS\n");
	else printf("TEAM 2 WINS\n");

	return 0;
}