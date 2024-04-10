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
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

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

int n;
vector< pair<int, string> > g[100007];
string s;
int uk[26][3 * 100007];
int suf[3 * 100007];
int kk;
int ans = 0;

void dfs(int v) {
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		int now = kk;

		for (int j = 0; j < g[v][i].YY.size(); j++) {
			kk = uk[g[v][i].YY[j] - 'a'][kk];

			if (kk == (int)s.size() - 1)
				ans++;
		}

		dfs(to);
		kk = now;
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a;
		string s;
		cin >> a >> s;
		g[a - 1].pub(mp(i + 1, s));
	}

	cin >> s;

	s = 'a' + s;

	for (int i = 0; i < 3 * 100007; i++)
		suf[i] = 0;
	for (int c = 0; c < 26; c++) {
		for (int i = 0; i < 3 * 100007; i++)
			uk[c][i] = 0;
	}

	for (int i = 2; i < s.size(); i++) {
		int now = suf[i - 1];
		bool f = false;
		while (1) {
			if (s[now + 1] == s[i]) {
				suf[i] = now + 1;
				break;
			}
			if (now == 0) {
				if (f)
					break;
				f = 1;
			}
			now = suf[now];
		}
	}

	for (int c = 0; c < 26; c++) {
		for (int i = 0; i < s.size(); i++) {
			if (i < (int)s.size() - 1 && (s[i + 1] - 'a' == c))
				uk[c][i] = i + 1;
			else
				uk[c][i] = uk[c][suf[i]];
		}
	}

	dfs(0);

	cout << ans;
}