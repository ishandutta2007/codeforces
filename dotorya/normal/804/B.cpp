#include <stdio.h>  
#include <algorithm>  
#include <assert.h>  
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
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <pair<ll, char>> Vu;
char in[1000050];
int main() {
	scanf("%s", in);

	int i, j;
	for (i = 0; in[i] != 0; i++) {
		if (Vu.empty() || Vu.back().second == 'a' || Vu.back().second != in[i]) Vu.emplace_back(1, in[i]);
		else Vu.back().first++;
	}

	while (!Vu.empty()) {
		if (Vu.back().second == 'a') Vu.pop_back();
		else break;
	}
	if (Vu.empty()) return !printf("0\n");

	while (Vu.size() > 1) {
		if (Vu[Vu.size() - 2].second == 'b') {
			Vu[Vu.size() - 2].first = (Vu[Vu.size() - 2].first + Vu.back().first) % MOD;
			Vu.pop_back();
			continue;
		}
		else {
			ll t = Vu.back().first;
			Vu.pop_back();
			Vu.pop_back();
			Vu.emplace_back(t * 2 % MOD, 'b');
		}
	}

	ll ans = Vu[0].first;
	for (i = 0; in[i] != 0; i++) if (in[i] == 'b') ans = (ans + MOD - 1) % MOD;
	return !printf("%lld\n", ans);
}