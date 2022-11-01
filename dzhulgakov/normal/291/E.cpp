#pragma comment(linker,"/STACK:64000000")
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
#include <cassert>

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

VI prefixFunc(const string &s) {
    VI f(SZ(s)); int k=0;
    FOR(i,1,SZ(s)-1) {
        while(k && s[k] != s[i]) k=f[k-1];
        if(s[k] == s[i]) ++k;
        f[i]=k; }
	return f; }

int KMPsearch(const string &s, const VI& f, const string &p, int& k) {
    int res=0;
    REP(i,SZ(s)) {
        while(k && p[k] != s[i]) k = f[k-1];
        if(p[k] == s[i]) ++k;
		if(k == SZ(p)) k = f[k-1], res++; }
	return res;
}

#define N 111000
int n;
string s[N],t;
VI a[N];
VI prefix;
int res;
queue<PII> q;

int main()
{
	//freopen("data.in","r",stdin);

	cin >> n;
	s[0] = "";
	REP(i,n) if (i)
	{
		int p;
		cin >> p >> s[i];
		a[p-1].pb(i);
	}
	cin >> t;
	prefix = prefixFunc(t);
	res = 0;
	q.push(PII(0,0));
	while (!q.empty()) {
		int v = q.front().X;
		int k = q.front().Y;
		q.pop();
		res += KMPsearch(s[v], prefix, t, k);
		REP(i,SZ(a[v]))
			q.push(PII(a[v][i],k));
	}
	cout << res << endl;
	return 0;
}