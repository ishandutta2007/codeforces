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

ll in[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N / 2; i++) scanf("%lld", &in[i * 2]);

	ll cur = 0;
	for (i = 2; i <= N; i += 2) {
		ll v = in[i];
		
		ll n1 = -1, n2 = -1;
		for (j = 1; j * j < v; j++) {
			if (v%j) continue;

			ll t1 = j, t2 = v / j;
			if (t1 % 2 != t2 % 2) continue;
			
			ll x1 = (t2 - t1) / 2;
			ll x2 = (t2 + t1) / 2;

			if (x1 <= cur) continue;
			n1 = x1, n2 = x2;
		}
		if (n1 == -1) return !printf("No\n");

		in[i - 1] = n1 * n1 - cur * cur;
		assert(in[i] == n2 * n2 - n1 * n1);
		cur = n2;
	}
	printf("Yes\n");
	for (i = 1; i <= N; i++) printf("%lld ", in[i]);
	return !printf("\n");
}