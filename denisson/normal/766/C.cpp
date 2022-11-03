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
#define x first
#define y second
#define XX first
#define YY second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
const double pi = acos(-1.0);
 
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

string s;
int a[26];
int dp[1007];
int dp2[1007];
bool was[1007];

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("lamps.in", "r", stdin);
        //freopen("lamps.out", "w", stdout);
    }
	cin >> s >> s;
	for (int i = 0; i < 26; i++) cin >> a[i];
	dp[0] = 1;
	dp2[0] = 0;
	int ma = 0;
	for (int i = 1; i <= s.size(); i++) {
		int now = 0;
		dp2[i] = INF;
		memset(was, 0, sizeof(was));
		for (int j = i; j >= 1; j--) {
			now++;
 			was[s[j - 1] - 'a'] = 1;
			bool f = 0;
			for (int w = 0; w < 26; w++) {
				if (was[w] && a[w] < now) {
					now--;
					f = 1;
					break;
				}
			}
			if (f) break;
			dp[i] += dp[j - 1];
			dp2[i] = min(dp2[i], dp2[j - 1] + 1);
			if (dp[i] >= MOD) dp[i] -= MOD;
		}
		ma = max(ma, now);
	}

	cout << dp[s.size()] << "\n" << ma << "\n" << dp2[s.size()];
}