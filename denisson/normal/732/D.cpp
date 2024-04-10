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
#include <cassert>
 
using namespace std;
 
typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
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
//

int n, m;
int a[100007], b[100007];
int was[100007];

bool check(int ans) {
	for (int i = 0; i <= 100005; i++)
		was[i] = -1;
	for (int i = 0; i <= ans; i++) {
		was[a[i]] = i;
	}
	for (int i = 1; i <= m; i++)
		if (was[i] == -1)
			return 0;
	int k = 0;
	for (int i = 0; i <= ans; i++) {
		if (a[i] == 0 || was[a[i]] != i)
			k++;
		if (was[a[i]] == i) {
			if (k < b[a[i]])
				return 0;
			k -= b[a[i]];
		}
	}
	return 1;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	forn(i, n)
		cin >> a[i];
	forn(i, m)
		cin >> b[i + 1];
	int l = -1, r = n;
	while (l + 1 < r) {
		int nm = (l + r) / 2;
		if (check(nm))
			r = nm;
		else
			l = nm;
	}
	if (r + 1 > n)
		cout << -1, exit(0);
	cout << r + 1;
}