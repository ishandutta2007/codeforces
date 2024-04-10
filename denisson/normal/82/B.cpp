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
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
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

int n;
vector<int> a[207 * 207];
int was[207][207];
bool ss[207];
bool ha[207];

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	cin >> n;
	if (n == 2) {
		vector<int> now;
		cin >> n;
		now.resize(n);
		forn(i, n)
			cin >> now[i];
		cout << 1 << ' ' << now[0] << endl;
		cout << (int)now.size() - 1 << ' ';
		for (int i = 1; i < now.size(); i++)
			cout << now[i] << ' ';
		exit(0);
	}
	forn(i, 205)
		forn(j, 205)
			was[i][j] = 1;
	forn(i, n * (n - 1) / 2) {
		int sz;
		cin >> sz;
		a[i].resize(sz);
		forn(j, sz)
			cin >> a[i][j];
		set<int> qq;
		forn(j, a[i].size())
			qq.insert(a[i][j]);
		forn(j, sz) {
			ha[a[i][j]] = 1;
			forn(k, 205)
				if (was[a[i][j]][k]) {
					if (qq.find(k) == qq.end())
						was[a[i][j]][k] = 0;
				}
		}
	}
	forn(i, 205)
		if (!ss[i] && ha[i]) {
			vector<int> ans;
			forn(j, 205)
				if (was[i][j])
					ans.pub(j);
			if (ans.size() > 0) {
				forn(j, ans.size())
					ss[ans[j]] = 1;
				cout << ans.size() << ' ';
				forn(j, ans.size())
					cout << ans[j] << ' ';
				cout << LN;
			}
		}

}