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
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
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
//

struct bor {
	vector<int> g;
	//int uk[26];
	int su[26];
	map<int, int> uk;
	bool f;
	int suf, kol, tin, tout;
	bor() {
		f = 0;
		suf = 0;
		kol = 0;
	}
};

int n, k;
int sz = 1;
bool was[100007];
bor t[1000007];
int ge[100007];
int tt = 0;
int fen[2 * 1000007];

string sss;

void add(int ss) {
	int v = 0;
	for (int i = 0; i < sss.size(); i++) {
		char c = sss[i] - 'a';
		if (!t[v].uk.count(c)) {
			t[v].uk[c] = sz++;
		} 
		v = t[v].uk[c];
	}
	t[v].f = 1;
	ge[ss] = v;
}

void dfs(int v) {
	t[v].tin = tt++;
	for (int i = 0; i < t[v].g.size(); i++) {
		int to = t[v].g[i];
		dfs(to);
	}
	t[v].tout = tt++;
}

void up(int v, int val) {
	for (; v <= 2 * 1000005; v = (v | (v + 1)))
		fen[v] += val;
}

void up(int l, int r, int val) {
	up(l, val);
	up(r + 1, -val);
}

int get(int v) {
	int ans = 0;
	for (; v >= 0; v = (v & (v + 1)) - 1)
		ans += fen[v];
	return ans;
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
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	/*cout << 1 << ' ' << 1 << endl;
	for (int i = 0; i < 1e6; i++)
		cout << 'a';
	cout << endl;
	cout << "?";
	for (int i = 0; i < 1e6; i++)
		cout << 'a';
	exit(0);*/
	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		//scanf("%s", &sss);
		cin >> sss;
		was[i] = 1, add(i);
	}
	

	// suff
	
	vector<int> s;
	int uk = 0;
	s.pub(0);
	while (uk < s.size()) {
		int v = s[uk++];
		t[v].kol = (int)t[v].f + t[t[v].suf].kol;
		for (int c = 0; c < 26; c++) {
			if (t[v].uk.count(c)) {
				int to = t[v].uk[c];
				int ha = t[v].suf;
				bool ff = 0;
				while (1) {
					if (t[ha].uk.count(c)) {
						t[to].suf = t[ha].uk[c];
						break;
					}
					ha = t[ha].suf;
					if (ha == 0) {
						if (ff)
							break;
						ff = 1;
					}
				}
				if (v == 0)
					t[to].suf = 0;
				t[t[to].suf].g.pub(to);
				s.pub(to);
			}
		}
	}
	s.clear();
	uk = 0;
	s.pub(0);
	while (uk < s.size()) {
		int v = s[uk++];

		for (int b = 0; b < 26; b++) {
			if (t[v].uk.count(b))
				t[v].su[b] = t[v].uk[b];
			else
				t[v].su[b] = t[t[v].suf].su[b];
		}

		for (int c = 0; c < 26; c++) {
			if (t[v].uk.count(c))
				s.pub(t[v].uk[c]);
		}
	}
	//
	dfs(0);
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == '?') {
			cin >> sss;
			//scanf("%s", &sss);
			ll ans = 0;

			int v = 0;
			for (int i = 0; i < sss.size(); i++) {
				int c = sss[i] - 'a';
				v = t[v].su[c];
				ans += t[v].kol + get(t[v].tin);
			}

			cout << ans << LN;
		} else {
			int num;
			//scanf("%d", &num);
			cin >> num;
			num--;
			if (c == '+') {
				if (!was[num]) {
					int l = ge[num];
					up(t[l].tin, t[l].tout, 1);
				}
				was[num] = 1;
			} else {
				if (was[num]) {
					int l = ge[num];
					up(t[l].tin, t[l].tout, -1);
				}
				was[num] = 0;
			}
		}
	}
}