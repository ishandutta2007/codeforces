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

int n, k;
string s;
ll dp[26];
ll ans = 1;
int uk[26];

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	for (int i = 0; i < 26; i++)
		uk[i] = -1;
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		ll last = ans;
		ans = ((ll)2 * ans - dp[s[i] - 'a'] + MOD) % MOD;
		dp[s[i] - 'a'] = last;
		uk[s[i] - 'a'] = i;
	}
	
	for (int i = 0; i < n; i++) {
		ll last = ans;
		int now = 0;
		for (int c = 0; c < k; c++) {
			if (uk[c] < uk[now])
				now = c;
		}
		ans = ((ll)2 * ans - dp[now] + MOD) % MOD;
		uk[now] = i + s.size();
		dp[now] = last;
	}

	cout << ans;
}