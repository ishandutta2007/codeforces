#pragma comment(linker, "/STACK:64000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i,n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define REPD(i,n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = (a); _##i = (b); i <= _##i; ++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define pb push_back
#define MP make_pair
const double pi = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef long long LL;

char a[128];
int n;

int nrm(int x) {
	return (x+2*n)%n;
}

VI pr[128];

map<string,LL> mem;

LL go(string ch) {
	if (mem.count(ch))
		return mem[ch];
	REP(i,n) if (ch[i] == '1')
	{
		LL res = 0;
		string ch2 = ch;
		ch2[i] = '0';
		res += go(ch2);
		REP(j,SZ(pr[i]))
		{
			ch2[pr[i][j]] = '0';
		}
		res += go(ch2);
		return mem[ch] = res;
	}
	return mem[ch] = 1;
}

LL solve() {
	VI mark(n,0);
	REP(i,n) pr[i].clear();
	string ch(n,'0');
	REP(i,n)
	{
		if (a[i] == 'A' && a[nrm(i+1)] == 'B')
		{
			pr[nrm(i-1)].pb(nrm(i+1));
			pr[nrm(i+1)].pb(nrm(i-1));
		}
		if (a[i] == 'B' && a[nrm(i+1)] == 'A')
		{
			ch[i] = '1';
		}
	}
	string ch2 = ch;
	REP(i,n)
	{
		if (ch[i]=='0')
		{
			REP(j,SZ(pr[i]))
				if (ch[pr[i][j]]=='0')
					return 0;
				else
				{
					ch2[pr[i][j]] = '0';
				}
		}
	}
	mem.clear();
	return go(ch2);
}

int main()
{
	//freopen("c.in","r",stdin);

	int res = 0;
	gets(a);
	n = strlen(a);

	cout << solve() << endl;

	return 0;
}