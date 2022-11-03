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

const int magic = 100;

const int dd = 1000007;

int n, k;
vector<int> g[1000007];
bool was[1000007];
bitset<dd> dp;
int sz;
int kol[107];

void dfs(int v) {
	was[v] = 1;
	sz++;
	for (int to : g[v])
		if (!was[to]) dfs(to);
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
		//freopen("lines.in", "r", stdin);
		//freopen("lines.out", "w", stdout);
	}
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int to;
		scanf("%d", &to);
		to--;
		g[i].pub(to);
		g[to].pub(i);
	}
	multiset<int> s;
	vector<int> s2;
	for (int i = 0; i < n; i++) {
		if (was[i]) continue;
		sz = 0;
		dfs(i);
		s.insert(sz);
		s2.pub(sz);
		if (sz <= magic) kol[sz]++;
	}
	int ans = 0;
	int p = k;
	while (s.size()) {
		if (k == 0) break;
		int now = *(--s.end());
		s.erase(--s.end());
		ans += min(2, now);
		if (now - 2 > 0) s.insert(now - 2);
		k--;
	}
	//

	dp[0] = 1;
	memset(was, 0, sizeof(was));

	for (int x : s2) {
		if (x > magic) {
			dp |= (dp << x);
		} else {
			if (was[x]) continue;
			was[x] = 1;
			for (int i = 0; i < x; i++) {
				int d = INF;
				for (int j = i; j <= n; j += x) {
					if (dp[j] == 1) {
						d = 0;
					} else {
						if (kol[x] >= d)
							dp[j] = 1;
					}
					d++;
				}
			}
		}
	}
	//
	cout << p + 1 - (dp[p] == 1) << ' ' << ans;
}