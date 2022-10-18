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
#include<unordered_map>
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
//Stores intermediate order for lcp

char S[1000006];
int o[21][1000006];
/*int inv[1000006];*/
int final;

int lcp(int a, int b)
{
	int ret = 0;
	for (int i = final; i >= 0; i--)
	{
		if (o[i][a] != o[i][b])
			continue;

		ret += 1 << i;
		a += 1 << i;
		b += 1 << i;
	}

	return ret;
}

void suffix_array()
{
	int *A, *B, *C, *D;
	int **t;
	int N, i, j, jj, k, x;

	N = strlen(S);

	A = new int[N + 26];
	B = new int[N + 26];
	C = new int[N + 26];
	D = new int[N + 26];

	t = new int*[2];
	t[0] = new int[N + 26];
	t[1] = new int[N + 26];

	memset(A, 0, sizeof(int)*(N + 26));
	for (i = 0; i < N; ++i) A[(int)(S[i] - 'a')] = 1;
	for (i = 1; i < 26; ++i) A[i] += A[i - 1];
	for (i = 0; i < N; ++i) o[0][i] = A[(int)(S[i] - 'a')];
	x = 0;

	for (j = 0, jj = 1, k = 0; jj < N && k < N; ++j, jj <<= 1) {
		memset(A, 0, sizeof(int)*(N + 26));
		memset(B, 0, sizeof(int)*(N + 26));
		for (i = 0; i < N; ++i) {
			++A[t[0][i] = o[x][i]];
			++B[t[1][i] = (i + jj<N) ? o[x][i + jj] : 0];
		}
		for (i = 1; i <= N; ++i) {
			A[i] += A[i - 1];
			B[i] += B[i - 1];
		}
		for (i = N - 1; i >= 0; --i)
			C[--B[t[1][i]]] = i;
		for (i = N - 1; i >= 0; --i)
			D[--A[t[0][C[i]]]] = C[i];

		x++;
		o[x][D[0]] = k = 1;
		for (i = 1; i < N; ++i)
			o[x][D[i]] = (k += (t[0][D[i]] != t[0][D[i - 1]] || t[1][D[i]] != t[1][D[i - 1]]));
	}

	final = x;
	/*
	for(i = 0; i < N; i++)
	inv[o[x][i]] = i;
	*/
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;

	delete[] t[0];
	delete[] t[1];
	delete[] t;
}

char s01[100005];

void solve() {
	scanf("%s %s", s01, S);
	/*s01[100000] = 0;
	S[1000000] = 0;
	for (int i = 0; i < 100000; i++) s01[i] = '0'; s01[0] = '1';
	for (int i = 0; i < 1000000; i++) S[i] = 'a';*/
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	int l0 = strlen(s01);
	int l = strlen(S);
	for (int i = 0; i < l0; i++) {
		cnt[s01[i] - '0']++;
	}
	suffix_array();
	int ans = 0;
	for (LL i = 1; i < l; i++) {
		if (l <= cnt[0] * i) continue;
		if ((l - cnt[0] * i) % cnt[1]) continue;
		LL j = (l - cnt[0] * i) / cnt[1];
		PII pos[2];
		pos[0] = pos[1] = { -1, -1 };
		int prev = 0;
		int flag = 1;
		for (int k = 0; k < l0; k++) {
			if (s01[k] == '0') {
				if (pos[0].first == -1) {
					pos[0] = { prev, prev + i - 1 };
				}
				else {
					int common = lcp(pos[0].first, prev);
					if (common < i) flag = 0;
				}
				prev += i;
			}
			else {
				if (pos[1].first == -1) {
					pos[1] = { prev, prev + j - 1 };
				}
				else {
					int common = lcp(pos[1].first, prev);
					if (common < j) flag = 0;
				}
				prev += j;
			}
			if (!flag) break;
		}
		if (i == j) {
			int common = lcp(pos[0].first, pos[1].first);
			if (common >= i) flag = 0;
		}
		ans += flag;
		//if (flag) printf("%lld %lld\n", i, j);
	}
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