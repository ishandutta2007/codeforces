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


int n;
char word[105][105];
VI V[30];
int in[500];

int main()
{
	int i, j;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", word[i]);
	}

	int imp = 0;
	for(i = 0; i + 1 < n; i++)
	{
		for(j = 0; ; j++)
		{
			if(word[i][j] == 0) break;
			if(word[i + 1][j] == 0) {imp = 1; break;}
			if(word[i][j] == word[i + 1][j]) continue;
			V[word[i][j] - 'a'].push_back(word[i + 1][j] - 'a');
			in[word[i + 1][j] - 'a']++;
			break;
		}
	}

	if(imp) 
	{
		printf("Impossible\n");
		return 0;
	}

	queue<int> Q;
	for(i = 0; i < 26; i++)
		if(in[i] == 0)
			Q.push(i);

	char ans[40];
	ans[26] = 0;
	int now = 0;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		ans[now++] = u + 'a';
		for(i = SZ(V[u]) - 1; i >= 0; i--)
		{
			in[V[u][i]]--;
			if(in[V[u][i]]==0)
				Q.push(V[u][i]);
		}
	}

	if(now != 26)
	{
		printf("Impossible\n");
		return 0;
	}

	printf("%s\n", ans);

	return 0;
}