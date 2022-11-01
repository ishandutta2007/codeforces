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

LL l,r;

LL g(LL x)
{
	LL t = 1;
	while (t <= x) t*=10;
	return (t-1-x)*x;
}

int n,m;
const char let[] = "ACGT";
char buf[1600];
int len[16];
int a[16][16];

VI st;

struct Node
{
	Node* ch[4];
	Node* next[4];
	int end;
	Node() { CLEAR(a);}
	void mark(Node * root)
	{
		end = 0;
		REP(i,m) if (len[i] <= SZ(st))
		{
			bool eq = true;
			REP(k,len[i])
				if (st[SZ(st)-len[i]+k] != a[i][k])
				{
					eq=false;
					break;
				}
			if (eq)
			{
				end = max(end, len[i]);
			}
		}
		REP(i,4) if (ch[i])
		{
			st.pb(i);
			ch[i]->mark(root);
			st.pop_back();
			next[i] = ch[i];
		}
		else
		{
			st.pb(i);
			next[i]=0;
			REP(j,SZ(st)+1) if (j>0)
			{
				Node * v = root;
				for (int jj = j; jj < SZ(st) && v; jj++)
					v = v->ch[st[jj]];
				if (v)
				{
					next[i] = v;
					break;
				}
			}
			st.pop_back();
		}
	}
};

#define MOD 1000000009 
Node nodes[1024];
int w;
int d[1024][128][11];

int main()
{
	//freopen("data.in","r",stdin);
	gets(buf);
	sscanf(buf,"%d%d",&n,&m);
	REP(i,m)
	{
		gets(buf);
		len[i] = strlen(buf);
		REP(j,len[i])
			a[i][j] = strchr(let,buf[j])-let;
	}
	w = 1;
	REP(i,m)
	{
		Node * v = &nodes[0];
		REP(j,len[i])
		{
			if (v->ch[a[i][j]] == 0)
				v->ch[a[i][j]] = &nodes[w++];
			v = v->ch[a[i][j]];
		}
	}
	nodes[0].mark(&nodes[0]);
	CLEAR(d);
	d[0][0][0] = 1;
	REP(i,n) REP(j,w) REP(c,11) if (d[i][j][c]) REP(add,4)
	{
		int nc = c+1;
		Node * v = nodes[j].next[add];
		if (v->end >= nc)
			nc = 0;
		if (nc == 10) continue;
		d[i+1][v-nodes][nc] = (d[i+1][v-nodes][nc] + d[i][j][c]) % MOD;
	}
	LL res = 0;
	REP(j,w)
		res = (res+d[n][j][0])%MOD;
	cout << res << endl;
	return 0;
}