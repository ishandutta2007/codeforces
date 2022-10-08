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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> Vu;

bool dchk[100050];
int in[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	for (i = 1; i <= N; i++) {
		if (dchk[i]) continue;

		vector <int> Vl;
		int c = 0, t = i;
		do {
			c++;
			Vl.push_back(t);
			t = in[t];
		} while (t != i);
		Vu.push_back(c);
		for (auto it : Vl) dchk[it] = true;
	}
	if (Vu.size() == 1) return !printf("%lld\n", (ll)N*N);

	sort(all(Vu));
	int t = Vu.back();
	Vu.pop_back();
	Vu.back() += t;

	ll ans = 0;
	for (auto it : Vu) ans += (ll)it*it;
	return !printf("%lld\n", ans);
}