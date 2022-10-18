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
//#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

string s[2][302][302];
char grid[100005];
int n, m;

int cnt[2][302];
int req[2][302];

struct Move {
	int r1, c1, r2, c2;
	void print() {
		printf("%d %d %d %d\n", r1 + 1, c1 + 1, r2 + 1, c2 + 1);
	}
};

void solve(int id, vector<Move>& V) {
	for (int i = 0; i < m; i++) {
		cnt[0][i] = cnt[1][i] = 0;
	}

	if (id == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				reverse(ALL(s[id][i][j]));
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int nj = (j + 1);
		if (nj == m) nj = 0;
		for (char ch : s[id][0][j]) {
			if (ch == '0') {
				V.push_back({ 0, j, 0, nj });
				cnt[0][nj]++;
			}
			else {
				V.push_back({ 0, j, n - 1, j });
				cnt[1][j]++;
			}
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			for (char ch : s[id][i][j]) {
				if (ch == '0') {
					V.push_back({ i, j, 0, j });
					cnt[0][j]++;
				}
				else {
					V.push_back({ i, j, n - 1, j });
					cnt[1][j]++;
				}
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int nj = (j + 1);
		if (nj == m) nj = 0;
		for (char ch : s[id][n - 1][j]) {
			if (ch == '0') {
				V.push_back({ n - 1, j, 0, j });
				cnt[0][j]++;
			}
			else {
				V.push_back({ n - 1, j, n - 1, nj });
				cnt[1][nj]++;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		req[0][i] = req[1][i] = 0;
		for (int j = 0; j < n; j++) {
			for (char ch : s[1][j][i]) {
				req[ch - '0'][i]++;
			}
		}
		cnt[0][i] -= req[0][i];
		cnt[1][i] -= req[1][i];
	}

	for (int i = 0; i < m; i++) {
		int j = 0;
		while (cnt[0][i] > 0) {
			while (j < m && cnt[0][i] > 0 && cnt[0][j] < 0) {
				cnt[0][i]--;
				cnt[0][j]++;
				V.push_back({ 0, i,0, j });
			}
			j++;
		}
	}
	for (int i = 0; i < m; i++) {
		int j = 0;
		while (cnt[1][i] > 0) {
			while (j < m && cnt[1][i] > 0 && cnt[1][j] < 0) {
				cnt[1][i]--;
				cnt[1][j]++;
				V.push_back({ n - 1, i,n - 1, j });
			}
			j++;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", grid);
			s[0][i][j] = grid;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", grid);
			s[1][i][j] = grid;
		}
	}

	vector<Move> V1, V2;
	solve(0, V1);
	solve(1, V2);
	/*printf("--\n");
	for (auto&m : V2) {
		m.print();
	}
	printf("--\n");
	*/
	reverse(ALL(V2));
	printf("%d\n", SZ(V1) + SZ(V2));
	for (auto& m : V1) {
		m.print();
	}
	for (auto& m : V2) {
		swap(m.r1, m.r2);
		swap(m.c1, m.c2);
		m.print();
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}