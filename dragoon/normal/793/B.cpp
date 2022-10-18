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

int R, C;
char grid[1003][1003];
int dist[1003][1003][4];

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

struct Pos {
	int r, c, dir;
};

int main()
{
	int n, m;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", grid[i]);
	PII src, snk;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == 'S') {
				src = PII(i, j);
			}
			if (grid[i][j] == 'T') {
				snk = PII(i, j);
			}
		}
	}

	MEM(dist, -1);

	deque<Pos> Q;
	for (int i = 0; i < 4; i++) {
		dist[src.first][src.second][i] = 1;
		Q.push_back({ src.first, src.second, i });
	}

	while (!Q.empty()) {
		Pos u = Q.front();
		Q.pop_front();

		for (int i = 0; i < 4; i++) {
			int r = u.r + dr[i];
			int c = u.c + dc[i];
			if (IN(r, 0, R - 1) && IN(c, 0, C - 1) && grid[r][c] != '*') {
				int d = dist[u.r][u.c][u.dir] + (i != u.dir);
				if (dist[r][c][i] == -1 || dist[r][c][i] > d) {
					dist[r][c][i] = d;
					if (i == u.dir) Q.push_front({ r, c, i });
					else Q.push_back({ r, c, i });
				}
			}
		}
	}

	int ans = 1000000000;
	for (int i = 0; i < 4; i++) if (dist[snk.first][snk.second][i] != -1) ans = MIN(ans, dist[snk.first][snk.second][i]);
	//printf(">>%d\n", ans);
	if (ans < 4) printf("YES\n");
	else printf("NO\n");
	return 0;
}