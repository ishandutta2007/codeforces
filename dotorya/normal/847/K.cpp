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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

map <pair<string, string>, int> Mx;
int ch(string a, string b) {
	if (a > b) swap(a, b);
	auto u = mp(a, b);
	if (Mx.count(u)) return Mx[u];
	int t = Mx.size() + 1;
	return Mx[u] = t;
}

string in[305][2];
int val[305];

ll tot[605];
int main() {
	int N, A, B, K, F, i, j, k;
	scanf("%d %d %d %d %d", &N, &A, &B, &K, &F);
	for (i = 1; i <= N; i++) cin >> in[i][0] >> in[i][1];
	for (i = 1; i <= N; i++) {
		val[i] = A;
		if (i != 1 && in[i][0] == in[i - 1][1]) val[i] = B;
		tot[ch(in[i][0], in[i][1])] += val[i];
	}

	vector <ll> Vu;
	for (i = 1; i <= Mx.size(); i++) Vu.push_back(tot[i]);
	sort(all(Vu), [](ll a, ll b) {
		return a > b;
	});
	for (i = 0; i < Vu.size() && i < K; i++) Vu[i] = min(Vu[i], (ll)F);

	ll ans = 0;
	for (auto it : Vu) ans += it;
	return !printf("%lld\n", ans);
}