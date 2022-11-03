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

struct kek {
	db b, k, x;
	kek() {}
	kek(db b1, db k1, db x1) { b = b1, k = k1, x = x1; }
};
int n, k;
int t[200001];
db dp[51][200001];
ll sum[200001];
db obr[200001];
db ans[200001];

db getx(db b1, db k1, db b2, db k2) {
	return (b2 - b1) / (k1 - k2);
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
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}

	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 200001; j++)
			dp[i][j] = LINF;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + t[i];
		obr[i] = obr[i - 1] + (db)1 / t[i];
		ans[i] = ans[i - 1] + (db)sum[i] / t[i];
		dp[1][i] = ans[i];
	}

	for (int kk = 2; kk <= k; kk++) {
		dp[kk][kk] = kk;
		vector<kek> st;

		st.pub(kek(dp[kk - 1][kk - 1] - ans[kk - 1] + sum[kk - 1] * obr[kk - 1], -sum[kk - 1], 0));

		for (int i = kk + 1; i <= n; i++) {

			db x = obr[i];
			int l = 0, r = (int)st.size();
			while (l + 1 < r) {
				int mm = (l + r) >> 1;
				if (st[mm].x <= x)
					l = mm;
				else
					r = mm;
			}
			dp[kk][i] = min(st[l].k * x + st[l].b + ans[i], dp[kk - 1][i - 1] + 1);
			db k = -sum[i - 1];
			db b = dp[kk - 1][i - 1] - ans[i - 1] + sum[i - 1] * obr[i - 1];


			while (st.size() > 0) {
				kek last = st.back();
				db x = getx(b, k, last.b, last.k);
				if (x > last.x) {
					st.pub(kek(b, k, x));
					break;
				}
				else
					st.pop_back();
			}

			if (st.size() == 0)
				st.pub(kek(b, k, 0));
		}
		//dp[kk][i] = min(dp[kk][i], dp[kk - 1][j - 1] - ans[j - 1] - sum[j - 1] * (obr[i] - obr[j - 1]));
	}

	cout.precision(8);
	cout << fixed << dp[k][n];
}