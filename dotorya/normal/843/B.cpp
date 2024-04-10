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

bool dchk[50050];
int myrand(int M) {
	ll rv = rand() % M;
	rv = (rv * RAND_MAX + rand()) % M;
	rv = (rv * RAND_MAX + rand()) % M;
	rv = (rv * RAND_MAX + rand()) % M;
	return rv;
}

int cnt;
pii getv(int x) {
	cnt++;
	printf("? %d\n", x);
	fflush(stdout);

	int t1, t2;
	scanf("%d %d", &t1, &t2);
	return pii(t1, t2);
}
int main() {
	srand(time(0));
	int N, st, x, i;
	scanf("%d %d %d", &N, &st, &x);
	
	vector <pii> Vu;
	for (i = 1; i <= min(N, 500); i++) {
		int t;
		do {
			t = myrand(N) + 1;
			if (i == 1) t = st;
		} while (dchk[t]);
		dchk[t] = true;
		pii u = getv(t);
		Vu.emplace_back(u.first, t);
	}
	
	sort(all(Vu));
	int p = lower_bound(all(Vu), pii(x + 1, -1)) - Vu.begin();
	p--;
	if (p == -1) {
		printf("! %d\n", Vu[0].first);
		fflush(stdout);
		return 0;
	}
	
	int t = Vu[p].second;
	while (t != -1 && cnt <= 1990) {
		pii u = getv(t);
		if (u.first >= x) {
			printf("! %d\n", u.first);
			fflush(stdout);
			return 0;
		} 
		t = u.second;
	}
	printf("! -1\n");
	fflush(stdout);
	return 0;
}