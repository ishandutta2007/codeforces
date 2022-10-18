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

void Update(PLL& ans, LL a, LL b) {
	if (ans.first == -1) {
		ans = { a, b };
		return;
	}
	if (S(ans.first + ans.second) * (a * b) >
		S(a + b) * (ans.first * ans.second)) {
		ans = { a, b };
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	VI V;
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		V.push_back(v);
	}
	sort(ALL(V));
	VI W;
	for (int i = 0; i < SZ(V); i++) {
		if (i + 1 < SZ(V) && V[i] == V[i + 1]) {
			W.push_back(V[i]);
			i++;
		}
	}
	PLL ans = { -1, -1 };
	for (int i = 1; i < SZ(W); i++) {
		Update(ans, W[i - 1], W[i]);
	}
	printf("%lld %lld %lld %lld\n", ans.first, ans.first, ans.second, ans.second);
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) solve();


	return 0;
}