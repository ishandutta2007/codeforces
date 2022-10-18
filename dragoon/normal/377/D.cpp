#pragma warning(disable:4786)
#include<list>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;


#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

struct Worker
{
	int l, v, r;
};

Worker worker[100005];
int x[100005], y[100005];
int tree[4*300005];
int suf_max[4*300005];
int wheres[4*300005];

bool cmp_x(int a, int b) { return worker[a].v < worker[b].v; }
bool cmp_y(int a, int b) { return worker[a].l < worker[b].l; }

void update(int at, int L, int R, int p, int u)
{
	if(L==R)
	{
		tree[at] += u;
		suf_max[at] = tree[at];
		wheres[at] = L;
		return;
	}

	int M = (L + R)/2;
	if(p <= M) update(at * 2, L, M, p, u);
	else update(at * 2 + 1, M + 1, R, p, u);

	if(suf_max[at*2] >= tree[at*2] + suf_max[at*2+1])
	{
		wheres[at] = wheres[at*2];
	}
	else
	{
		wheres[at] = wheres[at*2 + 1];
	}

	suf_max[at] = MAX(suf_max[at*2], tree[at*2] + suf_max[at*2+1]);
	tree[at] = tree[at*2] + tree[at*2 + 1];
}

int main()
{
	int n, i, j, ans = 0, cur, cury;
	int last, first;

	scanf("%d", &n);
	FORN(i, n)
	{
		scanf("%d %d %d", &worker[i].l, &worker[i].v, &worker[i].r);
	}

	FORN(i, n) x[i] = y[i] = i;

	sort(x, x + n, cmp_x);
	sort(y, y + n, cmp_y);

	int Z = 300001;
	j = n - 1;
	for(i = n - 1; i >= 0; i--)
	{
		cur = x[i];
		update(1, 1, Z, worker[cur].v, 1);
		update(1, 1, Z, worker[cur].r + 1, -1);

		while(j >= 0)
		{
			cury = y[j];
			if(worker[cury].l > worker[cur].v)
			{
				update(1, 1, Z, worker[cury].v, -1);
				update(1, 1, Z, worker[cury].r + 1, 1);
				j--;
			}
			else
			{
				break;
			}
		}

		if(ans < suf_max[1])
		{
			ans = suf_max[1];
			first = worker[cur].v;
			last = wheres[1];
		}
	}

	printf("%d\n", ans);
	int flag = 0 ;
	FORN(i, n)
	{
		if(worker[i].l <= first && last <= worker[i].r && first <= worker[i].v && worker[i].v <= last)
		{
			if(flag) printf(" ");
			printf("%d",i + 1);
			flag++;
		}
	}

	assert(ans == flag);

	printf("\n");

	return 0;
}