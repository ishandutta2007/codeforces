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

int n, c;
int A[100], B[100], C[100];
VI V;
int imp = 0;
int Left[105], Right[105];

int solve(int a, int b)
{
	if(a > b) return -1;

	if(a == b)
	{
		Left[a] = Right[a] = -1;
		return a;
	}

	int root = a;

	for(int i = a; i <= b; i++) //(a + 1 .. i) in Left side, (i + 1 .. b) Right side. any can be empty.
	{
		int now = 1;

		for(int j = 0; j < c; j++)
		{
			if(A[j] == root)
			{
				if(C[j] == 0 && !IN(B[j], a + 1, i))
					now = 0;
				if(C[j] == 1 && !IN(B[j], i + 1, b))
					now = 0;
			}
			else if(IN(A[j], a + 1, i) && IN(B[j], i + 1, b))
				now = 0;
		}
		if(now == 0) continue;
		int x = solve(a + 1, i);
		int y = solve(i + 1, b);
		Left[root] = x;
		Right[root] = y;

		return root;
	}
	imp = 1;
	return -1;
}

void inorder(int at)
{
	if(at == -1) return;
	inorder(Left[at]);
	V.push_back(at);
	inorder(Right[at]);
}

int main()
{
	int i;
	char word[100];

	scanf("%d %d", &n, &c);
	for(i = 0; i < c; i++)
	{
		scanf("%d %d %s", &A[i], &B[i], word);
		imp |= A[i] >= B[i];
		C[i] = (strcmp(word, "RIGHT") == 0);
	}

	solve(1, n);

	if(imp) 
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}

	inorder(1);

	for(i = 0; i < n; i++)
	{
		if(i) printf(" ");
		printf("%d", V[i]);
	}
	printf("\n");
	
	
	return 0;
}