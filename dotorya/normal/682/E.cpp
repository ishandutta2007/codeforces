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

pll operator + (pll a, pll b) {
	return pll(a.first + b.first, a.second + b.second);
}
pll operator - (pll a, pll b) {
	return pll(a.first - b.first, a.second - b.second);
}
ll ccw(pll a, pll b) {
	ll rv = a.first * b.second - a.second * b.first;
	if (rv > 0) return 1;
	if (rv < 0) return -1;
	return 0;
}

pll in[5050];
vector <pll> Vch;
ll getarea(ll a, ll b, ll c, ll N) {
	pll u1 = in[b%N] - in[a%N];
	pll u2 = in[c%N] - in[a%N];
	return abs(u1.first*u2.second - u1.second*u2.first);
}
int main() {
	ll N, S, i, j, k;
	scanf("%lld %lld", &N, &S);
	for (i = 1; i <= N; i++) scanf("%lld %lld", &in[i].first, &in[i].second);
	sort(in + 1, in + N + 1);
	sort(in + 2, in + N + 1, [](pll a, pll b) {
		if(ccw(a-in[1], b - in[1])) return ccw(a - in[1], b - in[1]) > 0;
		return a < b;
	});
	Vch.push_back(in[1]);
	for (i = 2; i <= N; i++) {
		while (Vch.size() > 1) {
			pll u1 = Vch[Vch.size() - 2];
			pll u2 = Vch.back();
			if (ccw(u2 - u1, in[i] - u1) > 0) break;
			Vch.pop_back();
		}
		Vch.push_back(in[i]);
	}

	N = Vch.size();
	for (i = 0; i < N; i++) in[i] = Vch[i];
	ll mx = 0, a1 = 0, a2 = 0, a3 = 0;
	for (i = 0; i < N; i++) {
		for (j = i + 1, k = i + 2; j < i + N - 1; j++, k = max(k, j+1)) {
			pll u = in[j%N] - in[i%N];
			while (k < i + N && ccw(u, in[(k + 1) % N] - in[k%N]) > 0) k++;
			
			ll v = getarea(i, j, k, N);
			if (mx < v) {
				mx = v;
				a1 = i%N;
				a2 = j%N;
				a3 = k%N;
			}
		}
	}

	pll p1 = in[a1] + in[a2] - in[a3];
	pll p2 = in[a1] + in[a3] - in[a2];
	pll p3 = in[a2] + in[a3] - in[a1];

	printf("%lld %lld\n", p1.first, p1.second);
	printf("%lld %lld\n", p2.first, p2.second);
	printf("%lld %lld\n", p3.first, p3.second);
	return 0;
}