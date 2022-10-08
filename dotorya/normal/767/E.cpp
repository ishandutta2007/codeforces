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
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

ll C[100050];
ll W[100050];
bool chk[100050];

ll cnt[100050];

vector <int> Vu;
int main() {
	ll N, M, i, j;
	scanf("%lld %lld", &N, &M);
	for (i = 1; i <= N; i++) scanf("%lld", &C[i]);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &W[i]);
		W[i] *= (100 - C[i] % 100) % 100;
	}

	ll v = -M;
	for (i = 1; i <= N; i++) {
		v += C[i] % 100;
		if (v < 0) cnt[i] = 0;
		else cnt[i] = (v + 99) / 100;
		while (Vu.size() < cnt[i]) Vu.push_back(i);
	}

	ll ans = 0;
	priority_queue <pll, vector<pll>, greater<pll>> Hx;
	for (i = 0, j = 1; i < Vu.size(); i++) {
		while (j <= N) {
			if (j > Vu[i]) break;
			if(W[j] != 0) Hx.emplace(W[j], j);
			j++;
		}
		ans += Hx.top().first;
		chk[Hx.top().second] = true;
		Hx.pop();
	}
	
	printf("%lld\n", ans);
	for (i = 1; i <= N; i++) {
		if (chk[i]) printf("%lld 0\n", C[i] / 100 + 1);
		else printf("%lld %lld\n", C[i] / 100, C[i] % 100);
	}
	return 0;
}