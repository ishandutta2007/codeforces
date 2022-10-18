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

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
typedef __int64 LL;

vector<int> Prime;
char mark[10000002];

void sieve(int n)
{
	int i,j,limit=sqrt(n*1.)+2;

	mark[1] = 1;
	for(i=4;i<=n;i+=2) mark[i]=1;

	Prime.push_back(2);
	for(i=3;i<=n;i+=2)
		if(!mark[i])
		{
			Prime.push_back(i);

			if(i<=limit)
			{
				for(j=i*i;j<=n;j+=i*2)
				{
					mark[j] = 1;
				}
			}
		}
}

int V[1000006];
LL cnt_prime[10000007];
LL ans[10000007];
int n;

int check(LL x)
{
	int i;
	LL temp, cnt;
	int sz = Prime.size();

	for(i = 0; i < sz; i++)
	{
		if(Prime[i] > V[n - 1])
			break;

		cnt = 0;
		temp = x;
		while(temp)
		{
			cnt += temp/Prime[i];
			temp /= Prime[i];
		}

		if(cnt < cnt_prime[Prime[i]])
			return 0;
	}

	return 1;
}

int pos[20000007];
int main()
{
	LL lo, hi = 0, mid, now;
	int i, p, at, a, sz, ii;

	sieve(10000000);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
//		a = 10000000;
		scanf("%d", &a);
		pos[a]++;
		V[i] = a;
		hi += a;
	}

	for(i = 1; i <= 20000000; i++)
		pos[i] += pos[i-1];

	sort(V, V + n);

	sz = Prime.size();
	for(ii = 0; ii < sz; ii++)
	{
		p = Prime[ii];
//		printf("%d\n", p);

		if( p > V[n-1] )
			break;

		ans[0] = 0;

		for(i = p; i <= 10000000; i += p)
		{
			if(i > V[n-1])
				break;
//			if(i%100000==0)
//			printf(">>>%d\n", i);
			ans[i] = i/p + ans[ ((i/p)/p)*p ];
			now = pos[i+p-1] - pos[i-1];
			cnt_prime[p] += ans[i]*now;
		}
	}

	lo = V[n-1];
	while( lo < hi )
	{
		mid = (lo + hi)/2;

//		printf("%I64d %I64d\n", lo, hi);
		if(check(mid)) hi = mid;
		else lo = mid + 1;
	}

	printf("%I64d\n", lo);
	
	return 0;
}