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

string s1, s2;
int last[26];
vector<int> q1, q2;
vector<int> now;
int check[26];

vector<int> get(string &s) {
	vector<int> ans(s.size());
	for (int c = 0; c < 26; c++)
		last[c] = -1;
	for (int i = 0; i < s.size(); i++) {
		if (last[s[i] - 'a'] == -1)
			ans[i] = -1;
		else
			ans[i] = i - last[s[i] - 'a'];
		last[s[i] - 'a'] = i;
	}
	return ans;
}

bool ye(int a, int b, int d1, int d2) {
	if (d2 >= s2.size())
		return 0;
	if (d2 < now[d1])
		a = -1;
	return (a == b);
}

vector<int> pref(vector<int> a) {
	vector<int> ans(a.size());

	ans[0] = 0;

	for (int i = 1; i < a.size(); i++) {
		if (i == s2.size()) {
			ans[i] = 0;
			continue;
		}
		int j = ans[i - 1];
		while (j > 0 && !ye(a[i], a[j], i, j)) {
			j = ans[j - 1];
		}
		if (ye(a[i], a[j], i, j))
			j++;
		ans[i] = j;
	}

	return ans;
}

vector<int> ans;

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
	cin >> s1 >> s2 >> s1 >> s2;
	q1 = get(s1);
	q2 = get(s2);
	for (int i = 0; i < q2.size(); i++)
		now.pub(q2[i]);
	now.pub(INF);
	for (int j = 0; j < q1.size(); j++)
		now.pub(q1[j]);
	for (int c = 0; c < 26; c++)
		check[c] = -1;
	for (int i = 0; i < s2.size(); i++)
		check[s2[i] - 'a'] = i;
	vector<int> ha = pref(now);

	for (int i = s2.size() + 1, j = 0; i < ha.size(); i++, j++) {
		if (ha[i] == s2.size()) {
			vector<pair<char, char> > se;
			int st = j - (int)s2.size() + 1;
			for (int c = 0; c < 26; c++) {
				if (check[c] != -1) {
					char c1 = s2[check[c]];
					char c2 = s1[st + check[c]];
					se.pub(mp(min(c1, c2), max(c1, c2)));
				}
			}
			bool f = 1;
			for (int k1 = 0; k1 < se.size(); k1++)
				for (int k2 = 0; k2 < se.size(); k2++) {
					if (i != j && se[k1] != se[k2]) {
						if (se[k1].XX == se[k2].XX || se[k1].XX == se[k2].YY)
							f = 0;
						if (se[k1].YY == se[k2].XX || se[k1].YY == se[k2].YY)
							f = 0;
					}
				}
			if (f)
				ans.pub(st);
		}
	}

	cout << ans.size() << LN;
	for (int x : ans)
		cout << x + 1 << ' ';
}