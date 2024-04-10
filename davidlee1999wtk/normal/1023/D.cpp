#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#include<ctime>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int a[N], c[N * 4], ql, qr, ans;
void build_tree(int o, int L, int R)
{
	if (L == R)
	{
		c[o] = a[L];
		return;
	}
	int mid = (L + R) >> 1;
	build_tree(o << 1, L, mid);
	build_tree(o << 1 | 1, mid + 1, R);
	c[o] = min(c[o << 1], c[o << 1 | 1]);
}

void Get(int o, int L, int R)
{
	if (L >= ql && R <= qr)
	{
		ans = min(ans, c[o]);
		return;
	}
	int mid = (L + R) >> 1;
	if (ql <= mid)
		Get(o << 1, L, mid);
	if (qr > mid)
		Get(o << 1 | 1, mid + 1, R);
}

int last[N], pre[N];

int main()
{
	int n, q, i, first_zero = 0, have_q = 0;
	cin >> n >> q;
	a[0] = 1;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
		{
			a[i] = a[i - 1];
			if (first_zero == 0)
				first_zero = i;
		}
		if (a[i] == q)
			have_q = 1;
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	build_tree(1, 1, n);
	for (i = 1; i <= n; i++)
	{
		if (pre[i] != 0)
		{
			ql = pre[i];
			qr = i;
			ans = INF;
			Get(1, 1, n);
			if (ans < a[i])
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	if (!have_q)
		if (first_zero)
			a[first_zero] = q;
		else // hack
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/