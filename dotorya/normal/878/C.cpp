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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

int K;
int u[10];
class datax {
public:
	int a[10];
	int b[10];
	int c;
	datax() {
		for (int i = 0; i < K; i++) a[i] = b[i] = u[i];
		c = 1;
	}
	datax operator + (const datax &l) const {
		datax rv;
		for (int i = 0; i < K; i++) {
			rv.a[i] = min(a[i], l.a[i]);
			rv.b[i] = max(b[i], l.b[i]);
		}
		rv.c = c + l.c;
		return rv;
	}
	bool operator < (const datax &l) const {
		return a[0] < l.a[0];
	}
};

set <datax> Sx;
int main() {
	int N, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		for (j = 0; j < K; j++) scanf("%d", &u[j]);

		datax cur = datax();
		while (!Sx.empty()) {
			auto it = Sx.lower_bound(cur);
			if (it != Sx.begin()) {
				it--;
				bool c1 = false, c2 = false;
				for (int i = 0; i < K; i++) {
					if (it->b[i] > cur.a[i]) c1 = true;
					if (cur.b[i] > it->a[i]) c2 = true;
				}
				if (c1 && c2) {
					cur = cur + *it;
					Sx.erase(it);
					continue;
				}
			}

			it = Sx.lower_bound(cur);
			if (it != Sx.end()) {
				bool c1 = false, c2 = false;
				for (int i = 0; i < K; i++) {
					if (it->b[i] > cur.a[i]) c1 = true;
					if (cur.b[i] > it->a[i]) c2 = true;
				}
				if (c1 && c2) {
					cur = cur + *it;
					Sx.erase(it);
					continue;
				}
			}
			break;
		}
		Sx.insert(cur);
		auto it = Sx.end();
		it--;
		printf("%d\n", it->c);
	}
	return 0;
}