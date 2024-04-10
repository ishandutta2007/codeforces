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

int n;
int dig[10];
int allow;
int s[25];

int len;
vector<LL> ans;

void solve(int p, int num, LL ip)
{
	if (len-p > 3*(4-num)) return;
	if (num == 4)
	{
		if (p==len)
			ans.pb(ip);
		return;
	}
	int x = 0;
	REP(i,3)
	{
		if (p+i >= len) continue;
		if (i>0 && x==0) continue;
		x = x*10 + s[p+i];
		if (x>255) continue;
		solve(p+i+1, num+1, ip*256LL + x);
	}
}

void check(int k)
{
	if (k==12 && s[0]>2) return;
	len = k;
	solve(0,0,0);
}

void go(int p, int u)
{
	if (u == allow)
	{
		REP(i,p-1)
			s[2*p-2-i] = s[i];
		check(2*p-1);
		REP(i,p)
			s[2*p-1-i] = s[i];
		check(2*p);
	}
	if (p>=6)
		return;
	REP(i,n)
	{
		s[p] = dig[i];
		go(p+1, u | (1<<dig[i]));
	}
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	allow=0;
	REP(i,n) 
	{
		scanf("%d",dig+i);
		allow |= 1<<dig[i];
	}
	go(0,0);
	printf("%d\n",SZ(ans));
	//SORT(ans);
	REP(ii,SZ(ans))
	{
			REPD(i,4)
			{
				printf("%d",(int)((ans[ii]>>(i*8))&0xff));
				if (i)printf(".");
			}
			printf("\n");
	}
	return 0;
}