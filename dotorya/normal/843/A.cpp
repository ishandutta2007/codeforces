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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> Vx;
int in[100050];

bool dchk[100050];

int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		Vx.push_back(in[i]);
	}
	sort(all(Vx));
	for (i = 1; i <= N; i++) in[i] = lower_bound(all(Vx), in[i]) - Vx.begin() + 1;

	vector <vector<int>> Va;
	for (i = 1; i <= N; i++) {
		if (dchk[i]) continue;
		vector <int> Vu;
		
		int t = i;
		do {
			Vu.push_back(t);
			dchk[t] = true;
			t = in[t];
		} while (!dchk[t]);
		sort(all(Vu));
		Va.push_back(Vu);
	}
	printf("%d\n", (int)Va.size());
	for (auto it : Va) {
		printf("%d ", it.size());
		for (auto it2 : it) printf("%d ", it2);
		printf("\n");
	}
	return 0;
}