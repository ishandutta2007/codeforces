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

double Prob(int type, int score, int Left, int Right)
{
	if(type == 0)
	{
		if(Right <= score) return 0.0;
		else if(score < Left) return 1.0;
		return (Right - score) / (Right - Left + 1.);
	}
	
	if(type == 1)
	{
		if(score < Left || score > Right) return 0.0;
		return 1. / (Right - Left + 1.);
	}

	if(type == 2)
	{
		if(Left >= score) return 0.0;
		else if(Right < score) return 1.0;
		return (score - Left) / (Right - Left + 1.);
	}

	return 0.0;
}

double prob[10][4];
int cnt[10];
int n;
int L[10], R[10];
double ans;

void bktk(int at, double p, int score)
{
	if(at == n + 1)
	{
		if(cnt[0] >= 2 || cnt[0] + cnt[1] < 2) return;
		ans += p * score;
		return;
	}

	for(int i = 0; i < 3; i++)
	{
		cnt[i]++;
		bktk(at + 1, p * prob[at][i], score);
		cnt[i]--;
	}
}

int main()
{
	int i, j, k;

	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &L[i], &R[i]);
	}

	ans = 0;
	for(i = 1; i <= 10000; i++)
	{
		for(j = 1; j <= n; j++)
		{
			for(k = 0; k < 3; k++)
				prob[j][k] = Prob(k, i, L[j], R[j]);
		}
		bktk(1, 1.0, i);
	}

	printf("%.10lf\n", ans);
	return 0;
}