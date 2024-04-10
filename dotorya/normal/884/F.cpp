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

char in1[105];
int in2[105];

int main() {
	int N, i, j;
	scanf("%d", &N);
	scanf("%s", in1 + 1);
	for (i = 1; i <= N; i++) scanf("%d", &in2[i]);

	int s = 0, s2 = 0;
	for (i = 1; i <= N; i++) s += in2[i];

	while (1) {
		vector <pair<char, int>> Vu;
		for (i = 1; i <= N / 2; i++) {
			if (in1[i] != in1[N + 1 - i]) continue;
			Vu.emplace_back(in1[i], i);
			if (in2[i] > in2[N + 1 - i]) Vu.back().second = N + 1 - i;
		}
		if (Vu.empty()) break;

		sort(all(Vu));
		if (Vu[0].first != Vu.back().first) {
			int t1 = Vu[0].second;
			int t2 = Vu.back().second;
			s2 += in2[t1] + in2[t2];
			in2[t1] = 0, in2[t2] = 0;
			swap(in1[t1], in1[t2]);
			continue;
		}

		int mn = INF, mnp = 0;
		for (i = 1; i <= N / 2; i++) {
			if (in1[i] == Vu[0].first || in1[N + 1 - i] == Vu[0].first) continue;
			if (mn > in2[i]) {
				mn = in2[i];
				mnp = i;
			}
			if (mn > in2[N + 1 - i]) {
				mn = in2[N + 1 - i];
				mnp = N + 1 - i;
			}
		}

		int t1 = Vu[0].second;
		int t2 = mnp;
		s2 += in2[t1] + in2[t2];
		in2[t1] = 0, in2[t2] = 0;
		swap(in1[t1], in1[t2]);
	}
	return !printf("%d\n", s - s2);
}