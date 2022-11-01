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

template<class T> inline T gcd(T a,T b) {
	if(a<0)a=-a; if(b<0)b=-b; if(a<b)swap(a,b);
	while (b) {T t = b; b=a%b; a=t;} return a; }

string q1(string s)
{
	string r = "      ";
	r[0]=s[0];
	r[1]=s[2];
	r[2]=s[3];
	r[3]=s[4];
	r[4]=s[1];
	r[5]=s[5];
	return r;
}

string q2(string s)
{
	string r = "      ";
	r[2]=s[2];

	r[0]=s[1];
	r[1]=s[5];
	r[5]=s[3];
	r[3]=s[0];

	r[4]=s[4];
	return r;
}

int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	char buf[1024];
	scanf("%s",buf);
	string st = string(buf);
	SORT(st);
	set<string> u;
	int res = 0;
	do {
		if (u.count(st)) continue;
		u.insert(st);
		queue<string> q;
		q.push(st);
		while (!q.empty())
		{
			string s = q.front();
			q.pop();
			if (!u.count(q1(s)))
			{
				q.push(q1(s));
				u.insert(q1(s));
			}
			if (!u.count(q2(s)))
			{
				q.push(q2(s));
				u.insert(q2(s));
			}
		}
		++res;
	} while (next_permutation(ALL(st)));
	printf("%d\n",res);
}