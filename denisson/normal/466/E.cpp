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
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

struct cnm {
	int pred, r;
	cnm() {}
};

struct zap {
	int type, x, y;
	zap() {}
};

int n, m, ti = 0;
int tin[100007], tout[100007];
bool can[100007];
cnm t[100007];
zap q[100007];
vector<int> was[100007];
vector<int> g[100007];
bool anss[100007];

int get(int v) {
	if (t[v].pred == v) return v;
	t[v].pred = get(t[v].pred);
	return t[v].pred;
}

void merge(int a, int b) {
	a = get(a), b = get(b);
	if (a != b) {
		if (t[a].r < t[b].r)
			swap(a, b);
		t[b].pred = a;
		if (t[b].r == t[a].r)
			t[a].r++;
	}
}

void dfs(int v) {
	tin[v] = ti++;
	for (int to : g[v])
		dfs(to);
	tout[v] = ti++;
}

bool pred(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	for (int i = 0; i < 100007; i++)
		t[i].pred = i, t[i].r = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int type, x, y;
		scanf("%d", &type);
		if (type == 2)
			scanf("%d", &x);
		else
			scanf("%d %d", &x, &y);
		x--; y--;
		if (type == 1) g[y].pub(x), can[x] = 1;
		if (type == 3) was[y].pub(i);
		q[i].type = type, q[i].x = x, q[i].y = y;
	}
	for (int i = 0; i < n; i++)
		if (!can[i])
			dfs(i);
	int uk = 0;
	for (int i = 0; i < m; i++) {
		if (q[i].type == 1) {
			merge(q[i].x, q[i].y);
		}
		if (q[i].type == 2) {
			for (int x : was[uk]) {
				if (get(q[i].x) == get(q[x].x) && pred(q[x].x, q[i].x))
					anss[x] = 1;
			}
			uk++;
		}
	}
	for (int i = 0; i < m; i++) if (q[i].type == 3) {
		if (anss[i]) printf("YES\n"); else printf("NO\n");
	}
}