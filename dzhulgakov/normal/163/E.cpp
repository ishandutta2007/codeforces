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

class AhoCorasick { public:
	struct Node {
		int a[27], p, link, nok, h;
		int leafid; char pch;
		Node(int P=-1, char Pch=0):p(P),pch(Pch),leafid(-1),nok(-2),link(-1),h(-1) {FILL(a,-1);} };
	vector<Node> a;
	AhoCorasick() {a.clear(); a.pb(Node()); a.reserve(1024000); }
	void addstr(char * c, int id) {
		int v = 0;
		for (; *c; v=a[v].a[*c++])
			if (a[v].a[*c]==-1) {
				Node q(v,*c);
				a[v].a[*c]=SZ(a);
				a.pb(q); }
		a[v].leafid=id; }
	int go(int v, char c);
	int link(int v);
	int nok(int v);
	int height(int v);
}; // iteration through solutions: v=nok(v)
int AhoCorasick::go(int v, char c) {
	return a[v].a[c]==-1 ? (v==0 ? 0 : go(link(v),c)) : a[v].a[c]; }
int AhoCorasick::link(int v) {
	return a[v].link==-1 ? (a[v].link = v==0||a[v].p==0 ? 0 : go(link(a[v].p),a[v].pch)) : a[v].link; }
int AhoCorasick::nok(int v) {
	if (a[v].nok==-2) { int l = link(v);
		a[v].nok = l==0 ? -1 : (a[l].leafid != -1 ? l : nok(l)); }
	return a[v].nok;}
int AhoCorasick::height(int v) {
	return a[v].h == -1 ? (a[v].h = v==0 ? 0 : height(a[v].p)+1) : a[v].h; }

template <class T, int N> class Summator { public:
	T a[N]; int n;
	inline void make(int nn) { n=nn; CLEAR(a); }
	inline void modify(int x, T by)	{ a[x] += by;
		for (int i=1;1;i<<=1) if ((x&i)==0) {
			if ((x|=i)>=n) break;
			a[x] += by; } }
	inline T sum(int x) { T res=0;
		for (; x >= 0; x = (x&(x+1))-1) res += a[x];
		return res; }
	inline T sum(int l, int r) { T res=0; l--;
		for (; r > l; r = (r&(r+1))-1) res += a[r];
		for (; l > r; l = (l&(l+1))-1) res -= a[l];
		return res; } };

AhoCorasick a;

#define N 111000
int n,m;
char buf[1024000];
int st[N],ed[N];
VI adj[N];
int tmr;
Summator<int,N*2> summ;
bool inside[N];

void dfs(int v)
{
	st[v] = tmr++;
	REP(i,SZ(adj[v]))
		dfs(adj[v][i]);
	ed[v] = tmr++;
}

int main()
{
	//freopen("e.in","r",stdin);

	scanf("%d%d",&m,&n);
	REP(i,n)
	{
		scanf("%s",buf);
		for (char *c = buf; *c; c++)
			*c-='a'-1;
		a.addstr(buf,i);
	}
	REP(i,SZ(a.a)) if (a.a[i].leafid != -1)
	{
		int v = a.a[i].leafid;
		int p = a.nok(i);
		if (p==-1)
		{
			adj[n].pb(v);
			continue;
		}
		int vv = a.a[p].leafid;
		adj[vv].pb(v);
	}
	tmr=0;
	REP(i,SZ(adj[n]))
		dfs(adj[n][i]);
	summ.make(tmr);
	CLEAR(inside);
	REP(i,n)
	{
		summ.modify(st[i],+1);
		summ.modify(ed[i],-1);
		inside[i]=true;
	}
	REP(step,m)
	{
		scanf("%s",buf);
		if (buf[0]=='?')
		{
			int v = 0;
			LL res = 0;
			for (char *c = buf+1; *c; c++)
			{
				v = a.go(v,*c-'a'+1);
				int ok = a.a[v].leafid != -1 ? v : a.nok(v);
				if (ok != -1)
				{
					int id = a.a[ok].leafid;
					if (id != -1)
						res += summ.sum(st[id]);
				}
			}
			cout << res << endl;
		}
		else
		{
			int id;
			sscanf(buf+1,"%d",&id);
			--id;
			if (buf[0] == '+')
			{
				if (!inside[id])
				{
					summ.modify(st[id],+1);
					summ.modify(ed[id],-1);
					inside[id]=true;
				}
			}
			else
			{
				if (inside[id])
				{
					summ.modify(st[id],-1);
					summ.modify(ed[id],+1);
					inside[id]=false;
				}
			}
		}
	}
	return 0;
}