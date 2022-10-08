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

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int main() {
	int N, i, j;
	scanf("%d", &N);

	int ON = N;

	int a1 = -1, a2 = -1;
	for (i = 2; i * i <= N; i++) {
		if (N%i) continue;

		if (a1 == -1) a1 = i;
		else {
			a2 = i;
			break;
		}

		while (N%i == 0) N /= i;
	}
	if (N != 1) {
		if (a1 == -1) a1 = N;
		else if(a2 == -1) a2 = N;
	}
	
	if (a2 == -1) return !printf("NO\n");

	if (a1 > a2) swap(a1, a2);
	for (int i = 0; i < a1; i++) {
		int v = ON - 1 - a2 * i;
		if (v % a1 == 0) {
			printf("YES\n2\n%d %d\n%d %d\n", v / a1, ON / a1, i, ON / a2);
			return 0;
		}
	}
	return !printf("NO\n");
}