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

typedef struct item * pitem;
struct item {
	int prior, cnt, key;
	LL summ;
	pitem l, r;
	item (int key=0, int prior=0) : key(key), prior(prior), l(NULL), r(NULL) { cnt = 1; summ = key; }
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

LL summ (pitem it) {
	return it ? it->summ : 0;
}

void upd_cnt (pitem it) {
	if (it)
	{
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
		it->summ = summ(it->l) + summ(it->r) + it->key;
	}
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, int key, pitem & l, pitem & r) {
	if (!t)
		l = r = NULL;
	else if (key <= t->key)
		split (t->l, key, l, t->l),  r = t;
	else
		split (t->r, key, t->r, r),  l = t;
	upd_cnt (t);
}

int n;
#define N 111000
item items[N];
int rands[N];

int main()
{
//	freopen("data.in","r",stdin);

	char buf[1024];
	gets(buf);
	sscanf(buf,"%d",&n);
	pitem root[5];
	CLEAR(root);
	REP(i,n)
		rands[i]=i;
	random_shuffle(rands,rands+n);
	REP(step,n)
	{
		gets(buf);
		char cmd[1024];
		int val;
		sscanf(buf,"%s %d",cmd,&val);
		if (strcmp(cmd,"sum")==0)
		{
			cout << summ(root[2]) << "\n";
		}
		else
		{
			pitem ends[5];
			REP(i,5)
				split(root[i],val,root[i],ends[i]);
			if (strcmp(cmd,"add") == 0)
			{
				int mn = INF;
				REP(i,5)
					mn = min(cnt(root[i]),mn);
				REP(i,5)
					if (cnt(root[i]) == mn)
					{
						items[step] = item(val,rands[step]);
						merge(root[i],root[i],&items[step]);
						break;
					}
				REP(i,5)
					merge(root[i],root[i],ends[(i+4)%5]);
			}
			else
			{
				REP(i,5)
				{
					pitem dummy;
					split(ends[i],val+1,dummy,ends[i]);
				}
				REP(i,5)
					merge(root[i],root[i],ends[(i+1)%5]);
			}
			/*int x = 0;
			REP(i,5) x += cnt(root[i]);
			cout << " = " << x << "\n";*/
		}
	}
	return 0;
}