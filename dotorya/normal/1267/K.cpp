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

int Co[25][25];
int cnt[25];
ll getans(int s) {
	if (cnt[0] < 0) return 0;

	ll rv = 1;
	int cur = 0;
	for (int i = s + 1; i >= 2; i--) {
		cur++;
		rv *= Co[cur][cnt[i - 1]];
		cur -= cnt[i - 1];
		if (cur < 0) return 0;
	}
	return rv;
}

int main() {
	for (int i = 0; i <= 22; i++) {
		Co[i][0] = Co[i][i] = 1;
		for (int j = 1; j < i; j++) Co[i][j] = Co[i - 1][j - 1] + Co[i - 1][j];
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		ll t;
		scanf("%lld", &t);
		vector <int> Vl;
		for (int i = 2; t; i++) {
			Vl.push_back(t%i);
			t /= i;
		}

		ll ans = 0;
		ll s = Vl.size();
		for (auto it : Vl) cnt[it]++;

		ans = getans(s);
		
		if (cnt[0] != 0 && cnt[s] == 0) {
			cnt[0]--;
			ans -= getans(s - 1);
		}
		printf("%lld\n", ans - 1);

		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}