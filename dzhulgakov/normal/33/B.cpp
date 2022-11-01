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
#define INF 1000000000
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

int n;
int d[26][26];
char s1[111000];
char s2[111000];

int main()
{
	gets(s1);
	gets(s2);
	scanf("%d",&n);
	REP(i,26) REP(j,26) d[i][j] = i==j?0:INF;
	REP(i,n)
	{
		char c1,c2;
		do c1 = getc(stdin); while (!isalpha(c1));
		do c2 = getc(stdin); while (!isalpha(c2));
		int w;
		scanf("%d",&w);
		d[c1-'a'][c2-'a'] = min(w, d[c1-'a'][c2-'a']);
	}
	REP(k,26) REP(i,26) REP(j,26) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	int len = strlen(s1);
	int len2 = strlen(s2);
	if (len!=len2) {
			printf("-1\n");
			return 0;
	}
	LL res = 0;
	REP(i,len)
	{
		int w = INF;
		char ch = 0;
		REP(j,26)
			if (d[s1[i]-'a'][j]+d[s2[i]-'a'][j] < w)
			{
				w = d[s1[i]-'a'][j]+d[s2[i]-'a'][j];
				ch = 'a'+j;
			}
		if (w==INF)
		{
			printf("-1\n");
			return 0;
		}
		res += w;
		s1[i] = ch;
	}
	printf("%lld\n%s\n",res,s1);
	return 0;
}