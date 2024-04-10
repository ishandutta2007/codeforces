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
#define x first
#define y second
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

struct reb {
	ll w, p, del, to;
	reb() {}
	reb(int to1, ll w1, ll p1) {
		to = to1;
		w = w1;
		p = p1;
		del = 0;
	}
};

int n;
vector<reb> g[2 * 100007];
map<pair<int, int>, ll> ma;
ll ha[2 * 100007];

ll dfs(int v) {
	ll sum = 0;
	for (int i = 0; i < g[v].size(); i++){
		auto t = g[v][i];
		ll now = dfs(t.to);
		if (now > t.p) {
			cout << -1;
			exit(0);
		}
		ll can = t.p - now;
		can = min(can, t.w - 1);
		g[v][i].del = can;
		ma[{v, t.to}] = g[v][i].del;
		sum += now + t.w - g[v][i].del;
	}
	ha[v] = sum;
	return sum;
}

vector<pair<pair<int, int>, pair<ll ,ll> > > was;

ll up(int v, ll can) {
	ll now = 0;
	for (reb t : g[v]) {
		if (now == can) break;
		now += (ll)t.del;
		if (now >= can) {
			ll ost = now - can;
			now = can;
			ma[{v, t.to}] = ost;
			break;
		} else {
			ma[{v, t.to}] = 0;
		}
		ll sd = up(t.to, min(t.p - ha[t.to], can - now));
		now += sd;
	}
	return now;
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
		//freopen("subrev.in", "r", stdin);
		//freopen("subrev.out", "w", stdout);
	}
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y, w, p;
		scanf("%d %d %d %d", &x, &y, &w, &p);
		x--; y--;
		g[x].pub(reb(y, w, p));
		was.pub({ { x, y }, {w, p} });
	}
	dfs(0);
	up(0, LINF);
	printf("%d\n", n);
	for (auto c : was) {
		int mi = ma[{c.x.x, c.x.y}];
		printf("%d %d %d %d\n", c.x.x + 1, c.x.y + 1, (int)(c.y.x - mi), (int)(c.y.y - mi));
	}
}