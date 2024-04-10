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

string s;
ll ans;
ll dr;

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
	cin >> s;
	s += '+';
	ll now = 0;
	for (int i = 0; i < s.size();) {
		if (s[i] == '.') {
			if (s[i + 3] < '0' || s[i + 3] > '9') {
				ans += now;
				now = 0;
				dr += (s[i + 1] - '0') * 10 + s[i + 2] - '0';
				i += 3;
			}
		} else {
			if (s[i] >= '0' && s[i] <= '9')
				now = now * (ll)10 + s[i] - '0';
			else
				ans += now, now = 0;
		}
		i++;
	}
	ans += dr / 100;
	dr %= 100;
	//cout << ans << ' ' << dr << endl;
	vector<int> q;
	while (ans > 0) {
		q.pub(ans % 10);
		ans /= 10;
	}
	if (q.size() == 0)
		q.pub(0);
	reverse(all(q));
	for (int i = 0; i < q.size(); i++) {
		cout << q[i];
		if (((int)q.size() - i - 1) % 3 == 0 && i != (int)q.size() - 1)
			cout << '.';
	}
	if (dr == 0)
		exit(0);
	cout << '.';
	if (dr < 10)
		cout << 0;
	cout << dr;
}