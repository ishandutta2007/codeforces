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

string s, t;
ll pr1[2 * 1000007];
ll pr2[2 * 1000007];
ll h1[2 * 1000007];
ll h2[2 * 1000007];
int sum[1000007];
int pref[1000007];
int suf[1000007];
int pref2[1000007];
int suf2[1000007];

void build() {
	pr1[0] = 1;
	pr2[0] = 1;
	for (int i = 0; i < t.size(); i++) {
		h1[i + 1] = (h1[i] + t[i]) * P1 % MOD1;
		h2[i + 1] = (h2[i] + t[i]) * P2 % MOD2;
		pr1[i + 1] = pr1[i] * P1 % MOD1;
		pr2[i + 1] = pr2[i] * P2 % MOD2;
	}
}

pair<ll, ll> get(int l, int r) {
	ll ans1 = (h1[r + 1] - h1[l] * pr1[r - l + 1]) % MOD1;
	if (ans1 < 0)
		ans1 += MOD1;
	ll ans2 = (h2[r + 1] - h2[l] * pr2[r - l + 1]) % MOD2;
	if (ans2 < 0)
		ans2 += MOD2;
	return mp(ans1, ans2);
}

bool ok(int q1, int q2) {
	int l = 0, r = s.size() + 1;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (get(q1, q1 + m - 1) == get(q2, q2 + m - 1))
			l = m;
		else
			r = m;
	}
	if (l == s.size())
		return 0;
	else
		return (t[q1 + l] < t[q2 + l]);
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "w", stdout);
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		sum[i] = sum[i - 1];
		if (s[i - 1] == '(')
			sum[i]++;
		else
			sum[i]--;
	}
	for (int i = 1; i <= s.size(); i++) {
		if (i == 0)
			pref[i] = sum[0];
		else
			pref[i] = max(pref[i - 1] + sum[i] - sum[i - 1], sum[i] - sum[i - 1]);
		if (i == 0)
			pref2[i] = sum[0];
		else
			pref2[i] = min(pref2[i - 1], sum[i]);
	}
	for (int i = (int)s.size(); i >= 1; i--) {
		if (i == (int)s.size())
			suf[i] = sum[i] - sum[i - 1];
		else
			suf[i] = max(suf[i + 1], sum[s.size()] - sum[i]);
		if (i == (int)s.size())
			suf2[i] = sum[i] - sum[i - 1];
		else
			suf2[i] = min(suf2[i + 1] + sum[i] - sum[i - 1], sum[i] - sum[i - 1]);
	}
	//
	t = s + s;
	build();
	int uk = -1;
	int bal = sum[s.size()];
	if (bal <= 0) {
		if (suf[1] <= 0)
			uk = 0;
		for (int i = 1; i < s.size(); i++) {
			int ma = max(pref[i], sum[i] + suf[i + 1]);
			if (ma <= 0) {
				if (uk == -1)
					uk = i;
				else {
					if (ok(i, uk))
						uk = i;
				}
			}
		}
		for (int i = 0; i < -bal; i++)
			cout << '(';
		for (int i = 0; i < s.size(); i++)
			cout << t[uk + i];
		exit(0);
	} else {
		if (pref2[s.size()] >= 0)
			uk = 0;
		for (int i = s.size(); i >= 2; i--) {
			int ma = min(suf2[i], pref2[i - 1] + (sum[s.size()] - sum[i - 1]) );
			//cout << i << ' ' << ma << endl;
			if (ma >= 0) {
				if (uk == -1)
					uk = i - 1;
				else {
					if (ok(i - 1, uk))
						uk = i - 1;
				}
			}
		}
		for (int i = 0; i < s.size(); i++)
			cout << t[uk + i];
		for (int i = 0; i < bal; i++)
			cout << ')';
		exit(0);

	}
}