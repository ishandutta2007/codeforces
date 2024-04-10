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

#define N 11000
int k,n;
int res[22][N];

void verify()
{
	static int a[N],b[N];
	REP(i,n) a[i]=1;
	a[n]=0;
	REP(i,k) {
		FOR(j,1,n)
		{
			int id = res[i][j-1];
			assert(1 <= id && id <= n);
			b[j] = a[id];
		}
		FOR(j,1,n) a[j]+=b[j];
	}
	FOR(i,1,n) assert(a[i]==n-i);
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&k);

	REP(j,k) REP(i,n) res[j][i] = (n-i-1-(i+1<n?1:0))&(1<<j) ? n-(1<<j) : n;

	REP(i,k) {
		REP(j,n) printf(" %d"+(j==0), res[i][j]);
		printf("\n");
	}

	//verify();
	return 0;
}