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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int ans[26][1550];
char in[1550];
int main() {
	int N, i, j, k;
	scanf("%d %s", &N, in + 1);
	for (k = 0; k < 26; k++) {
		for (i = 1; i <= N; i++) {
			int c = 0;
			for (j = i; j <= N; j++) {
				if ('a' + k != in[j]) c++;
				ans[k][c] = max(ans[k][c], j - i + 1);
			}
		}
		for (i = 1; i <= N; i++) ans[k][i] = max(ans[k][i], ans[k][i - 1]);
	}

	scanf("%d", &k);
	while (k--) {
		char c[2];
		scanf("%d %s", &i, c);
		printf("%d\n", ans[c[0] - 'a'][i]);
	}
	return 0;
}