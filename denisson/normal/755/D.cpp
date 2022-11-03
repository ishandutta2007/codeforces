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


int n, k;

struct fen {
	int a[1000007];
	fen() {
		memset(a, 0, sizeof(a));
	}
	void add(int v) {
		for (; v <= n; v += (v&-v))
			a[v]++;
	}
	int get(int v) {
		int ans = 0;
		for (; v > 0; v -= (v&-v))
			ans += a[v];
		return ans;
	}
	int get(int l, int r) {
		if (l > r) return 0;
		if (l == 0) return get(r);
		return get(r) - get(l - 1);
	}
};

fen t;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else { 
		//freopen("lines.in", "r", stdin);
		//freopen("lines.out", "w", stdout);
	}
	cin >> n >> k;
	k = min(k, n - k);
	ll ans = 1;
	int last = 1;
	for (int i = 0; i < n; i++) {
		int d = last + k;
		if (d > n) {
			d -= n;
			ans += (ll)t.get(last + 1, n) + (ll)t.get(1, d - 1) + 1;
		} else {
			ans += (ll)t.get(last + 1, d - 1) + 1;
		}
		t.add(d);
		t.add(last);
		last = d;
		cout << ans << ' ';
	}
}