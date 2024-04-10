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

int n, k;
char grid[2003][2003];

int rem[2003][2003];

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", grid[i]);
	}

	string s = "";
	if (grid[0][0] == 'a' || k > 0) {
		s.push_back('a');
		if (grid[0][0] != 'a') {
			rem[0][0] = k - 1;
		}
		else {
			rem[0][0] = k;
		}
	}
	else {
		s.push_back(grid[0][0]);
		rem[0][0] = k;
	}

	for (int dia = 1; dia <= (n - 1) * 2; dia++) {
		for (int c = 0; c < n; c++) {
			int r = dia - c;
			if (IN(r, 0, n - 1));
			else continue;

			int x = -1, y = -1;
			if (IN(r, 0, n - 1) && IN(c - 1, 0, n - 1)) {
				x = rem[r][c - 1];
			}
			if (IN(r - 1, 0, n - 1) && IN(c, 0, n - 1)) {
				y = rem[r - 1][c];
			}
			rem[r][c] = MAX(x, y);
		}

		char best = 'z' + 1;
		for (int c = 0; c < n; c++) {
			int r = dia - c;
			if (IN(r, 0, n - 1));
			else continue;

			if (rem[r][c] == -1) continue;

			if (rem[r][c]) best = 'a';
			else best = MIN(best, grid[r][c]);
		}

		s.push_back(best);
		for (int c = 0; c < n; c++) {
			int r = dia - c;
			if (IN(r, 0, n - 1));
			else continue;
			if (rem[r][c] == -1) continue;

			if (grid[r][c] == best) {
				rem[r][c] = rem[r][c];
			}
			else if (rem[r][c]) {
				rem[r][c]--;
			}
			else {
				rem[r][c] = -1;
			}
		}
	}
	printf("%s\n", s.c_str());
#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}