//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

typedef long double ld;

int n;
int cnt[102], a[102];
VP V; int sz;
const int p[2] = { 102352333, 876209077 };
int ncr[2][102][102];
int way[2][102][10002];
int ans;

void solve() {
	for (int k = 0; k < 2; k++) {
		ncr[k][0][0] = 1;
		int limncr = 100;
		for (int i = 1; i <= limncr; i++)
			for (int j = 0; j <= limncr; j++)
			{
				if (j > i) ncr[k][i][j] = 0;
				else if (j == i || j == 0) ncr[k][i][j] = 1;
				else {
					ncr[k][i][j] = ncr[k][i - 1][j - 1] + ncr[k][i - 1][j];
					if (ncr[k][i][j] >= p[k]) ncr[k][i][j] -= p[k];
				}
			}
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for (int i = 1; i <= 100; i++) {
		if (cnt[i]) {
			V.push_back({ i, cnt[i] });
		}
	}
	sz = SZ(V);
	sort(ALL(V));
	ans = 0;
	//ans = V[0].second;
	//ans = MAX(ans, V[sz - 1].second);
	for (int kk = 0; kk < 2; kk++) {
		way[kk][0][0] = 1;
		int mxsum = 0;
		for (int i = 1; i <= n; i++) {
			int val = a[i];
			for (int j = i - 1; j >= 0; j--) {
				for (int k = mxsum; k >= 0; k--) {
					way[kk][j + 1][k + val] += way[kk][j][k];
					if (way[kk][j + 1][k + val] >= p[kk]) {
						way[kk][j + 1][k + val] -= p[kk];
					}
				}
			}
			mxsum += val;
		}
	}
	for (int i = 0; i < SZ(V); i++) {
		for (int j = ans + 1; j <= V[i].second; j++) {
			if (way[0][j][j * V[i].first] == ncr[0][V[i].second][j] && 
				way[1][j][j * V[i].first] == ncr[1][V[i].second][j]) {
				ans = j;
			}
		}
	}
	if (sz == 2) ans = n;
	printf("%d\n", ans);
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	solve();


	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}