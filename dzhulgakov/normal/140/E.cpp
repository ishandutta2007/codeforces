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

int n,m,p;
int d[2][5555];
LL fact[1024000],mfact[1024000];
int w[5555][5555];

int main()
{
	//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
	CLEAR(d);
	int cur = 0;
	d[cur][0] = 1;
	int lprev = 0;
	CLEAR(w);
	w[0][0]=1;
	REP(i,5100) FOR(j,0,i)
	{
		if (j) w[i+1][j] = (w[i+1][j]+(j-1)*(LL)w[i][j])%p;
		w[i+1][j+1] = (w[i+1][j+1]+(LL)w[i][j])%p;
	}
	fact[0]=1;
	mfact[0]=1;
	FOR(i,1,m)
	{
		fact[i]=(fact[i-1]*(LL)i)%p;
		mfact[i]=(mfact[i-1]*(LL)(m+1-i))%p;
	}
	REP(step,n)
	{
		CLEAR(d[cur^1]);
		LL sum = 0;
		FOR(i,0,lprev) sum += d[cur][i];
		sum%=p;
		int lcur;
		scanf("%d",&lcur);
		FOR(i,1,lcur)
		{
			LL k = (sum*(LL)mfact[i])%p;
			k = (k-(d[cur][i]*(LL)fact[i])%p+(LL)p)%p;
			d[cur^1][i] = (d[cur^1][i] + k*(LL)w[lcur][i])%p;
		}
		lprev=lcur;
		cur^=1;
	}
	LL res = 0;
	REP(i,5555) res += d[cur][i];
	res %= p;
	res += p;
	res %= p;
	printf("%d\n",(int)res);
	return 0;
}