#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <bitset>
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

#define N 256
int n,k;
typedef bitset<N> BS;
BS a[N*N];
BS total;
VI in[N];

void print(const BS& a)
{
	printf("%d",a.count());
	REP(i,N) if (a[i]) printf(" %d",i);
	printf("\n");
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	k=n*(n-1)/2;
	REP(i,k)
	{
		int cnt;
		scanf("%d",&cnt);
		REP(j,cnt)
		{
			int x;
			scanf("%d",&x);
			total.set(x);
			a[i].set(x);
			in[x].pb(i);
		}
	}
	REP(start,N) if (total[start])
	{
		BS s1;
		s1.set();
		REP(i,SZ(in[start]))
			s1 &= a[in[start][i]];
		if (n==2) {
			s1.reset();
			s1.set(start);
		}
		print(s1);
		REP(i,SZ(in[start]))
			print(s1 ^ a[in[start][i]]);
		return 0;
	}
	return 0;
}