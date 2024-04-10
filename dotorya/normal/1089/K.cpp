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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class Node {
public:
	ll mx, v;
	Node() {
		mx = 0, v = 0;
	}
};

Node indt[1100000];
void propagate(int n) {
	ll v = indt[n].v;
	indt[2 * n].mx += v;
	indt[2 * n].v += v;
	indt[2 * n + 1].mx += v;
	indt[2 * n + 1].v += v;
	indt[n].v = 0;
}

void update(int st, int en, int S, int E, int n, ll v) {
	if (en < S || E < st) return;
	if (st <= S && E <= en) {
		indt[n].mx += v;
		indt[n].v += v;
		return;
	}

	propagate(n);
	int M = (S + E) / 2;
	update(st, en, S, M, 2 * n, v);
	update(st, en, M + 1, E, 2 * n + 1, v);
	indt[n].mx = max(indt[2 * n].mx, indt[2 * n + 1].mx);
}
ll getmx(int st, int en, int S, int E, int n) {
	if (en < S || E < st) return -LL_INF;
	if (st <= S && E <= en) return indt[n].mx;

	propagate(n);
	int M = (S + E) / 2;
	return max(getmx(st, en, S, M, 2 * n), getmx(st, en, M + 1, E, 2 * n + 1));
}

ll Qu[300050][3];
vector <ll> Vx;


int main() {
	int Q, i, j;
	scanf("%d", &Q);
	for (i = 1; i <= Q; i++) {
		char c[2];
		int t1, t2 = -1;
		scanf("%s %d", c, &t1);
		if (c[0] == '+') scanf("%d", &t2);
		
		if (c[0] == '+') Vx.push_back(t1);
		if (c[0] == '-') Qu[i][0] = 1;
		if (c[0] == '?') Qu[i][0] = 2;
		Qu[i][1] = t1, Qu[i][2] = t2;
	}

	sort(all(Vx));
	Vx.erase(unique(all(Vx)), Vx.end());

	int X = Vx.size();
	for (i = 1; i <= X; i++) update(i, i, 1, IT_MAX, 1, Vx[i - 1]);

	for (i = 1; i <= Q; i++) {
		if (Qu[i][0] == 0) {
			ll t1 = Qu[i][1], t2 = Qu[i][2];
			t1 = lower_bound(all(Vx), t1) - Vx.begin() + 1;
			update(1, t1, 1, IT_MAX, 1, t2);
		}
		else if (Qu[i][0] == 1) {
			ll x = Qu[i][1];
			ll t1 = Qu[x][1], t2 = Qu[x][2];
			t1 = lower_bound(all(Vx), t1) - Vx.begin() + 1;
			update(1, t1, 1, IT_MAX, 1, -t2);
		}
		else {
			ll p = lower_bound(all(Vx), Qu[i][1] + 1) - Vx.begin();
			if (p == 0) {
				printf("0\n");
				continue;
			}
			
			ll mx = getmx(1, p, 1, IT_MAX, 1);
			if (p < X) {
				ll v = getmx(p+1, p+1, 1, IT_MAX, 1);
				v -= Vx[p];
				mx -= v;

			}
			printf("%lld\n", max(0ll, mx - Qu[i][1]));
		}
	}
	return 0;
}