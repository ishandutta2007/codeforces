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

int n, k, m;
string s;
vector<pair<ll, ll> > q;

ll h1[2 * 1000007], h2[2 * 1000007], deg1[2 * 1000007], deg2[2 * 1000007];
ll hh1[2 * 1000007], hh2[2 * 1000007];

void build() {
	h1[0] = 0;
	h2[0] = 0;
	deg1[0] = 1;
	deg2[0] = 1;
	forn(i, s.size()) {
		h1[i + 1] = (h1[i] + s[i]) * P1 % MOD1;
		h2[i + 1] = (h2[i] + s[i]) * P2 % MOD2;
		deg1[i + 1] = deg1[i] * P1 % MOD1;
		deg2[i + 1] = deg2[i] * P2 % MOD2;
	}
}

pair<ll, ll> ah(string &s) {
	hh1[0] = 0;
	hh2[0] = 0;
	forn(i, s.size()) {
		hh1[i + 1] = (hh1[i] + s[i]) * P1 % MOD1;
		hh2[i + 1] = (hh2[i] + s[i]) * P2 % MOD2;
	}
	return mp(hh1[s.size()], hh2[s.size()]);
}

pair<ll, ll> get(int l, int r) {
	ll ans1 = (h1[r + 1] - h1[l] * deg1[r - l + 1] % MOD1 + MOD1) % MOD1;
	ll ans2 = (h2[r + 1] - h2[l] * deg2[r - l + 1] % MOD2 + MOD2) % MOD2;
	return mp(ans1, ans2);
}

map<pair<int, int>, int> ge;
int uk = 0;

void check() {
	cout << "YES" << LN;
	forn(i, n) {
		int kk = uk;
		cout << ge[get(kk + i * k, kk + (i + 1) * k - 1)] << ' ';
	}
	exit(0);
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
	cin >> n >> k >> s >> m;
	s += s;
	build();
	forn(i, m) {
		string now;
		cin >> now;
		q.pub(ah(now));
		ge[ah(now)] = i + 1;
	}
	for (uk = 0; uk < k; uk++) {
		set<pair<ll, ll> > se;
		
		forn(i, n) {
			auto now = get(uk + i * k, uk + (i + 1) * k - 1);
			se.insert(now);
		}

		if (se.size() == n) {
			bool f = 1;
			for (auto c : se) {
				if (ge[c] == 0)
					f = 0;
			}
			if (f)
				check();
		}
	}
	cout << "NO";
}