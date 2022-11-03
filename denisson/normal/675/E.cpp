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

int n;
int a[100007];
pair<int, int> t[4 * 100007];
ll dp[100007];

pair<int, int> get(int v, int vl, int vr, int l, int r) {
	if (vr < l || vl > r)
		return mp(-INF, -INF);
	if (vl >= l && vr <= r) {
		return t[v];
	} else {
		int vm = (vl + vr) >> 1;
		return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
	}
}

void up(int v, int vl, int vr, int pos) {
	if (vl == vr) {
		t[v] = mp(a[pos], pos);
	} else {
		int vm = (vl + vr) >> 1;
		if (pos <= vm)
			up(v * 2 + 1, vl, vm, pos);
		else
			up(v * 2 + 2, vm + 1, vr, pos);
		t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
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
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> a[i], a[i]--;
	ll sum = 0;

	up(0, 0, n - 1, n - 1);

	for (int i = n - 2; i >= 0; i--) {
		pair<int, int> now = get(0, 0, n - 1, i + 1, a[i]);
		
		dp[i] = dp[now.second] + (n - 1 - i);
		dp[i] -= a[i] - now.second;

		up(0, 0, n - 1, i);

		sum += dp[i];
	}
	cout << sum;
}