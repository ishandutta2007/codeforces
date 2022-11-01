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

int a[1024];

struct T
{
	T(char C, T* P): c(C), parent(P) {}
	char c;
	T* parent;
	void Print()
	{
		char buf[1024];
		int len = 0;
		for (T* x = this; x && x->c; x = x->parent)
		{
			buf[len++] = x->c;
		}
		reverse(buf,buf+len);
		buf[len]=0;
		printf("%s\n",buf);
	}
};

T* ans[1024];

int main()
{
//	freopen(".in","r",stdin);
	int n;
	scanf("%d",&n);
	REP(i,n)
	{
		scanf("%d",&a[i]);
	}
	vector<T*> s;
	s.push_back(new T(0,0));
	FOR(i,1,1023)
	{
		vector<T*> ss;
		for(vector<T*>::iterator it = s.begin(); it != s.end(); it++)
		{
			if (ss.size() < 1024)
				ss.push_back(new T('0', *it));
			if (ss.size() < 1024)
				ss.push_back(new T('1', *it));
		}
		REP(j,n) if (a[j]==i)
		{
			if (ss.empty())
			{
				printf("NO\n");
				return 0;
			}
			ans[j]=ss.back();
			ss.pop_back();
			a[j] = -1;
		}
		s.swap(ss);
	}
	printf("YES\n");
	REP(i,n)
		ans[i]->Print();
	return 0;
}