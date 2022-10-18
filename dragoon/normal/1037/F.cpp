#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int n, k;
int num[1000006];
PII tree[1000006 * 4];
LL ans = 0;
const LL MOD = 1000000007;

void build(int at, int l, int r) {
	if (l == r) {
		tree[at] = { num[l], l };
		return;
	}
	int mid = (l + r) / 2;
	build(at * 2, l, mid);
	build(at * 2 + 1, mid + 1, r);
	if (tree[at * 2].first > tree[at * 2 + 1].first) {
		tree[at] = tree[at * 2];
	}
	else {
		tree[at] = tree[at * 2 + 1];
	}
}

PII query(int at, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return tree[at];
	}
	if (R < l || r < L) {
		return { 0, 0 };
	}
	int mid = (l + r) / 2;
	PII A = query(at * 2, l, mid, L, R);
	PII B = query(at * 2 + 1, mid + 1, r, L, R);
	if (A.first >= B.first) return A;
	return B;
}


void solve(int l, int r) {
	if (r < l) return;
	if (r - l + 1 < k) return;
	PII q = query(1, 1, n, l, r);
	int pos = q.second;
	LL val = q.first;
	solve(l, pos - 1);
	solve(pos + 1, r);


	if (ABS(pos - l) < ABS(pos - r)) {
		// left is less
		int j = l + k - 1;
		while (j < pos) j += k - 1;
		for (int i = l; i <= pos; i++) {
			if (i > l) {
				j++;
				if (j - k + 1 >= pos && i + k - 1 <= j - k + 1) j -= k - 1;
			}
			if (j > r) break;
			int cnt = 1 + (r - j) / (k - 1);
			ans += cnt * val;
			ans %= MOD;
		}
	}
	else {
		// right is less
		int j = r - k + 1;
		while (j > pos) j -= k - 1;
		for (int i = r; i >= pos; i--) {
			if (i < r) {
				j--;
				if (j + k - 1 <= pos && j + k - 1 <= i - k + 1) j += k - 1;
			}
			if (j < l) break;
			int cnt = 1 + (j - l) / (k - 1);
			ans += cnt * val;
			ans %= MOD;
		}
	}
}

LL calc(VI V) {
	if (SZ(V) < k) return 0;
	VI Y;
	LL sum = 0;
	for (int i = 0; i <= SZ(V) - k; i++) {
		int now = V[i];
		for (int j = 0; j < k; j++) {
			now = MAX(now, V[j + i]);
		}
		Y.push_back(now);
		sum += now;
		sum %= MOD;
	}
	return sum + calc(Y);
}

LL calc() {
	VI V;
	for (int i = 1; i <= n; i++) V.push_back(num[i]);
	return calc(V);
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	scanf("%d %d", &n, &k);
	//n = 1000000, k = 2;
	//n = 7, k = 2;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		//num[i] = rand() % 10;
	}
	build(1, 1, n);
	ans = 0;
	solve(1, n);
	printf("%lld\n", ans);

	//LL temp = calc();
	//assert(ans == temp);

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}