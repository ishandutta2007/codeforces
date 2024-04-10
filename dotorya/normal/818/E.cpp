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

int IT_MAX = 1 << 18;
const ll MOD = 31991;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int in[100050];
vector <int> Vp;
vector <int> Vc;
vector <int> Vin[100050];
vector <int> Vx;
vector <int> Vy;
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	int oK = K;
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 2; i*i <= K; i++) {
		if (K%i) continue;
		int c = 0;
		while (K % i == 0) {
			c++;
			K /= i;
		}
		Vp.push_back(i);
		Vc.push_back(c);
	}
	if (K != 1) {
		Vp.push_back(K);
		Vc.push_back(1);
	}
	for (i = 1; i <= N; i++) {
		for (j = 0; j < Vp.size(); j++) {
			int c = 0, t = in[i];
			while (t % Vp[j] == 0) {
				t /= Vp[j];
				c++;
			}
			Vin[i].push_back(c);
		}
	}

	int X = Vp.size();
	for (i = 0; i < X; i++) Vx.push_back(0);
	for (i = 0; i < X; i++) Vy.push_back(1);
	
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		int mx = 0;
		for (j = 0; j < X; j++) {
			while (Vy[j] <= i) Vx[j] += Vin[Vy[j]++][j];
			while (Vy[j] <= N && Vx[j] < Vc[j]) Vx[j] += Vin[Vy[j]++][j];
			if (Vx[j] < Vc[j]) break;
			mx = max(mx, Vy[j]);
		}
		if (j < X) break;
		ans += N + 2 - max(mx, i + 1);
		for (j = 0; j < X; j++) Vx[j] -= Vin[i][j];
	}
	return !printf("%lld\n", ans);
}