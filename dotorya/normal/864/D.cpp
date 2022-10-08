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

int in[200050];
int cnt[200050];
bool dchk[200050];
set<int> Sx;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) Sx.insert(i);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		cnt[in[i]]++;
		Sx.erase(in[i]);
	}

	int ans = 0;
	for (i = 1; i <= N; i++) ans += max(0, cnt[i] - 1);

	for (i = 1; i <= N; i++) {
		int t = 0;
		if (!Sx.empty()) t = *(Sx.begin());
		if (dchk[in[i]]) {
			cnt[in[i]]--;
			cnt[t]++;
			in[i] = t;
			dchk[t] = true;
		}
		else if (cnt[in[i]] >= 2 && t < in[i]) {
			cnt[in[i]]--;
			cnt[t]++;
			in[i] = t;
			dchk[t] = true;
		}
		else dchk[in[i]] = true;
		if (Sx.count(in[i])) Sx.erase(in[i]);
	}
	printf("%d\n", ans);
	for (i = 1; i <= N; i++) printf("%d ", in[i]);
	return !printf("\n");
}