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
int n;
LL k;
vector<LL> happy;
LL minsize;
pair<LL,LL> brd[N];

struct Tracker
{
	int sign;
	LL arr[N];
	LL pos;
	LL deriv,sum;
	double r_sum;
	int id;
	void make(int s)
	{
		sign = s;
		pos=0;
		sum=0;
		r_sum=0;
		deriv=0;
		if (sign > 0)
		{
			REP(i,n)
			{
				deriv -= 1;
				sum += arr[i];
				r_sum += arr[i];
			}
		}
		id = 0;
	}
	void advance(LL x)
	{
		while (pos < x || id < n && arr[id] <= x)
		{
			LL npos = min(x,arr[id]);
			if (id == n) npos = x;
			sum += deriv*(npos-pos);
			r_sum += deriv*(double)(npos-pos);
			while (id < n && arr[id] <= npos)
			{
				++deriv;
				++id;
			}
			pos = npos;
		}
	}
} bl,br;

int main()
{
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(0);
	FOR(len,1,18) REP(mask,1<<len)
	{
		LL x = 0;
		REPD(i,len)
			x = x*10 + ((mask&(1<<i))?7:4);
		happy.pb(x);
	}
	SORT(happy);

	cin>>n>>k;
	minsize = 1222333444555666777LL;
	REP(i,n)
	{
		cin >> brd[i].X >> brd[i].Y;
		bl.arr[i] = brd[i].X;
		br.arr[i] = brd[i].Y;
		minsize = min(minsize,(brd[i].Y-brd[i].X+1));
	}
	int left = 0, right = SZ(happy);
	sort(bl.arr,bl.arr+n);
	sort(br.arr,br.arr+n);
	while (left!=right)
	{
		int need = (left+right+1)/2;
		bool ok = false;
		bl.make(+1);
		br.make(-1);
		FOR(i,0,SZ(happy)-need)
		{
			if (happy[i+need-1]-happy[i]+1 > minsize)
				continue;
			bl.advance(happy[i]);
			br.advance(happy[i+need-1]);
			if (bl.r_sum+br.r_sum < k*4 && bl.sum+br.sum <= k)
			{
				ok = true;
				break;
			}
		}
		if (ok)
			left = need;
		else
			right = need-1;
	}
	printf("%d\n",left);
	return 0;
}