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

int a[100005];
int g[100005 * 4];
VI V[100005];
map<int, int> M;

int gcd(int a, int b)
{
	if(a % b == 0) return b;
	return gcd(b, a % b);
}

void gen(int at, int l, int r)
{
	if(l == r)
	{
		g[at] = a[l];
		return;
	}
	int m = (l + r) / 2;
	gen(at * 2, l, m);
	gen(at * 2 + 1, m + 1, r);
	g[at] = gcd(g[at * 2], g[at * 2 + 1]);
}

int query(int at, int l, int r, int x, int y)
{
	if(x <= l && r <= y) return g[at];
	if(r < x || y < l) return 0;
	int m = (l + r) / 2;
	int a = query(at * 2, l, m, x, y);
	int b = query(at * 2 + 1, m + 1, r, x, y);
	if(!a) return b;
	if(!b) return a;
	return gcd(a, b);	
}

int main()
{
	int n, i, t,p,q;
	scanf("%d", &n);
	int id = 0;
	FORN(i, n) 
	{
		scanf("%d", &a[i]);
		if(M.find(a[i]) == M.end()) M[a[i]] = id++;
		V[M[a[i]]].push_back(i);
	}
	gen(1, 0, n - 1);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &p, &q);
		p--, q--;
		int num = query(1, 0, n - 1, p, q);
		int ans = 0;
		if(M.find(num) == M.end()) ans = 0;
		else
		{
			int id = M[num];
			ans = upper_bound(ALL(V[id]), q) - lower_bound(ALL(V[id]), p);
		}

		printf("%d\n", q - p + 1 - ans);
	}
	return 0;
}