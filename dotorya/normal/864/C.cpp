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

vector <int> Vu;
int main() {
	ll A, B, F, K, i;
	scanf("%lld %lld %lld %lld", &A, &B, &F, &K);

	ll prv = 0;
	for (i = 1; i <= K; i++) {
		if (i % 2 == 1) {
			prv += F;
			Vu.push_back(prv);
			prv = A - F;
		}
		else {
			prv += A - F;
			Vu.push_back(prv);
			prv = F;
		}
	}
	Vu.push_back(prv);

	for (i = 0; i < Vu.size(); i++) if (B < Vu[i]) return !printf("-1\n");

	int ans = 0;
	ll cur = B;
	for (i = 0; i < Vu.size(); i++) {
		cur -= Vu[i];
		if (i + 1 != Vu.size() && cur < Vu[i + 1]) {
			ans++;
			cur = B;
		}
	}
	return !printf("%d\n", ans);
}