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
int a[10];
ll dp[107][10];
ll fac[107];
ll revfac[107];


ll cnk(ll n, ll k) {
	if (n == k || k == 0)
		return 1;
	return (fac[n] * revfac[k] % MOD) * revfac[n - k] % MOD;
}

ll bp(ll a, ll k) {
	if (k == 1)
		return a;
	if (k & 1) {
		return bp(a, k - 1) * a % MOD;
	} else {
		ll q = bp(a, k / 2);
		return q * q % MOD;
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
	fac[1] = 1;
	for (int i = 2; i < 107; i++)
		fac[i] = fac[i - 1] * i % MOD;
	for (int i = 1; i < 107; i++)
		revfac[i] = bp(fac[i], MOD - 2);
	cin >> n;
	for (int i = 0; i <= 9; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
			dp[i][9] = (i >= a[9]);
	for (int i = 8; i >= 0; i--) {
		if (a[i] == 0 && dp[0][i + 1])
			dp[0][i] = 1;
		else
			dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 8; j >= 0; j--) {
			if (i < a[j]) {
				dp[i][j] = 0;
				continue;
			}
			for (int k = a[j]; k <= i; k++) {
				dp[i][j] = (dp[i][j] + dp[i - k][j + 1] * cnk(i - (j == 0), k)) % MOD;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp[i][0]) % MOD;
	cout << ans;
}