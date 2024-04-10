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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char in[100050];
ll L[100050];
ll sum[100050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &L[i]);
		L[i] *= 2;
	}

	for (i = N; i >= 1; i--) sum[i] = sum[i + 1] + L[i];

	scanf("%s", in + 1);

	ll ans = 0;
	map <ll, ll> Mx;
	for (i = 1; i <= N; i++) {
		if (in[i] == 'W') {
			Mx[3] = LL_INF;

			ll left = L[i];

			// Step 1. Fly with left stamina
			ll l = min(Mx[0], left);
			Mx[0] -= l;
			ans += l;
			Mx[1] += 2 * l;
			left -= l;

			// Step 2. Walk -> Fly repeat
			ans += 2 * left;
			Mx[1] += left;
		}

		if (in[i] == 'G') {
			Mx[5] = LL_INF;

			ll left = L[i];

			// Step 1. Fly with left stamina
			ll l = min(Mx[0], left);
			Mx[0] -= l;
			ans += l;
			Mx[2] += 2 * l;
			left -= l;

			// Step 2. Fly with +1 stamina
			l = min(Mx[1], left);
			Mx[1] -= l;
			ans += 2 * l;
			Mx[2] += 2 * l;
			left -= l;

			// Step 3. Walk -> Fly repeat
			ans += 3 * left;
			Mx[2] += left;
		}
		if (in[i] == 'L') {
			for (ll j = 1; Mx[0] < L[i]; j++) {
				ll left = min(L[i] - Mx[0], Mx[j]);
				Mx[0] += left;
				Mx[j] -= left;
				ans += j * left;
			}
			Mx[0] -= L[i];
			ans += L[i];
		}
	}
	return !printf("%lld\n", ans / 2);
}