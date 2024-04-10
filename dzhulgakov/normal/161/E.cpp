#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:16000000")
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
#include <ctime>

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

#define MAXP 100000
bool iscomp[MAXP];
int pr[MAXP],prc;
void getPrimes() {
	CLEAR(iscomp); prc=0;
	for (int i = 2; i < MAXP; i++) if (!iscomp[i])	{
		pr[prc++]=i;
		if (i <= MAXP/i) for (int j = i*i; j < MAXP; j+=i)
			iscomp[j]=true;
	} }

struct Node
{
	Node* a[10];
	VI b[6];
	Node() { CLEAR(a); }
} root;

const int pw10[6] = {1,10,100,1000,10000,100000};

void add(int x, int len)
{
	Node * v = &root;
	while (1)
	{
		v->b[len].pb(x);
		if (len==0) break;
		int d = (x / pw10[len-1]) % 10;
		if (v->a[d] == 0) v->a[d] = new Node();
		v=v->a[d];
		--len;
	}
}

int n;
int a[5][5];
LL res;

void rec(int s, Node** arr)
{
	if (s == n)
	{
		++res;
		return;
	}
	/*for (int i = s; i < n; i++)
	{
		if (arr[i] == 0 || arr[i]->b[n-s].empty()) return;
	}*/
	Node*v = arr[s];
	//if (v == 0 || v->b[n-s].empty()) return;
	REP(k,SZ(v->b[n-s]))
	{
		Node*nw[5];
		bool bad = false;
		for (int x = v->b[n-s][k], j=n-1; j >= s; j--,x/=10)
		{
			a[j][s]=a[s][j] = x%10;
			nw[j] = arr[j]->a[a[j][s]];
			if (nw[j] == 0 || nw[j]->b[n-s-1].empty())
			{
				bad = true;
				break;
			}
		}
		if (!bad)
			rec(s+1,nw);
	}
}

int main()
{
	//freopen("e.in","r",stdin);
	//int qq;	scanf("%d",&qq);	srand(qq);

	getPrimes();
	REP(i,prc)
	{
		int len = 0;
		for (int x = pr[i]; x; x/=10) ++len;
		for (int j = len; j <= 5; j++)
			add(pr[i],j);
	}

	int tests;
	scanf("%d",&tests);
	//tests = 100; double lng = 0; int lll = 0;
	for (int test = 1; test<=tests; test++)
	{
		int fst;
		scanf("%d",&fst);

		//fst = pr[1500 + rand()%(prc-1500)]; int q = clock();

		char buf[100];
		sprintf(buf,"%d",fst);
		n = strlen(buf);
		res = 0;
		Node*st[5];
		REP(i,n)
		{
			a[0][i]=a[i][0]=buf[i]-'0';
			st[i]=root.a[a[i][0]];
		}
		rec(1,st);
		cout << res << endl;

		/*double spent = ((clock()-q)*1.0/CLOCKS_PER_SEC);
		cout << "? " << fst << "  " << spent << endl;
		if (spent > lng)
		{
			lng=spent;
			lll = fst;
		}*/
	}
		//cout << "??? " << lll << "  " << lng << endl;
	return 0;
}