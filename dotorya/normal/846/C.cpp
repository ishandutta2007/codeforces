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

ll in[5050];
ll sum[5050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		sum[i] = sum[i - 1] + in[i];
	}

	ll ans = -sum[N], a1 = 0, a2 = 0, a3 = 0;
	ll mx = 0, p1 = 0, p2 = 0;
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= i; j++) {
			if (2 * sum[j] - 2 * sum[i] > mx) {
				mx = 2 * sum[j] - 2 * sum[i];
				p1 = j, p2 = i;
			}	
		}
		if (ans < mx + sum[i] * 2 - sum[N]) {
			ans = mx + sum[i] * 2 - sum[N];
			a1 = p1, a2 = p2, a3 = i;
		}
	}
	printf("%lld %lld %lld\n", a1, a2, a3);
	return 0;
}