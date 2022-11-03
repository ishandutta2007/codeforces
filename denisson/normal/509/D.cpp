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

int n, m;
ll a[107][107];
ll q1[107];
ll q2[107];
ll q3[107];
ll q4[107];
ll ma;

void check(ll mod) {
	if (ma >= mod)
		return;

	for (int i = 0; i < n; i++) {
		q3[i] = q1[i] % mod;
		if (q3[i] < 0)
			q3[i] += mod;
	}
	for (int i = 0; i < m; i++) {
		q4[i] = q2[i] % mod;
		if (q4[i] < 0)
			q4[i] += mod;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((q3[i] + q4[j]) % mod != a[i][j])
				return;
		}
	}

	cout << "YES" << "\n" << mod << "\n";
	for (int i = 0; i < n; i++)
		cout << q3[i] << ' ';
	cout << "\n";
	for (int j = 0; j < m; j++)
		cout << q4[j] << ' ';
	exit(0);

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
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	ma = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ma = max(ma, a[i][j]);
		}
	}

	for (int j = 0; j < m; j++) {
		q2[j] = a[0][j];
	}
	for (int i = 0; i < n; i++) {
		q1[i] = a[i][0] - q2[0];
	}

	ll dl = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (q1[i] + q2[j] != a[i][j]) {
				int rz = abs(a[i][j] - q1[i] - q2[j]);
				if (rz != 0)
					dl = rz;
			}
		}
	}
	if (dl == -1) {
		cout << "YES" << "\n" << (ll)(1e16) << "\n";
		for (int i = 0; i < n; i++) {
			if (q1[i] < 0)
				q1[i] += (ll)(1e16);
			cout << q1[i] << ' ';
		}
		cout << "\n";
		for (int i = 0; i < m; i++) {
			if (q2[i] < 0)
				q2[i] += (ll)(1e16);
			cout << q2[i] << ' ';
		}
		exit(0);
	}
	for (ll j = 1; j * j <= dl; j++) {
		if (dl % j == 0) {
			check(j);
			check(dl / j);
		}
	}
	cout << "NO";
}