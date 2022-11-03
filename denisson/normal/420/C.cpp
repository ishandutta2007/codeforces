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

int n, p;
pair<int, int> a[3 * 100007];
vector<int> g[3 * 100007];
int t[4 * 3 * 100007];
int len[3 * 100007];

void up(int v, int vl, int vr, int pos, int val) {
	if (vl == vr) {
		t[v] += val;
	} else {
		int vm = (vl + vr) / 2;
		if (pos <= vm) {
			up(v * 2 + 1, vl, vm, pos, val);
		} else {
			up(v * 2 + 2, vm + 1, vr, pos, val);
		}
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

int get(int v, int vl, int vr, int l, int r) {
	if (vr < l || vl > r)
		return 0;
	if (vl >= l && vr <= r) {
		return t[v];
	} else {
		int vm = (vl + vr) / 2;
		return get(v * 2 + 1, vl, vm, l, r) + get(v * 2 + 2, vm + 1, vr, l, r);
	}
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
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].XX, &a[i].YY), a[i].XX--, a[i].YY--;
	for (int i = 0; i < n; i++)
		g[a[i].XX].pub(i), g[a[i].YY].pub(i);
	for (int i = 0; i < n; i++) {
		up(0, 0, n, g[i].size(), 1);
		len[i] = (int)g[i].size();
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		for (int x : g[i]) {
			int to = (a[x].XX == i ? a[x].YY : a[x].XX);
			up(0, 0, n, len[to], -1);
			up(0, 0, n, --len[to], 1);
 		}
		up(0, 0, n, len[i], -1);
		ans += (ll)get(0, 0, n, max(0, p - (int)g[i].size()), n);
		up(0, 0, n, len[i], 1);
		for (int x : g[i]) {
			int to = (a[x].XX == i ? a[x].YY : a[x].XX);
			up(0, 0, n, len[to]++, -1);
			up(0, 0, n, len[to], 1);
 		}
	}

	cout << ans / (ll)2;
}