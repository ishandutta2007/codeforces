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

ll val[500050];
ll indt[1100000];
void update(int p, int v) {
	v *= val[p];
	p += IT_MAX - 1;
	for (; p; p /= 2) indt[p] += v;
}
ll getsum(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;

	ll rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = rv + indt[p1++];
		if (p2 % 2 == 0) rv = rv + indt[p2--];
	}
	return rv;
}

int getright(int p) {
	p += IT_MAX - 1;

	while (1) {
		if (indt[p]) break;

		if (p & (p + 1)) p = (p + 1) / 2;
		else return INF;
	}

	while (p < IT_MAX) {
		if (indt[2 * p]) p = 2 * p;
		else p = 2 * p + 1;
	}
	return p - IT_MAX + 1;
}

int in[500050][2];

map <int, int> Mx1;
map <int, int> Mx2;
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		char c[2];
		scanf("%s %d", c, &in[i][1]);
		if (c[0] == '+') {
			in[i][0] = 1;
			Mx1[in[i][1]]++;
		}
	}

	int prv = 0;
	for (auto &it : Mx1) {
		for (i = prv + 1; i <= prv + it.second; i++) val[i] = it.first;
		it.second += prv;
		prv = it.second;
	}
	Mx2 = Mx1;

	for (i = 1; i <= N; i++) {
		if (in[i][0] == 1) {
			int t = in[i][1];
			in[i][1] = Mx1[t];
			Mx1[t]--;
		}
		else {
			int t = in[i][1];
			in[i][1] = Mx2[t];
			Mx2[t]--;
		}
	}

	int M = prv;
	int cnt = 0;
	for (i = 1; i <= N; i++) {
		if (in[i][0] == 1) {
			cnt++;
			update(in[i][1], 1);
		}
		else {
			cnt--;
			update(in[i][1], -1);
		}

		if (cnt <= 1) {
			printf("0\n");
			continue;
		}

		int ans = cnt;
		ll sum = 0;
		while (1) {
			int p = lower_bound(val + 1, val + M + 1, 2 * sum + 1) - val;

			ll nsum = getsum(1, p - 1);
			if (sum == nsum) {			
				int x = getright(p);
				if (x == INF) break;
				else {
					ans--;
					sum = getsum(1, x);
				}
			}
			else sum = nsum;
		}
		printf("%d\n", ans);
	}
	return 0;
}