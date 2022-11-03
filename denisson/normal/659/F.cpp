#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/
//

struct st {
	int pred, kol, r;
	st() {}
	st(int pred1) {
		pred = pred1;
		kol = 1;
		r = 0;
	}
};


int n, m;
ll k;
int a[1007][1007];
int c[1007][1007];
set<pair<int, int> > se;
int dx[4] = { -1, 0, 1, 0 }, dy[4] = {0, 1, 0, -1};
st cnm[2007 * 1007];
int kkk, ha;

int getPred(int v) {
	if (cnm[v].pred == v)
		return v;
	cnm[v].pred = getPred(cnm[v].pred);
	return cnm[v].pred;
}  

void merge(int v, int u) {
	v = getPred(v);
	u = getPred(u);
	if (v != u) {
		if (cnm[v].r < cnm[u].r)
			swap(v, u);
		cnm[u].pred = v;
		cnm[v].kol += cnm[u].kol;
		if (cnm[v].r == cnm[u].r)
			cnm[v].r++;
	}
}

int get(int v, int u) {
	return (v - 1) * m + u;
}

pair<int, int> antiGet(int v) {
	return mp(v / m + 1 + (v % m == 0 ? -1 : 0), v - m * (v / m) + (v % m == 0 ? m : 0));
}

void dfs(int x, int y) {
	if (c[x][y] != 0)
		return;
	if (kkk == 0)
		return;
	kkk--;
	c[x][y] = ha;
	if (kkk == 0)
		return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && a[nx][ny] >= ha) {
			dfs(nx, ny);
		}
	}
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("input.txt", "w", stdout);
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	scanf("%d %d %I64d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			se.insert(mp(a[i][j], get(i, j)));
			cnm[get(i, j)] = st(get(i, j));
		}
	}
	while (se.size()) {
		pair<int, int> now = *(--se.end());
		se.erase(--se.end());
		pair<int, int> uk = antiGet(now.YY);
		int val = now.XX;
		if (a[uk.XX][uk.YY - 1] >= val)
			merge(now.YY, get(uk.XX, uk.YY - 1));
		if (a[uk.XX][uk.YY + 1] >= val)
			merge(now.YY, get(uk.XX, uk.YY + 1));
		if (a[uk.XX - 1][uk.YY] >= val)
			merge(now.YY, get(uk.XX - 1, uk.YY));
		if (a[uk.XX + 1][uk.YY] >= val)
			merge(now.YY, get(uk.XX + 1, uk.YY));
		if (k % val == 0) {
			ll kol = (ll)k / (ll)val;
			if ((ll)cnm[getPred(now.YY)].kol >= kol) {
				printf("YES\n");
				kkk = kol;
				ha = val;
				dfs(uk.XX, uk.YY);
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) {
						printf("%d ", c[i][j]);
					}
					printf("\n");
				}
				exit(0);
			}
		}
	}
	printf("NO");
}