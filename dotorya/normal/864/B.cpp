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

char in[205];
int cnt[26];
int main() {
	int N, i, j, k;
	scanf("%d %s", &N, in);

	int ans = 0;
	for (i = 0; in[i] != 0; i++) {
		if (in[i] >= 'A' && in[i] <= 'Z') continue;
		for (j = i; in[j] != 0; j++) if (in[j] >= 'A' && in[j] <= 'Z') break;

		for (k = i; k < j; k++) cnt[in[k] - 'a']++;

		int c = 0;
		for (k = 0; k < 26; k++) {
			if (cnt[k]) c++;
			cnt[k] = 0;
		}
		ans = max(ans, c);
	}
	return !printf("%d\n", ans);
}