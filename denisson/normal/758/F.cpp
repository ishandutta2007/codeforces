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

int n, l, r;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll bp(ll a, int k) {
	if (k == 1) return a;
	if (k & 1) {
		return bp(a, k - 1) * a;
	} else {
		ll q = bp(a, k / 2);
		return q * q;
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
		//freopen("subrev.in", "r", stdin);
		//freopen("subrev.out", "w", stdout);
	}
	cin >> n >> l >> r;
	if (n == 1) {
		cout << r - l + 1;
		exit(0);
	}
	if (n == 2) {
		cout << (ll)(r - l + 1) * (ll)(r - l);
		exit(0);
	}
	if (n > 30) cout << 0, exit(0);
	int ma = (double)pow(r, (double)1 / (double)(n - 1)) + 7;
	ll ans = 0;
	for (int i = 1; i <= ma; i++) {
		for (int j = i + 1; j <= ma; j++) {
			if (gcd(i, j) != 1) continue;
			ll b = bp(i, n - 1);
			ll a = bp(j, n - 1);
			int l1 = ceil((double)l / a);
			int r1 = floor((double)r / a);
			int l2 = ceil((double)l / b);
			int r2 = floor((double)r / b);
			int lnow = max(l1, l2);
			int rnow = min(r1, r2);
			ans += max(0, rnow - lnow + 1);
		}
	}
	cout << ans * (ll)2;
}