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

struct T
{
	int id,v,c,l,r,sum,prev;
	void read(int ii)
	{
		id=ii;
		scanf("%d%d%d%d",&v,&c,&l,&r);
	}
	int total()
	{
		return c+l+r;
	}
};

int n;
map<int,vector<T> > gr;
VI ans;
int res;
map<int,PII> d;

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d",&n);
	REP(i,n)
	{
		T x;
		x.read(i);
		gr[x.total()].pb(x);
	}
	res=0;
	for (map<int,vector<T> >::iterator git = gr.begin(); git != gr.end(); ++git)
	{
		vector<T>& a = git->second;
		d.clear();
		d[0]=PII(0,-1);
		int n = SZ(a);
		REP(i,n)
		{
			map<int,PII>::iterator it = d.find(a[i].l);
			if (it == d.end()) continue;
			a[i].prev = it->second.second;
			int newcost = it->second.first + a[i].v;
			map<int,PII>::iterator it2 = d.find(a[i].l+a[i].c);
			if (it2 == d.end() || it2->second.first < newcost)
			{
				d[a[i].l+a[i].c] = PII(newcost, i);
			}
		}
		int total = git->first;
		if (d.count(total) == 0) continue;
		if (d[total].first <= res) continue;
		res = d[total].first;
		int last = d[total].second;
		ans.clear();
		for (; last!=-1; last = a[last].prev)
			ans.pb(a[last].id);
		reverse(ALL(ans));
	}
	printf("%d\n",SZ(ans));
	REP(i,SZ(ans))
		printf(" %d"+(i==0),ans[i]+1);
	printf("\n");
	return 0;
}