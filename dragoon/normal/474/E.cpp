#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
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
typedef long long int LL;
//typedef __int64 LL;

PII tree[4 * 100005];
LL H[100005], h[100005];
int prevs[100005], dp[100005];

void insert(int at, int l, int r, LL x, int v, int id)
{
	if(l == r)
	{
		if(tree[at].second < v)
			tree[at] = PII(id, v);
		return;
	}
	int m = (l + r) / 2;
	if(x <= H[m]) insert(at * 2, l, m, x, v, id);
	else insert(at * 2 + 1, m + 1, r, x, v, id);
	if(tree[at * 2].second > tree[at * 2 + 1].second)
		tree[at] = tree[at * 2];
	else
		tree[at] = tree[at * 2 + 1];
}

PII query(int at, int l, int r, LL x, LL y)
{
	if(y < x)
		return PII(-1, -1);

	if(x <= H[l] && H[r] <= y)
		return tree[at];
	if(y < H[l] || x > H[r])
		return PII(-1, -1);

	int m = (l + r) / 2;
	PII a = query(2 * at, l, m, x, y);
	PII b = query(2 * at + 1, m + 1, r, x, y);
	if(a.second > b.second) return a;
	return b;
}

int main()
{
	int n;
	LL d;

	for(int i = 0; i < 4 * 100005; i++)
		tree[i] = PII(-1, -1);

	scanf("%d %I64d", &n, &d);
	for(int i = 0; i < n; i++) {scanf("%I64d", &h[i]); H[i] = h[i];}
	sort(H, H + n);
	int N = unique(H, H + n) - H;
	
	for(int i = 0; i < n; i++)
	{
		prevs[i] = -1;
		dp[i] = 1;

		PII a = query(1, 0, N - 1, H[0], h[i] - d);
		PII b = query(1, 0, N - 1, h[i] + d, H[N - 1]);

		if(b.second > a.second) a = b;
		if(a.first != -1) prevs[i] = a.first, dp[i] = a.second + 1;
		insert(1, 0, N - 1, h[i], dp[i], i);
	}

	int ans = 0;
	int id = 0;
	for(int i = 0; i < n; i++)
		if(dp[i] > ans)
		{
			ans = dp[i];
			id = i;
		}

	printf("%d\n", ans);
	VI V;
	while(id != -1)
	{
		V.push_back(id + 1);
		id = prevs[id];
	}

	for (int i = V.size() - 1; i >= 0; i--)
	{
		printf("%d", V[i]);
		if(i) printf(" ");
	}
	printf("\n");


	return 0;
}