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

string s, now, rs, rnow;
int n;
int ans = 0;
vector<int> a, b;
int ma[2 * 100007];

void zfunc(vector<int> &a, string s) {
	a.resize(s.size());
	a[0] = 0;
	for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
		a[i] = 0;
		if (i <= r)
			a[i] = min(r - i + 1, a[i - l]);
		while (i + a[i] < s.size() && s[a[i]] == s[a[i] + i])
			a[i]++;
		if (i + a[i] - 1 > r)
			r = i + a[i] - 1, l = i;
	}
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
	cin >> s >> n;
	rs = s;
	reverse(all(rs));
	for (int i = 0; i < n; i++) {
		cin >> now;
		if (now.size() == 1)
			continue;
		rnow = now;
		reverse(all(rnow));
		zfunc(a, now + "&" + s);
		zfunc(b, rnow + "&" + rs);
		bool f = 0;
		memset(ma, 0, sizeof(ma));
		for (int i = now.size() + 1, l = (int)s.size() - 1; i < b.size(); i++, l--) {
			ma[l] = max(ma[l + 1], b[i]);
		}
		for (int i = 0; i < s.size(); i++) {
			int ha = a[now.size() + 1 + i] + ma[i + now.size()];
			if (ha >= now.size()) {
				f = 1;
				break;
			}
		}

		if (f)
			ans++;
	}
	cout << ans;
}