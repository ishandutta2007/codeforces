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

pii in[2000050];
bool chk[2000050];
vector <int> Vu;
vector <int> Vu2;
int main() {
	int N, M, K, i, j;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i].first);
		in[i].second = 0;
	}
	for (i = 1; i <= M; i++) {
		scanf("%d", &in[i + N].first);
		in[i + N].second = i;
	}
	sort(in + 1, in + N + M + 1);
	for (i = 1; i <= N+M; i++) if (in[i].second) Vu.push_back(i);

	int st = 0, en = M, mi, rv = -1;
	while (st <= en) {
		mi = (st + en) / 2;
		Vu2.clear();
		for (i = 0; i < Vu.size(); i++) {
			int t = Vu.size() - i;
			if (t <= mi) chk[Vu[i]] = true;
			else chk[Vu[i]] = false;
		}
		for (i = 1; i <= N+M; i++) if (in[i].second == 0 || chk[i]) Vu2.push_back(in[i].first);
		for (i = 0; i < Vu2.size(); i++) if (i / K > Vu2[i]) break;
		if (i >= Vu2.size()) {
			rv = mi;
			st = mi + 1;
		}
		else en = mi - 1;
	}
	if (rv == -1) return !printf("-1\n");
	printf("%d\n", rv);
	for (i = Vu.size() - rv; i < Vu.size(); i++) printf("%d ", in[Vu[i]].second);
	return !printf("\n");
}