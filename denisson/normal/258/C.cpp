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

int n;
int a[100007];
int was[100007];
int q[100007], kk;

int get(int l, int r) {
	return was[r] - was[l - 1];
}

ll bp(ll a, int k) {
	if (k == 0)
		return 1;
	if (k == 1)
		return a;
	if (k & 1) {
		return a * bp(a, k - 1) % MOD;
	} else {
		ll q = bp(a, k / 2);
		return q * q % MOD;
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	cin >> n;
	int ma = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], ma = max(ma, a[i]), was[a[i]]++;
	for (int i = 1; i < 100007; i++)
		was[i] += was[i - 1];
	ll ans = 0;
	for (int i = ma; i >= 1; i--) {
		kk = 0;
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0)
				q[kk++] = j;
		}
		int ww = kk;
		for (int j = ww - 1; j >= 0; j--)
			if (i / q[j] != q[j])
				q[kk++] = i / q[j];
		ll now = 1;
		//for (int j = 0; j < kk; j++)
		//	cout << q[j] << ' ';
		q[kk++] = 100007;
		for (int j = 0; j < kk - 1; j++) {
			now = now * bp(j + 1, get(q[j], q[j + 1] - 1)) % MOD;
		}
		ll now2 = 1;
		q[kk - 2] = 100007;
		for (int j = 0; j < kk - 2; j++) {
			now2 = now2 * bp(j + 1, get(q[j], q[j + 1] - 1)) % MOD;
		}
		if (i == 1)
			now2 = 0;
		now -= now2;
		if (now < 0)
			now += MOD;
		//cout << "===" << now << endl;
		ans += now;
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans;
}