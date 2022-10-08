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

class datax {
public:
	int v;
	vector<pii> Vl;
	vector<pii> Vr;
	datax() {
	}
	datax(int p, int x) {
		v = 2*x;
		Vl.emplace_back(x, p);
		Vr.emplace_back(x, p);
	}
};
int lcp(string a, string b) {
	int i;
	for (i = 0; i < a.size() && i < b.size(); i++) if (a[i] != b[i]) return i;
	return i;
}
int indt1[300000];
void update1(int p, int v) {
	p += IT_MAX - 1;
	indt1[p] = v;
	for (p /= 2; p; p /= 2) indt1[p] = max(indt1[2 * p], indt1[2 * p + 1]);
}
int getmx1(int p1, int p2) {
	p1 += IT_MAX - 1;
	p2 += IT_MAX - 1;
	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = max(rv, indt1[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt1[p2--]);
	}
	return rv;
}

datax indt2[300000];
datax mymerge(datax& V1, datax& V2) {
	if (V2.Vr.empty()) return V1;
	if (V1.Vr.empty()) return V2;
	
	datax rv;
	rv.v = max(V1.v, V2.v);

	int p1 = (int)V1.Vr.size() - 1, p2 = (int)V2.Vl.size() - 1;
	while (p1 >= 0 && p2 >= 0) {
		pii u1 = V1.Vr[p1], u2 = V2.Vl[p2];
		rv.v = max(rv.v, (u2.second - u1.second + 2) * min(u1.first, u2.first));
		if (p1 == 0 && p2 == 0) break;
		if (p1 == 0) p2--;
		else if (p2 == 0) p1--;
		else if (u1.first < u2.first) p1--;
		else p2--;
	}
	rv.Vl = V1.Vl;
	for (auto it : V2.Vl) {
		if (rv.Vl.back().first <= it.first) rv.Vl.back().second = it.second;
		else rv.Vl.push_back(it);
	}
	rv.Vr = V2.Vr;
	for (auto it : V1.Vr) {
		if (rv.Vr.back().first <= it.first) rv.Vr.back().second = it.second;
		else rv.Vr.push_back(it);
	}
	return rv;
}
void update2(int p, int v) {
	int op = p;
	p += IT_MAX - 1;
	indt2[p] = datax(op, v);
	for (p /= 2; p; p /= 2) indt2[p] = mymerge(indt2[2 * p], indt2[2 * p + 1]);
}
int getmx2(int p1, int p2) {
	if (p1 > p2) return 0;

	vector <int> Vu1;
	vector <int> Vu2;
	for (p1 += IT_MAX - 1, p2 += IT_MAX - 1; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) Vu1.push_back(p1++);
		if (p2 % 2 == 0) Vu2.push_back(p2--);
	}

	while (!Vu2.empty()) {
		Vu1.push_back(Vu2.back());
		Vu2.pop_back();
	}
	
	datax Vr = indt2[Vu1[0]];
	for (int i = 1; i < Vu1.size(); i++) Vr = mymerge(Vr, indt2[Vu1[i]]);
	return Vr.v;
}


string in[100050];
char u[100050];
int main() {
	int N, Q, i;
	scanf("%d %d", &N, &Q);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		in[i] = string(u);
	}

	for (i = 1; i <= N; i++) update1(i, in[i].size());
	for (i = 1; i < N; i++) {
		update2(i, lcp(in[i], in[i + 1]));
	}

	while (Q--) {
		int t1, t2, t3;
		scanf("%d", &t1);
		if (t1 == 1) {
			scanf("%d %d", &t2, &t3);
			printf("%d\n", max(getmx1(t2, t3), getmx2(t2, t3 - 1)));
		}
		else {
			scanf("%d %s", &t2, u);
			in[t2] = string(u);
			update1(t2, in[t2].size());
			if (t2 != 1) update2(t2 - 1, lcp(in[t2 - 1], in[t2]));
			if (t2 != N) update2(t2, lcp(in[t2], in[t2 + 1]));
		}
	}
	return 0;
}