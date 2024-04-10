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

int w[402][402];
int r, c;
char R[30], C[30];

inline int okay(int i, int j)
{
	return i >= 0 && j >= 0 && i < r && j < c;
}

inline int node(int i, int j)
{
	return i * c + j;
}

int main()
{
	int ni, nj;

	scanf("%d %d", &r, &c);
	scanf("%s %s", R, C);
	
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			ni = i + 1; nj = j;
			if(okay(ni, nj)) w[node(i, j)][node(ni, nj)] = (C[j] == 'v');

			ni = i - 1; nj = j;
			if(okay(ni, nj)) w[node(i, j)][node(ni, nj)] = (C[j] == '^');

			ni = i; nj = j + 1;
			if(okay(ni, nj)) w[node(i, j)][node(ni, nj)] = (R[i] == '>');

			ni = i; nj = j - 1;
			if(okay(ni, nj)) w[node(i, j)][node(ni, nj)] = (R[i] == '<');
		}

	int N = r * c;
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				w[i][j] |= (w[i][k]&w[k][j]);

	int flag = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if(w[i][j] == 0 && i != j)
				flag = 1;

	if(flag) printf("NO\n");
	else printf("YES\n");
	return 0;
}