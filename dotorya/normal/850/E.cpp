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

vector<ll> mymul(vector<ll> A, vector<ll> B) {
	
	if (A.size() == 1 && B.size() == 1) {
		vector <ll> rv(1);
		rv[0] = A[0] * B[0];
		return rv;
	}
	
	int N = A.size(), i, j;
	vector <ll> Vu1;
	vector <ll> Vu2;
	vector <ll> rv1;
	vector <ll> rv2;
	for (i = 0; i < N / 2; i++) Vu1.push_back(A[i] + A[i + N / 2]);
	for (i = 0; i < N / 2; i++) Vu2.push_back(B[i] + B[i + N / 2]);
	rv1 = mymul(Vu1, Vu2);
	Vu1.clear();
	Vu2.clear();

	for (i = 0; i < N / 2; i++) Vu1.push_back(A[i] - A[i + N / 2]);
	for (i = 0; i < N / 2; i++) Vu2.push_back(B[i] - B[i + N / 2]);
	rv2 = mymul(Vu1, Vu2);

	vector <ll> rv;
	for (i = 0; i < N / 2; i++) rv.push_back((rv1[i] + rv2[i]) / 2);
	for (i = 0; i < N / 2; i++) rv.push_back((rv1[i] - rv2[i]) / 2);
	return rv;
}

char in[1100000];
int main() {
	vector <ll> Vu;
	
	int N, i, j;
	scanf("%d", &N);
	scanf("%s", in);
	for (i = 0; i < (1 << N); i++) Vu.push_back(in[i] - '0');

	vector <ll> rv = mymul(Vu, Vu);
	
	ll ans = 0;
	for (i = 0; i < (1 << N); i++) {
		ll v = rv[i];
		for (j = 0; j < N; j++) if (!(i&(1 << j))) v = (v * 2) % MOD;
		ans += v;
		ans %= MOD;
	}
	return !printf("%lld\n", ans * 3 % MOD);
}