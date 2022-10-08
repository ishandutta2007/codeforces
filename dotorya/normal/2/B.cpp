#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int in[2][1050][1050];
int dp[1050][1050];
int rev[1050][1050];
int main() {
	int N, i, j, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%d", &t);
			if (t == 0) {
				in[0][i][j] = in[1][i][j] = 30;
				continue;
			}
			int x = 0;
			while (t % 2 == 0) {
				t /= 2;
				x++;
			}
			in[0][i][j] = x;
			x = 0;
			while (t % 5 == 0) {
				t /= 5;
				x++;
			}
			in[1][i][j] = x;
		}
	}
	
	int x;
	int mn = INF;
	vector <char> a;
	for (x = 0; x < 2; x++) {
		for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) dp[i][j] = INF;
		dp[1][1] = in[x][1][1];
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (i != N && dp[i + 1][j] > dp[i][j] + in[x][i + 1][j]) {
					dp[i + 1][j] = dp[i][j] + in[x][i + 1][j];
					rev[i + 1][j] = 0;
				}
				if (j != N && dp[i][j + 1] > dp[i][j] + in[x][i][j + 1]) {
					dp[i][j + 1] = dp[i][j] + in[x][i][j + 1];
					rev[i][j + 1] = 1;
				}
			}
		}

		i = N, j = N;
		vector<char> rv;
		while (i != 1 || j != 1) {
			assert(i && j);
			if (rev[i][j]) {
				rv.push_back('R');
				j--;
			}
			else {
				rv.push_back('D');
				i--;
			}
		}
		reverse(all(rv));
		if (mn > dp[N][N]) {
			mn = dp[N][N];
			a = rv;
		}
	}
	if (mn >= 2) {
		int x = -1, y = -1;
		for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
			if (in[0][i][j] == 30 && in[1][i][j] == 30) {
				x = i, y = j;
			}
		}
		if (x != -1) {
			mn = 1;
			vector <char> Vu;
			for (i = 1; i <= x - 1; i++) Vu.push_back('D');
			for (i = 1; i <= y - 1; i++) Vu.push_back('R');

			for (i = 1; i <= N - x; i++) Vu.push_back('D');
			for (i = 1; i <= N - y; i++) Vu.push_back('R');
			a = Vu;
		}
	}
	
	printf("%d\n", mn);
	for (auto it : a) printf("%c", it);
	return !printf("\n");
}