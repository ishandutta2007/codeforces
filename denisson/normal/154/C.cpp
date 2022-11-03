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

const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }

struct hasher {
	size_t operator()(pair<int, int> t) const {
		return (ll)t.first * P1 + t.second;
	}
};

int n, m;
vector<int> g[1000007];
unordered_map<pair<int, int> , int, hasher> was;

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
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pub(b);
		g[b].pub(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(all(g[i]));
		ll ans1 = 0, ans2 = 0;
		for (int j = 0; j < g[i].size(); j++) {
			int to = g[i][j];
			ans1 = (ans1 * P1 + to) % MOD1;
			ans2 = (ans2 * P2 + to) % MOD2;
		}
		was[mp(ans1, ans2)]++;
	}
	ll ans = 0;
	for (auto c : was) {
		ans += (ll)c.YY * (c.YY - 1) / (ll)2;
	}
	for (int i = 1; i <= n; i++)
		g[i].pub(i);
	was.clear();
	for (int i = 1; i <= n; i++) {
		sort(all(g[i]));
		ll ans1 = 0, ans2 = 0;
		for (int j = 0; j < g[i].size(); j++) {
			int to = g[i][j];
			ans1 = (ans1 * P1 + to) % MOD1;
			ans2 = (ans2 * P2 + to) % MOD2;
		}
		was[mp(ans1, ans2)]++;
	}
	for (auto c : was) {
		ans += (ll)c.YY * (c.YY - 1) / (ll)2;
	}
	printf("%I64d", ans);
}