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

int k;
string s, t;
ll h1[8 * 100007];
//ll h2[8 * 100007];
ll pr1[8 * 100007];
//ll pr2[8 * 100007];

inline void up(ll &x, bool f) {
	if (!f) {
		if (x >= MOD1)
			x -= MOD1;
		if (x < 0)
			x += MOD1;
	} else {
		if (x >= MOD2)
			x -= MOD2;
		if (x < 0)
			x += MOD2;
	}
}

//fen
ll fe[8 * 100007];
inline void up2(int v, ll d){
    /*
    fe[v].XX += d.XX;
    fe[v].YY += d.YY;
    up(fe[v].XX, 0);
    up(fe[v].YY, 1);

    return;
    */
    for (; v <= s.size(); v = (v | (v + 1))) {
		fe[v] += d;
		//fe[v].YY += d.YY;
        up(fe[v], 0);
        //up(fe[v].YY, 1);
    }
}

inline void upf(int l, int r, ll d){
    up2(l, d);
    up2(r + 1, -d);
}

inline ll gett(int v){
    ll ans = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1){
        ans += fe[v];
        //ans.YY += fe[v].YY;
        up(ans, 0);
        //up(ans.YY, 1);
    }

    return ans;
}
//

inline void build() {
	pr1[0] = 1;
	//pr2[0] = 1;
	for (int i = 0; i < s.size(); i++) {
		h1[i + 1] = (h1[i] + (ll)s[i] * pr1[i]) % MOD1;
		//h2[i + 1] = (h2[i] + (ll)s[i] * pr2[i]) % MOD2;
		pr1[i + 1] = pr1[i] * P1 % MOD1;
		//pr2[i + 1] = pr2[i] * P2 % MOD2;
		upf(i + 1, i + 1, h1[i + 1]);
	}
}

inline bool get(int l1, int r1, int l2, int r2) {
	int len = (int)s.size() - 1;
	int ll = len - r2;
	int rr = len - l2;
	l2 = ll;
	r2 = rr;
	long long q1 = gett(l1);
	long long q2 = gett(r1 + 1);
	long long q3 = gett(l2);
	long long q4 = gett(r2 + 1);
	bool f1 = (((q2 - q1 + MOD1) * pr1[l2] % MOD1) == ((q4 - q3 + MOD1) * pr1[l1] % MOD1));
	//bool f2 = (((q2.YY - q1.YY + MOD2) * pr2[l2] % MOD2) == ((q4.YY - q3.YY + MOD2) * pr2[l1] % MOD2));
	//bool f1 = (((h1[r1 + 1] - h1[l1] + MOD1) * pr1[l2] % MOD1) == ((h1[r2 + 1] - h1[l2] + MOD1) * pr1[l1] % MOD1));
	//bool f2 = (((h2[r1 + 1] - h2[l1] + MOD2) * pr2[l2] % MOD2) == ((h2[r2 + 1] - h2[l2] + MOD2) * pr2[l1] % MOD2));
	return (f1);
}

inline void change(int uk, char c) {
	ll d1 = (c - t[uk]) * pr1[uk] % MOD1;
	//ll d2 = (c - t[uk]) * pr2[uk] % MOD2;
	upf(uk + 1, (int)s.size() - 1, d1);

	d1 = (c - t[uk]) * pr1[(int)s.size() - uk - 1] % MOD1;
	//d2 = (c - t[uk]) * pr2[(int)s.size() - uk - 1] % MOD2;

	upf((int)s.size() - uk, (int)s.size() - 1, d1);

	t[uk] = c;
	s[uk] = c;
	s[(int)s.size() - 1 - uk] = c;
}

inline bool pal(int l, int r) {
	int len = r - l + 1;
	int d = len / 2;
	if (len & 1) {
		return get(l, l + d - 1, l + d + 1, r);
	} else {
		return get(l, l + d - 1, l + d, r);
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
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	cin >> k >> t;
	s = t;
	reverse(all(t));
	s += t;
	reverse(all(t));
	if (k == 1)
		cout << "Impossible", exit(0);
	build();
	int uk = (int)t.size() - 1;
	for (int i = 0; i < t.size(); i++) {
		if (i + k - 1 < t.size() && pal(i, i + k - 1))
			uk = min(uk, i + k - 1);
		if (i + k < t.size() && pal(i, i + k))
			uk = min(uk, i + k);
	}
	bool ff = 0;
	for (int i = uk; i >= 0; i--) {
		for (int c = t[i] - 'a' + 1; c < 26; c++) {
			change(i, c + 'a');
			bool f1 = 0, f2 = 0;
			if (i - k + 1 >= 0)
				f1 = pal(i - k + 1, i);
			if (i - k >= 0)
				f2 = pal(i - k, i);
			if (!f1 && !f2) {
				ff = 1;
				break;
			}
		}
		if (ff) {
			uk = i;
			break;
		}
	}
	if (!ff)
		cout << "Impossible", exit(0);
	for (int i = uk + 1; i < t.size(); i++)
		change(i, 'a');
	for (int i = 0; i < t.size(); i++) {
		while (1) {
			bool f1 = 0, f2 = 0;
			if (i - k + 1 >= 0)
				f1 = pal(i - k + 1, i);
			if (i - k >= 0)
				f2 = pal(i - k, i);
			if (f1 || f2)
				change(i, t[i] + 1);
			else
				break;
		}
	}
	cout << t << endl;
}