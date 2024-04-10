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

char in1[200050];
char in2[200050];

int sa[200050];
int u[200050];
int u2[200050];
int tsa[200050];
int rsa[200050];
int lcp[200050];

int pos[200050];

vector <int> Vp;
vector <int> Vp2;

int r[200050];
int sz[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	scanf("%s %s", in1, in2);
	reverse(in1, in1 + N);
	reverse(in2, in2 + N);

	for (i = 0; i < N; i++) u2[i] = i;
	sort(u2, u2 + N, [](int a, int b) {
		return in1[a] < in1[b];
	});
	for (i = 0, j = -1; i < N; i++) {
		if (i == 0 || in1[u2[i]] != in1[u2[i - 1]]) j++;
		sa[u2[i]] = j;
	}
	for (int l = 1; l < N; l *= 2) {
		int p = 0;
		for (j = N - l; j < N; j++) u[p++] = j;
		for (j = 0; j < N; j++) if (u2[j] >= l) u[p++] = u2[j] - l;

		for (j = 0; j <= N; j++) pos[j] = 0;
		for (j = 0; j < N; j++) pos[sa[j]]++;
		for (j = 1; j <= N; j++) pos[j] += pos[j - 1];
		for (j = N - 1; j >= 0; j--) u2[--pos[sa[u[j]]]] = u[j];
		for (j = 0, k = 0; j < N; j++) {
			if (j) {
				int a = u2[j], b = u2[j - 1], c = a + l, d = b + l;
				if (c >= N || d >= N || sa[a] != sa[b] || sa[c] != sa[d]) k++;
			}
			tsa[u2[j]] = k;
		}
		for (j = 0; j < N; j++) sa[j] = tsa[j];
	}
	for (i = 0; i < N; i++) rsa[i] = u2[i];

	for (i = 0, j = 0; i < N; i++, j = max(0, j - 1)) {
		if (sa[i] == 0) continue;
		int p1 = rsa[sa[i] - 1], p2 = i;
		for (; p1 + j < N && p2 + j < N; j++) if (in1[p1 + j] != in1[p2 + j]) break;
		lcp[sa[p1]] = j;
	}

	ll ans = 0;

	for (i = 0; i < N; i++) {
		int t = rsa[i];
		if (in2[t] == '1') continue;
		if (!Vp.empty()) {
			int mn = INF;
			for (j = Vp.back(); j < i; j++) mn = min(mn, lcp[j]);
			Vp2.push_back(mn);
		}
		
		ans = max(ans, (ll)(N - t));
		Vp.push_back(i);
	}
	if (Vp.empty()) return !printf("%lld\n", ans);

	vector <pii> Vu;
	int X = Vp.size();
	for (i = 0; i < Vp2.size(); i++) Vu.emplace_back(Vp2[i], i);
	sort(all(Vu));
	reverse(all(Vu));

	for (i = 0; i < X; i++) r[i] = i, sz[i] = 1;
	for (auto it : Vu) {
		int t1 = it.second, t2 = t1 + 1;
		int t3 = root(t1), t4 = root(t2);
		sz[t4] += sz[t3];
		r[t3] = t4;
		ans = max(ans, (ll)sz[t4] * it.first);
	}
	return !printf("%lld\n", ans);
}