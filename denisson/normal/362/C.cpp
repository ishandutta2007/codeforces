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
int a[5007];
int d[5007][5007];

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
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = d[i][j - 1] + (a[j] > a[i]);
		}
	}
	int p = 0, k1 = 0, k2 = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += d[i][i];
	int k = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == j)
				continue;

			int t1 = d[i][i] + d[j][j];
			int t2 = d[j][i - 1] + d[i][j];

			int s = t1 - t2;
			if (abs(i - j) > 1) {
				int kk = abs(i - j) - 1;
				int tt1 = kk - (d[i][j - 1] - d[i][i]);
				int tt2 = kk - (d[j][j - 1] - d[j][i]);
				s += tt1 - tt2;
			}

			//cout << i << ' ' << j << ' ' << s << endl;

			if (s > p) {
				p = s;
				k1 = i;
				k2 = j;
				k = 1;
			} else if (s == p) k++;
		}
	}
	cout << ans - p << ' ' << k;
}