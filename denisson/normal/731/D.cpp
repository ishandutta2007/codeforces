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


int n, c;
vector<vector<int> > d;
int l = -1, r = -1;
bool was[1000007];
int t[16 * 1000007];

void up(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l)
		return;
	if (vl >= l && vr <= r) {
		t[v] = 1;
	} else {
		int vm = (vl + vr) / 2;
		up(v * 2 + 1, vl, vm, l, r);
		up(v * 2 + 2, vm + 1, vr, l, r);
	}
}

bool get(int v, int vl, int vr, int pos) {
	if (t[v])
		return 1;
	if (vl == vr)
		return t[v];
	int vm = (vl + vr) / 2;
	if (pos <= vm)
		return get(v * 2 + 1, vl, vm, pos);
	else
		return get(v * 2 + 2, vm + 1, vr, pos);
}

void merge(int l1, int r1) {
	if (l == -1 && r == -1) {
		l = l1;
		r = r1;
		return;
	}
	l = max(l, l1);
	r = min(r, r1);
	if (l > r) {
		cout << -1;
		exit(0);
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "w", stdout);
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	/*cout << "100 207" << endl;
	int k = 103;
	for (int i = 0; i < 100; i++) {
		cout << 1 << ' ' << k << endl;
		k += rand() % 2 + 1;
		if (k > 207)
			k -= 207;
	}
	exit(0);*/
	cin >> n >> c;
	d.resize(n);
	forn(i, n) {
		int k;
		cin >> k;
		forn(j, k) {
			int z;
			cin >> z;
			d[i].pub(z);
		}
	}
	forn(i, n - 1) {
		//cout << i << endl;
		if (d[i].size() <= d[i + 1].size()) {
			bool f = 1;
			forn(j, d[i].size()) {
				if (d[i][j] != d[i + 1][j]) {
					f = 0;
					break;
				}
			}
			if (f)
				continue;
		}
		if (d[i].size() > d[i + 1].size()) {
			bool f = 1;
			for (int j = 0; j < d[i + 1].size(); j++) {
				if (d[i][j] != d[i + 1][j]) {
					f = 0;
					break;
				}
			}
			if (f) {
				cout << -1;
				exit(0);
			}
		}
		int len = min(d[i].size(), d[i + 1].size());
		forn(j, len) {
			if (d[i][j] > d[i + 1][j]) {
				int l1 = c - d[i][j] + 1;
				int r1 = c - d[i + 1][j];
				merge(l1, r1);
				break;
			} 
			if (d[i][j] < d[i + 1][j]) {
				int r1 = c - d[i + 1][j];
				int l1 = c - d[i][j];
				up(0, 0, 1000005, r1 + 1, l1);
				break;
			}
		}
	}
	if (l == -1)
		cout << 0, exit(0);
	for (int i = l; i <= r; i++) {
		if (!get(0, 0, 1000005, i))
			cout << i, exit(0);
	}
	cout << -1;
}