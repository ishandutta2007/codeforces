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

int num1[100015], num2[100015];
char s1[100005], s2[100005];
int len, now, i;

int main()
{
	scanf("%s", s1);
	scanf("%s", s2);

	CLR(num1);
	CLR(num2);

	len = strlen(s1);
	for(i = 0; i < len; i++)
		num1[i] = s1[len - i - 1] - '0';
	len = strlen(s2);
	for(i = 0; i < len; i++)
		num2[i] = s2[len - i - 1] - '0';

	stack<int> S;
	for(i = 100004; i >= 0; i--)
	{
		if(num1[i] == 1)
		{
			now = i;
			if(S.empty()) S.push(now);
			else
			{
				while(!S.empty() && S.top() == now + 1)
				{
					S.pop();
					now = now + 2;
				}
				S.push(now);
			}
		}
	}

	CLR(num1);
	while(!S.empty())
	{
		int x = S.top();
		num1[S.top()] = 1;
		S.pop();
	}

	for(i = 100004; i >= 0; i--)
	{
		if(num2[i] == 1)
		{
			now = i;
			if(S.empty()) S.push(now);
			else
			{
				while(!S.empty() && S.top() == now + 1)
				{
					S.pop();
					now = now + 2;
				}
				S.push(now);
			}
		}
	}

	CLR(num2);
	while(!S.empty())
	{
		num2[S.top()] = 1; S.pop();
	}

	for(i = 100004; i >= 0; i--)
		if(num1[i] != num2[i])
			break;

	if(i == -1) printf("=\n");
	else if(num1[i] > num2[i]) printf(">\n");
	else printf("<\n");


	return 0;
}