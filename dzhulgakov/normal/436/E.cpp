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

#define N 333000
int n,w;
pair<PII,int> a[N];
set<PII> sel, cand;

#define BBB first
#define AAA second

void do_top1sel(int i)
{
}

PII getst(int i, int bot)
{
	if (i < bot)
		return PII(a[i].first.BBB - a[i].first.AAA, i);
	else
		return PII(a[i].first.AAA, i);
}

LL cursum;

void balance(int bot)
{
	while (bot + SZ(sel) < w)
	{
		if (cand.empty()) break;
		int i = cand.begin()->second;
		PII t = getst(i,bot);
		cand.erase(t);
		sel.insert(t);
		cursum += t.first;
	}
	while (bot + SZ(sel) > w)
	{
		if (sel.empty()) break;
		int i = sel.rbegin()->second;
		PII t = getst(i,bot);
		sel.erase(t);
		cand.insert(t);
		cursum -= t.first;
	}
	while (!sel.empty() && !cand.empty() && sel.rbegin()->first > cand.begin()->first)
	{
		PII t1 = *sel.rbegin();
		sel.erase(t1);
		PII t2 = *cand.begin();
		cand.erase(cand.begin());
		sel.insert(t2);
		cand.insert(t1);
		cursum += t2.first - t1.first;
	}
}

int main()
{
	//freopen("data.in","r",stdin);

	scanf("%d%d",&n,&w);
	REP(i,n)
	{
		scanf("%d%d",&a[i].first.AAA,&a[i].first.BBB);
		a[i].second = i;
	}
	sort(a,a+n);
	REP(i,n)
	{
		cand.insert(getst(i,0));
	}
	cursum = 0;
	LL best = 1LL<<62;
	int bestbot = -1;
	REP(bot,n+1)
	{
		balance(bot);
		if (bot+SZ(sel) == w)
		{
			if (cursum < best)
			{
				best = cursum;
				bestbot = bot;
			}
		}
		if (bot == n) break;
		PII oldst = getst(bot,bot);
		if (sel.count(oldst))
		{
			sel.erase(oldst);
			cursum -= oldst.first;
		}
		else
			cand.erase(oldst);
		PII newst = getst(bot,bot+1);
		cand.insert(newst);
		cursum += a[bot].first.AAA;
	}
	cout << best << endl;
	cursum = 0;
	VPII ccc;
	ccc.reserve(n);
	string ans(n,'0');
	REP(i,n)
	{
		if (i<bestbot)
		{
			cursum += a[i].first.AAA;
			ans[a[i].second] = '1';
		}
		ccc.push_back(getst(i,bestbot));
	}
	nth_element(ccc.begin(), ccc.begin()+(w-bestbot), ccc.end());
	REP(i,w-bestbot)
	{
		cursum += ccc[i].first;
		ans[a[ccc[i].second].second]++;
	}
	cout << ans << endl;
	if (cursum != best) fprintf(stderr,"BAD!\n");
	return 0;
}