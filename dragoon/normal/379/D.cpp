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
typedef __int64 LL;

LL start[100], EnD[100], cnt[100];

void PRINT(int a)
{
	if(a == 0) printf("A");
	if(a == 1) printf("C");
	if(a == 2) printf("X");
}

int possible(int len, int start, int end, int cnt, int isprint)
{
	int i;

	if(len == 1)
	{
		if(start != end || cnt > 0) return 0;
		if(isprint)
		{
			if(start == 0) printf("A");
			else if(start == 1) printf("C");
			else printf("X");
		}
		return 1;
	}

	if((start == 2 && (end == 2 || end == 0)) || (start == 1 && (end == 0 || end == 2)))
	{
		if(cnt > (len - 2)/2) return 0;
		if(isprint)
		{
			PRINT(start);
			for(i = 1; i <= cnt; i++) printf("AC");
			for(i = 2*cnt + 1; i <= len - 2; i++) printf("X");
			PRINT(end);
		}
		return 1;
	}

	if((start == 2 && end == 1) || (start == 1 && end == 1))
	{
		if( (len - 2)%2 == 0 && cnt > (len - 2)/2) return 0;
		if( (len - 2)%2 == 1 && cnt > (len - 2 + 1)/2) return 0;

		if(isprint)
		{
			PRINT(start);
			if(cnt == 0)
			{
				for(i = 1; i <= len - 2; i++) printf("X");
			}
			else
			{

				for(i = 1; i < cnt; i++) printf("AC");
				if(cnt*2 > (len - 2)) printf("A");
				else 
				{
					printf("AC");
					for(i = 2*cnt + 1; i <= len - 2; i++) printf("X");
				}
			}
			PRINT(end);
		}
		return 1;
	}

	if(start == 0 && (end == 0 || end == 2))
	{
		if( (len - 2)%2 == 0 && cnt > (len - 2)/2) return 0;
		if( (len - 2)%2 == 1 && cnt > (len - 2 + 1)/2) return 0;

		if(isprint)
		{
			PRINT(start);
			if(cnt) 
			{
				printf("C");
				for(i = 2; i <= cnt; i++) printf("AC");
				for(i = 2*(cnt - 1) + 2; i <= len - 2; i++) printf("X");
				PRINT(end);
			}
			else
			{
				for(i = 1; i <= len - 2; i++) printf("X");
				PRINT(end);
			}
		}
		return 1;
	}

	if(start == 0 && end == 1)
	{
		if(len == 2 && cnt == 0) return 0;
		if(cnt > len/2) return 0;

		if(isprint)
		{
			if(len == 2 && cnt == 1)
			{
				printf("AC");
				return 1;
			}

			if(cnt == 0)
			{
				printf("A");
				for(i = 1; i <= len - 2; i++) printf("X");
				printf("C");
			}
			else
			{
				for(i = 1; i <= cnt; i++) printf("AC");
				for(i = 2*cnt + 1; i <= len - 1; i++) printf("X");
				if(cnt*2 != len) printf("C");
			}
		}
		return 1;
	}

}

int main()
{
	int i, a, b, y, c1, z, c2;
	LL k, x, n, m;

	scanf("%I64d %I64d %I64d %I64d", &k, &x, &n, &m);
	for(a = 0; a <= 2; a++) for(y = 0; y <= 2; y++) for(c1 = 0; c1 <= n/2; c1++)
		for(b = 0; b <= 2; b++) for(z = 0; z <= 2; z++) for(c2 = 0; c2 <= m/2; c2++)
		{
			start[0] = a;
			EnD[0] = y;
			cnt[0] = c1;

			start[1] = b;
			EnD[1] = z;
			cnt[1] = c2;

			for(i = 2; i < k; i++)
			{
				start[i] = start[i - 2];
				EnD[i]   = EnD[i - 1];
				cnt[i]   = cnt[i - 2] + cnt[i - 1] + (EnD[i - 2] == 0 && start[i - 1] == 1);
			}

			if(cnt[k - 1] == x)
			{
				if(possible(n, a, y, c1, 0) && possible(m, b, z, c2, 0))
				{
					possible(n, a, y, c1, 1); 
					printf("\n");
					possible(m, b, z, c2, 1);
					printf("\n");
					return 0;
				}
			}
		}

		printf("Happy new year!\n");

	return 0;
}