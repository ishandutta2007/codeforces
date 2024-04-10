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

const int points[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
struct Player
{
	int sum;
	int ps[100];
	string name;
	Player()
	{
		sum=0;
		CLEAR(ps);
	}
};

int n,t;
map<string,Player> a;

bool gr1(Player a, Player b)
{
	if (a.sum != b.sum) return a.sum > b.sum;
	FOR(i,0,99)
		if (a.ps[i]!=b.ps[i])
			return a.ps[i]>b.ps[i];
	return false;
}

bool gr2(Player a, Player b)
{
	if (a.ps[0]!=b.ps[0])
		return a.ps[0]>b.ps[0];
	if (a.sum != b.sum) return a.sum > b.sum;
	FOR(i,1,99)
		if (a.ps[i]!=b.ps[i])
			return a.ps[i]>b.ps[i];
	return false;
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&t);
	REP(test,t)
	{
		scanf("%d",&n);
		REP(i,n)
		{
			char buf[256];
			scanf("%s",buf);
			string s = string(buf);
			Player &p = a[s];
			if (i<10)
				p.sum += points[i];
			p.ps[i]++;
			p.name = s;
		}
	}
	Player r1 = a.begin()->second, r2 = a.begin()->second;
	for (map<string,Player>::iterator it = a.begin(); it != a.end(); it++)
	{
		if (gr1(it->second, r1)) r1=it->second;
		if (gr2(it->second, r2)) r2=it->second;
	}
	printf("%s\n%s\n",r1.name.data(),r2.name.data());
	return 0;
}