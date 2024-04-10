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
int dp[77][77][77][2];
vector<int> t[3];

void up(int &x, int y) {
	if (y < x) x = y;
}

int get(int x, int k1, int k2, int k3) {
	int ans = 0;
	for (int i = 0; i < k1; i++) if (t[0][i] > x) ans++;
	for (int i = 0; i < k2; i++) if (t[1][i] > x) ans++;
	for (int i = 0; i < k3; i++) if (t[2][i] > x) ans++;
	return abs(k1 + k2 + k3 - (x + ans));
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
		//freopen("distance.in", "r", stdin);
		//freopen("distance.out", "w", stdout);
    }
	cin >> s >> s;
	for (int i = 0; i < s.size(); i++) { 
		if (s[i] == 'V') t[0].pub(i);
		else if (s[i] == 'K') t[1].pub(i);
		else t[2].pub(i);
	}
	for (int i = 0; i < 77; i++) for (int j = 0; j < 77; j++) for (int v = 0; v < 77; v++)
		dp[i][j][v][0] = INF, dp[i][j][v][1] = INF;
	dp[0][0][0][0] = 0;
	for (int i = 0; i <= t[0].size(); i++) for (int j = 0; j <= t[1].size(); j++) for (int v = 0; v <= t[2].size(); v++) {
		int p = min(dp[i][j][v][0], dp[i][j][v][1]);
		if (i != t[0].size()) up(dp[i + 1][j][v][1], p + get(t[0][i], i, j, v));
		if (j != t[1].size()) up(dp[i][j + 1][v][0], dp[i][j][v][0] +  get(t[1][j], i, j, v));
		if (v != t[2].size()) up(dp[i][j][v + 1][0], p + get(t[2][v], i, j, v));
	}
	cout << min(dp[t[0].size()][t[1].size()][t[2].size()][0], dp[t[0].size()][t[1].size()][t[2].size()][1]);
}