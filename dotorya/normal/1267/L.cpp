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

int cnt[26];
char in[1000050];

char ans[1050][1050];
int main() {
	int N, L, K, i, j, k;
	scanf("%d %d %d", &N, &L, &K);
	scanf("%s", in);
	for (i = 0; i < N*L; i++) cnt[in[i] - 'a']++;

	int S = 0, E = K - 1;
	for (i = 0; i < L; i++) {
		for (j = 0; j < 26; j++) {
			while (cnt[j]) {
				ans[S][i] = j + 'a';
				cnt[j]--;
				S++;
				if (S > E) break;
			}
			if (S > E) break;
		}
		S = K - 1;
		while (S > 0) {
			if (ans[S-1][i] != ans[S][i]) break;
			S--;
		}
	}

	for (i = 0; i < N; i++) for (j = 0; j < L; j++) {
		if (ans[i][j]) continue;
		for (k = 0; k < 26; k++) {
			if (!cnt[k]) continue;
			cnt[k]--;
			ans[i][j] = k + 'a';
			break;
		}
	}

	for (i = 0; i < N; i++) printf("%s\n", ans[i]);
	return 0;
}