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

LL n;
vector<int> V;
set<int> S;
set<int>::iterator iS;

int grundyNum[]={0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

void gen()
{
	LL i, num;

	V.push_back(1);
	for(i = 2; i*i <= n; i++)
	{
		for(num = i*i; num <= n; num*=i)
		{
			V.push_back( num );
			S.insert( num );
		}
	}

	sort(V.begin(), V.end());
}

LL solve()
{
	LL xor, i, cnt, j, num;

	if(n == 1) return 1;
	if(n == 2) return 0;
	if(n == 3) return 1;

	xor = 1;
	for(i = 2; i*i <= n; i++)
	{
		if(S.find(i)!=S.end()) continue;

		for(j = 1, num = i; num <= n; j++, num*=i);
		j--;

		xor ^= grundyNum[j];
	}

	cnt = n - i + 1;
	for(iS = S.begin(); iS!=S.end(); iS++)
		if(*iS >= i && *iS<=n)
			cnt--;

	if(cnt&1)
		xor ^= 1;

	return xor;
}

map<int, int> M;
int DP(int n, int mask)
{
	if(M.find(mask)!=M.end()) return M[mask];
	if(mask == (1<<n)-1) return 0;
	set<int> S;
	int i, nmask, j, g;

	for(i = 1; i <= n; i++)
		if(mask&(1<<(i-1)));
		else
		{
			nmask = mask;
			for(j = i; j <= n; j += i)
				nmask |= 1<<(j - 1);

			g = DP(n, nmask);
			S.insert(g);
		}

	for(i = 0;; i++)
		if(S.find(i)==S.end())
			return M[mask]  = i;
}

void genGrundy()
{
	int i;

	for(i = 2; i <= 30; i++)
	{
		M.clear();
		printf("%d: %d\n", i, DP(i, 0));
	}
}

int main()
{
	scanf("%I64d", &n);
//	n = 1000000000;

//	genGrundy();
	gen();
	LL ans = solve();

	if(ans) printf("Vasya\n");
	else printf("Petya\n");

	return 0;
}