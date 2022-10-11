#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 100 * 1000 + 228;

int n, m, q;
char st1[MAX_N];
char st2[MAX_N];
int a1[MAX_N];
int b1[MAX_N];
int a2[MAX_N];
int b2[MAX_N];
int ls1[MAX_N];
int ls2[MAX_N];

void build(int n, char st[], int a[], int b[], int ls[])
{
	a[0] = b[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (st[i] == 'C') st[i] = 'B';
		if (st[i] == 'A') a[i] = 1;
		if (st[i] == 'B') b[i] = 1;

		a[i] += a[i - 1];
		b[i] += b[i - 1];

		if (st[i] == 'A') ls[i] = ls[i - 1];
		else ls[i] = i;
	}
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%s", st1 + 1);
	scanf("%s", st2 + 1);
	n = strlen(st1 + 1);
	m = strlen(st2 + 1);
	
	build(n, st1, a1, b1, ls1);
	build(m, st2, a2, b2, ls2);

	scanf("%d", &q);

	while (q--)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		
		int cnt1_a = a1[r1] - a1[l1 - 1];
		int cnt1_b = b1[r1] - b1[l1 - 1];
		int cnt2_a = a2[r2] - a2[l2 - 1];
		int cnt2_b = b2[r2] - b2[l2 - 1];
		
		int bb1 = ls1[r1];
		int bb2 = ls2[r2];
		
		int bg1, ed1, bg2, ed2;
		if (bb1 < l1) {bg1 = 0; ed1 = r1 - l1 + 1;}
		else {bg1 = b1[bb1] - b1[l1 - 1]; ed1 = r1 - bb1;}

		if (bb2 < l2) {bg2 = 0; ed2 = r2 - l2 + 1;}
		else {bg2 = b2[bb2] - b2[l2 - 1]; ed2 = r2 - bb2;}
		bool fk = false;
		if (!bg1 && bg2) {bg1 += 2; ed1 -= 1; fk = true;}
		if (((bg2 < bg1 || ed2 > ed1 || bg1 % 2 != bg2 % 2) || (!fk && bg1 == bg2 && abs(ed2 - ed1) % 3 != 0)) || cnt1_b % 2 != cnt2_b % 2 || ed1 < 0) printf("0");
		else printf("1");
	}

	return 0;
}