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

string s1, s2;
int n;
int a[26][26];

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
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++)
			a[i][j] = INF;
		a[i][i] = 0;
	}
	cin >> s1 >> s2 >> n;
	if (s1.size() != s2.size())
		cout << -1, exit(0);
	for (int i = 0; i < n; i++) {
		char c1, c2;
		int d;
		cin >> c1 >> c2 >> d;
		a[c1 - 'a'][c2 - 'a'] = min(a[c1 - 'a'][c2 - 'a'], d);
	}
	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}

	string ans;
	ll anss = 0;

	for (int i = 0; i < s1.size(); i++) {
		int cl = 0;
		int c1 = s1[i] - 'a', c2 = s2[i] - 'a';
		for (int c = 0; c < 26; c++) {
			if (a[c1][c] + a[c2][c] < a[c1][cl] + a[c2][cl])
				cl = c;
		}
		if (a[c1][cl] == INF || a[c2][cl] == INF)
			cout << -1, exit(0);
		ans += (char)('a' + cl);
		anss += a[c1][cl] + a[c2][cl];
	}
	cout << anss << "\n" << ans;
}