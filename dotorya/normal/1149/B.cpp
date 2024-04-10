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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int dp[255][255][255];
int in2[3][255];
int L[3];


char in[100050];
int nxt[26][100050];

int main() {
	int N, Q, i, j, k;
	scanf("%d %d %s", &N, &Q, in + 1);
	for (i = 0; i < 26; i++) nxt[i][N + 1] = N + 1, nxt[i][N + 2] = N + 1;
	for (i = N; i >= 1; i--) {
		for (j = 0; j < 26; j++) nxt[j][i] = nxt[j][i + 1];
		nxt[in[i] - 'a'][i] = i;
	}

	while (Q--) {
		int t;
		char c1[2];
		char c2[2];
		scanf("%s %d", c1, &t);
		t--;

		if (c1[0] == '-') {
			L[t]--;
			if (dp[L[0]][L[1]][L[2]] <= N) printf("YES\n");
			else printf("NO\n");
			continue;
		}

		scanf("%s", c2);

		L[t]++;
		in2[t][L[t]] = c2[0] - 'a';
		
		int st[3], en[3];
		for (i = 0; i < 3; i++) {
			st[i] = en[i] = L[i];
			if (i != t) st[i] = 0;
		}
		

		for (i = st[0]; i <= en[0]; i++) {
			for (j = st[1]; j <= en[1]; j++) {
				for (k = st[2]; k <= en[2]; k++) {
					dp[i][j][k] = N + 1;
					if (i) dp[i][j][k] = min(dp[i][j][k], nxt[in2[0][i]][dp[i - 1][j][k] + 1]);
					if (j) dp[i][j][k] = min(dp[i][j][k], nxt[in2[1][j]][dp[i][j - 1][k] + 1]);
					if (k) dp[i][j][k] = min(dp[i][j][k], nxt[in2[2][k]][dp[i][j][k - 1] + 1]);
				}
			}
		}

		if (dp[L[0]][L[1]][L[2]] <= N) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}