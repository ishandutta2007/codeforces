#include <stdio.h>
#include <algorithm>
#include <assert.h>
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

int IT_MAX = 1 << 21;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

map <vector<int>, int> dis;
map < vector<int>, pair<int, vector<int>>> rev;
vector <vector<int>> Vq;

void vpush(vector <int> Vu, vector <int> Vr, int u, int d) {
	if (dis.count(Vu)) return;
	dis[Vu] = d;
	rev[Vu] = mp(u, Vr);
	Vq.push_back(Vu);
}
int main() {
	int N, A, B, i, j;
	scanf("%d %d %d", &N, &A, &B);

	vector <int> Vs;
	for (i = 1; i <= N; i++) {
		scanf("%d", &j);
		j++;
		Vs.push_back(j);
	}

	dis[Vs] = 0;
	Vq.push_back(Vs);
	for (i = 0; i < Vq.size(); i++) {
		vector <int> Vu = Vq[i];
		vector <int> Vu2 = Vu;
		int d = dis[Vu] + 1;
		for (j = 0; j < N; j++) if (Vu[j]) break;
		if (j == N) continue;
		if (j == N - 1) {
			Vu2[N - 1] = max(0, Vu2[N - 1] - B);
			vpush(Vu2, Vu, N - 2, d);
			continue;
		}

		if (j != 0) {
			Vu2[j] = max(0, Vu2[j] - A);
			Vu2[j + 1] = max(0, Vu2[j + 1] - B);
			vpush(Vu2, Vu, j, d);
		}
		if (j + 1 != N-1) {
			Vu2 = Vu;
			Vu2[j] = max(0, Vu2[j] - B);
			Vu2[j + 1] = max(0, Vu2[j + 1] - A);
			if (j + 2 < N) Vu2[j + 2] = max(0, Vu2[j + 2] - B);
			vpush(Vu2, Vu, j + 1, d);
		}
	}
	
	vector <int> Ve;
	for (i = 1; i <= N; i++) Ve.push_back(0);
	printf("%d\n", dis[Ve]);

	while (Ve != Vs) {
		printf("%d ", rev[Ve].first + 1);
		Ve = rev[Ve].second;
	}
	return !printf("\n");
}