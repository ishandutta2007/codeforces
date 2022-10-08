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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class datax {
public:
	int x, y, z;
	datax() {
		*this = datax(0, 0, 0);
	}
	datax(int x, int y, int z) : x(x), y(y), z(z) {}
	bool operator < (const datax &l) const {
		if (x != l.x) return x < l.x;
		if (y != l.y) return y < l.y;
		return z < l.z;
	}
};

datax Qu[100050];
bool ans[100050][2];

vector <datax> Vl[8];
int main() {
	int xmx, ymx, zmx, N, M, K, i, j, k;
	scanf("%d %d %d %d %d %d", &xmx, &ymx, &zmx, &N, &M, &K);

	int xst = INF, xen = -INF, yst = INF, yen = -INF, zst = INF, zen = -INF;
	for (i = 1; i <= N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		xst = min(xst, t1);
		xen = max(xen, t1);
		yst = min(yst, t2);
		yen = max(yen, t2);
		zst = min(zst, t3);
		zen = max(zen, t3);
	}

	for (i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);

		int ii, jj, kk;
		int iv, jv, kv;

		if (xst <= t1 && t1 <= xen && yst <= t2 && t2 <= yen && zst <= t3 && t3 <= zen) return !printf("INCORRECT\n");
		for (ii = 0; ii < 8; ii++) {
			if ((ii & 1) == 0) {
				if (xst <= t1 && t1 <= xen) iv = xmx;
				else if (t1 < xst) iv = t1;
				else continue;
			}
			else {
				if (xst <= t1 && t1 <= xen) iv = xmx;
				else if (t1 > xen) iv = xmx + 1 - t1;
				else continue;
			}

			if ((ii & 2) == 0) {
				if (yst <= t2 && t2 <= yen) jv = ymx;
				else if (t2 < yst) jv = t2;
				else continue;
			}
			else {
				if (yst <= t2 && t2 <= yen) jv = ymx;
				else if (t2 > yen) jv = ymx + 1 - t2;
				else continue;
			}

			if ((ii & 4) == 0) {
				if (zst <= t3 && t3 <= zen) kv = zmx;
				else if (t3 < zst) kv = t3;
				else continue;
			}
			else {
				if (zst <= t3 && t3 <= zen) kv = zmx;
				else if (t3 > zen) kv = zmx + 1 - t3;
				else continue;
			}

			Vl[ii].emplace_back(iv, jv, kv);
		}
	}
	for (i = 0; i < 8; i++) sort(all(Vl[i]));
	
	printf("CORRECT\n");

	for (i = 1; i <= K; i++) {
		scanf("%d %d %d", &Qu[i].x, &Qu[i].y, &Qu[i].z);
		int x = Qu[i].x, y = Qu[i].y, z = Qu[i].z;
		if (xst <= x && x <= xen && yst <= y && y <= yen && zst <= z && z <= zen) ans[i][0] = false;
		else ans[i][0] = true;

		ans[i][1] = true;
	}
	for (i = 0; i < 8; i++) {
		vector <pair<datax, int>> Vq;
		for (j = 1; j <= K; j++) {
			datax u = Qu[j];
			if (i & 1) u.x = xmx + 1 - u.x;
			if (i & 2) u.y = ymx + 1 - u.y;
			if (i & 4) u.z = zmx + 1 - u.z;
			Vq.emplace_back(u, j);
		}
		sort(all(Vq));

		map <int, int> Mx;
		Mx[1] = 0;
		Mx[ymx + 1] = -INF;

		int p = 0;
		int qp = 0;

		reverse(all(Vq));
		reverse(all(Vl[i]));
		for (j = xmx; j >= 1; j--) {
			while (p < Vl[i].size()) {
				datax u = Vl[i][p];
				if (u.x != j) break;

				auto it = Mx.lower_bound(u.y + 1);
				if (it->first != u.y + 1) {
					it--;
					int v = it->second;
					Mx[u.y + 1] = v;
				}

				int st = u.y + 1;
				while (1) {
					auto it = Mx.lower_bound(u.y + 1);
					if (it == Mx.begin()) break;
					it--;

					if (it->second >= u.z) break;
					st = it->first;
					Mx.erase(it);
				}
				if (st != u.y + 1) Mx[st] = u.z;
				p++;
			}
			while (qp < Vq.size()) {
				datax u = Vq[qp].first;
				if (u.x != j) break;

				auto it = Mx.lower_bound(u.y + 1);
				it--;
				if (it->second >= u.z) ans[Vq[qp].second][1] = false;
				qp++;
			}
		}
	}

	for (i = 1; i <= K; i++) {
		if (ans[i][0] & ans[i][1]) printf("UNKNOWN\n");
		else if (ans[i][0]) printf("CLOSED\n");
		else printf("OPEN\n");
	}
	return 0;
}