#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

int res;
set<pair<PII,PII> > mem[30];

int fst(int h, int l, int r)
{
	int p = (l>>h)<<h;
	while (p < l) p+=(1<<h);
	if (p <= r) return p;
	return -1;
}

void go(int h, int l1, int r1, int l2, int r2)
{
	if (h<0) return;
	if (l1 > r1 || l2 > r2) return;
	//assert((l1 >> (h+1)) == (r1 >> (h+1)));
	//assert((l2 >> (h+1)) == (r2 >> (h+1)));
	l1 %= 1<<(h+1);
	r1 %= 1<<(h+1);
	l2 %= 1<<(h+1);
	r2 %= 1<<(h+1);
	if (l1 > l2 || l1 == l2 && r1 > r2)
	{
		swap(l1,l2);
		swap(r1,r2);
	}
	if (mem[h].count(MP(PII(l1,r1),PII(l2,r2)))) return;
	mem[h].insert(MP(PII(l1,r1),PII(l2,r2)));
	int p1 = fst(h,l1,r1);
	int p2 = fst(h,l2,r2);
	if (p1 == -1)
		if (p2 == -1)
			go(h-1,l1,r1, l2,r2);
		else
		{
			go(h-1,l1,r1, l2,p2-1);
			go(h-1,l1,r1, p2+1,r2);
		}
	else
		if (p2 == -1)
		{
			go(h-1,l1,p1-1, l2,r2);
			go(h-1,p1+1,r1, l2,r2);
		}
		else
		{
			go(h-1,l1,p1-1, l2,p2-1);
			go(h-1,p1+1,r1, l2,p2-1);
			go(h-1,l1,p1-1, p2+1,r2);
			go(h-1,p1+1,r1, p2+1,r2);
			res = max(res, min(r1-p1, r2-p2)-max(l1-p1, l2-p2)+1);
		}
}

int main()
{
	//freopen(".in","r",stdin);

	int l1,r1,l2,r2;
	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
	res = 0;
	go(29,l1,r1,l2,r2);
	printf("%d\n",res);
	return 0;
}