#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

pii indt[300000][3][11];

char in[100050];
int main() {
	scanf("%s", in);

	int N = strlen(in), i, j, k;
	for (i = 1; i <= 2 * IT_MAX; i++) for (j = 0; j < 11; j++) indt[i][0][j] = indt[i][1][j] = indt[i][2][j] = pii(0, -1);

	for (i = 0; i < N; i++) {	
		int v = in[i] - '0';
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 11; k++) {
				int si1, si2;
				if (j == 0) si1 = 10, si2 = 9;
				else if (j == 1) si1 = 9, si2 = 10;
				else si1 = 9, si2 = 0;

				if (v >= (si2+k) % 11) continue;

				indt[IT_MAX + i][j][k].first = 1;

				int t1 = (si2 + k) % 11;
				int t2 = si2;
				int p = t1 * (t1 + 1) / 2 - t2 * (t2 + 1) / 2;
				p -= t1;
				p += v + 1;
				p = (p % 11 + 11) % 11;
				indt[IT_MAX + i][j][k].second = p;
			}
		}
	}
	for (i = IT_MAX - 1; i >= 1; i--) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 11; k++) {
				if (indt[2 * i][j][k].second == -1) indt[i][j][k] = indt[2 * i][j][k];
				else {
					int nx = min(j, 1) + indt[2 * i][j][k].first;
					nx %= 2;

					int nv = indt[2 * i][j][k].second;
					indt[i][j][k].first = indt[2 * i][j][k].first + indt[2 * i + 1][nx][nv].first;
					indt[i][j][k].second = indt[2 * i + 1][nx][nv].second;
				}
			}
		}
	}

	ll ans = 0;
	for (i = 0; i < N; i++) {
		if (in[i] == '0') continue;

		ans++;
		int nx = 2;
		int nv = in[i] - '0';
		int n = IT_MAX + i;
		while (1) {
			if (n % 2 == 0) {
				pii u = indt[n + 1][nx][nv];
				ans += u.first;

				nx = min(nx, 1) + u.first;
				nx %= 2;
				nv = u.second;
				if (nv == -1) break;
			}
			n /= 2;
		}
	}
	return !printf("%lld\n", ans);
}