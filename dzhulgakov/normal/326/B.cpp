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

#define N 111000
#define NN 2700
#define LEN 100
int n;
char a[N];
int d[NN][NN],prv[NN][NN];

int main()
{
	//freopen("pal.in","r",stdin);
	//freopen(".out","w",stdout);

	gets(a);
	n=strlen(a);
	if (n>26*LEN)
	{
		int x[26];
		CLEAR(x);
		REP(i,n) ++x[a[i]-'a'];
		REP(i,26) if (x[i]>=LEN)
		{
			REP(j,LEN) printf("%c",'a'+i);
			break;
		}
		printf("\n");
		return 0;
	}
	CLEAR(d);
	FILL(prv,-1);
	REP(j,n) REPD(i,j+1)
	{
		if (i==j)
		{
			d[i][j] = 1;
			prv[i][j] = -1;
			continue;
		}
		d[i][j] = (i==j-1?0:d[i+1][j-1])+(a[i]==a[j]?2:0);
		prv[i][j] = a[i]==a[j]?1:0;
		if (d[i+1][j] > d[i][j])
		{
			d[i][j] = d[i+1][j];
			prv[i][j] = 2;
		}
		if (d[i][j-1] > d[i][j])
		{
			d[i][j] = d[i][j-1];
			prv[i][j] = 3;
		}
	}
	int best[2] = {0};
	int xi[2]={-1,-1},xj[2]={-1,-1};
	REP(j,n) REPD(i,j+1)
	{
		int val = d[i][j];
		if (val > LEN+1) continue;
		int md = val%2;
		if (val > best[md])
		{
			best[md] = val;
			xi[md]=i;
			xj[md]=j;
		}
	}
	string res="";
	REP(md,2) if (best[md]>SZ(res))
	{
		string s1 = "";
		string s2 = "";
		for (int i = xi[md], j = xj[md]; i<=j; )
		{
			int id = prv[i][j];
			if (id == -1)
			{
				if (i==j) s1.push_back(a[i]);
				break;
			}
			if (id == 1)
			{
				s1.push_back(a[i]);
				s2 = string(1,a[j])+s2;
			}
			if (id <= 1)
			{
				++i,--j;
			}
			else if (id == 2)
				++i;
			else
				--j;
		}
		res = s1+s2;
		if (SZ(res) != best[md])
			fprintf(stderr,"BAD!\n");
	}
	if (SZ(res) > LEN)
	{
		res.erase(res.begin()+LEN/2);
	}
	printf("%s\n",res.c_str());
	return 0;
}