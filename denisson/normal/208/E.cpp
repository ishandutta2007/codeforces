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

int n, m, tt = 0;
vector<int> g[100007];
vector<int> st;
int h[100007];
int up[22][100007];
int tin[100007], tout[100007];
vector<int> q[100007];


void dfs(int v, int pred, int hh) {
	tin[v] = tt++;
	h[v] = hh;
	q[hh].pub(v);
	up[0][v] = pred;
	for (int l = 1; l <= 20; l++) {
		up[l][v] = up[l - 1][up[l - 1][v]];
	}
	for (int to : g[v]) {
		if (to != pred) {
			dfs(to, v, hh + 1);
		}
	}
	tout[v] = tt++;
}

int get(int v, int a) {
	for (int i = 20; i >= 0; i--) {
		if ((a >> i) & 1)
			v = up[i][v];
	}
	return v;
}

int check(int v, int lv) {
	int now = h[v] + lv;
	int l = -1, r = q[now].size();
	while (l + 1 < r) {
		int mm = ((l + r) >> 1);
		if (tin[q[now][mm]] > tout[v])
			r = mm;
		else
			l = mm;
	}
	int s = l;
	l = -1, r = q[now].size();
	while (l + 1 < r) {
		int mm = ((l + r) >> 1);
		if (tin[q[now][mm]] > tin[v])
			r = mm;
		else
			l = mm;
	}
	return s - l;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int z;
		scanf("%d", &z);
		if (z == 0) {
			st.pub(i);
		} else {
			z--;
			g[i].pub(z);
			g[z].pub(i);
		}
	}
	for (int x : st)
		dfs(x, x, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int v, lv;
		scanf("%d %d", &v, &lv);
		v--;
		if (h[v] < lv) {
			printf("0 ");
			continue;
		}
		int now = get(v, lv);
		printf("%d ", check(now, lv) - 1);
	}
}