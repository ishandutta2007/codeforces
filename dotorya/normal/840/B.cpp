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
#pragma comment(linker, "/STACK:33554432")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)


map <pii, int> Mx;

vector <pii> Ve;
vector <int> conn[300050];
int in[300050];
int prv[300050];
bool ok[300050];
bool achk[300050];

void mytoggle(int a, int b) {
	int t = Mx[pii(a, b)];
	achk[t] = !achk[t];
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Mx[pii(t1, t2)] = Mx[pii(t2, t1)] = i;
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
		Ve.emplace_back(t1, t2);
	}
	
	vector <int> Vu1;
	for (i = 1; i <= N; i++) {
		if (in[i] == -1) {
			Vu1.push_back(i);
			ok[i] = true;
		}
	}
	for (i = 0; i < Vu1.size(); i++) {
		for (auto it : conn[Vu1[i]]) {
			if (ok[it]) continue;
			ok[it] = true;
			prv[it] = Vu1[i];
			Vu1.push_back(it);
		}
	}
	reverse(all(Vu1));
	for (auto it : Vu1) {
		if (in[it] == -1) break;
		if (in[it] == 1) {
			in[it] ^= 1;
			in[prv[it]] ^= 1;
			mytoggle(it, prv[it]);
		}
	}

	vector <int> Vu2;
	for (i = 1; i <= N; i++) {
		if (ok[i]) continue;
		Vu2.push_back(i);
		ok[i] = true;
		for (j = 0; j < Vu2.size(); j++) {
			for (auto it : conn[Vu2[j]]) {
				if (ok[it]) continue;
				prv[it] = Vu2[j];
				ok[it] = true;
				Vu2.push_back(it);
			}
		}

		int s = 0;
		for (auto it : Vu2) s ^= in[it];
		if (s) return !printf("-1\n");

		reverse(all(Vu2));
		Vu2.pop_back();
		for (auto it : Vu2) {
			if (in[it]) {
				in[it] ^= 1;
				in[prv[it]] ^= 1;
				mytoggle(it, prv[it]);
			}
		}
		Vu2.clear();
	}

	vector <int> Va;
	for (i = 1; i <= M; i++) if (achk[i]) Va.push_back(i);

	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}