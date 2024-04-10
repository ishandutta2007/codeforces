/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define IS(a, i) (int)(((a) >> (i)) & 1)
#define sz(a) (int)(a).size()
#define pb push_back

struct edge {
	int i, j, type;
	bool operator < ( edge e ) const { return 0; }
};

typedef long long ll;

const int N = 34;

vector<edge> e;
int u[N][N];
ll d1[N + 1][N + 1];
ll d2[N + 1][N + 1];

void f() {
	memset(d1, 0, sizeof(d1));
	d1[0][0] = 1;
	forn(i, N)
		forn(j, N) {
			if (i + 1 < N && !IS(u[i][j], 0)) d1[i + 1][j] += d1[i][j];
			if (j + 1 < N && !IS(u[i][j], 1)) d1[i][j + 1] += d1[i][j];
		}
	memset(d2, 0, sizeof(d2));
	d2[N - 1][N - 1] = 1;
	fornd(i, N)
		fornd(j, N) {
			if (i - 1 >= 0 && !IS(u[i - 1][j], 0)) d2[i - 1][j] += d2[i][j];
			if (j - 1 >= 0 && !IS(u[i][j - 1], 1)) d2[i][j - 1] += d2[i][j];
		}
}

int walls;
void result() {
	printf("%d %d\n%d\n", N, N, walls);
	forn(i, N)
		forn(j, N) {
			if (IS(u[i][j], 0)) printf("%d %d %d %d\n", i + 1, j + 1, i + 2, j + 1);
			if (IS(u[i][j], 1)) printf("%d %d %d %d\n", i + 1, j + 1, i + 1, j + 2);
		}
	exit(0);
}

int main() {
	ll T;
	cin >> T;
	forn(i, N)
		forn(j, N) {
			if (i + 1 < N) e.push_back(edge {i, j, 0});
			if (j + 1 < N) e.push_back(edge {i, j, 1});
		}
	for (int cnt = 0;; cnt++) {
		vector<edge> tmp = e;
		vector<pair<ll, edge>> a;
		memset(u, 0, sizeof(u)), walls = 0;
		while (1) {
			f();
			a.clear();
			for (auto p : tmp) {
				int di = !p.type, dj = p.type;
				ll x = d2[0][0] - d1[p.i][p.j] * d2[p.i + di][p.j + dj];
				if (x == T) {
					u[p.i][p.j] ^= 1 << p.type, walls++;
					result();
				}
				if (x > T) 
					a.pb(make_pair(x, p));
			}
			if (!sz(a))
				break;
			sort(all(a));
			int k = rand() % min(sz(a), ((cnt % 3) * 2 + 3));
			edge p = a[k].second;
			u[p.i][p.j] ^= 1 << p.type, walls++;
			swap(a[k], a.back()), a.pop_back();
			tmp.resize(sz(a));
			forn(i, sz(a))
				tmp[i] = a[i].second;
			f();
			assert(d2[0][0] >= T);
		}
		f();
	}
}