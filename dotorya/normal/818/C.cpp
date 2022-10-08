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

int IT_MAX = 1 << 18;
const ll MOD = 31991;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> Vx1;
vector <int> Vx2;
vector <int> Vy1;
vector <int> Vy2;

int in[100050][4];
int in2[4];

int getcnt(vector <int> &V, int x) {
	int it = lower_bound(all(V), x + 1) - V.begin();
	return it;
}
int main() {
	int D, N, M, i;
	scanf("%d %d %d", &D, &N, &M);
	for (i = 1; i <= D; i++) {
		scanf("%d %d %d %d", &in[i][0], &in[i][1], &in[i][2], &in[i][3]);
		Vx1.push_back(min(in[i][0], in[i][2]));
		Vx2.push_back(max(in[i][0], in[i][2]));
		Vy1.push_back(min(in[i][1], in[i][3]));
		Vy2.push_back(max(in[i][1], in[i][3]));
	}
	sort(all(Vx1));
	sort(all(Vx2));
	sort(all(Vy1));
	sort(all(Vy2));
	for (i = 0; i < 4; i++) scanf("%d", &in2[i]);
	for (i = 1; i <= D; i++) {
		int c1 = getcnt(Vx1, max(in[i][0], in[i][2]) - 1);
		int c2 = D - getcnt(Vx2, min(in[i][0], in[i][2]));
		if (min(in[i][0], in[i][2]) != max(in[i][0], in[i][2])) c1--, c2--;

		int c3 = getcnt(Vy1, max(in[i][1], in[i][3]) - 1);
		int c4 = D - getcnt(Vy2, min(in[i][1], in[i][3]));
		if (min(in[i][1], in[i][3]) != max(in[i][1], in[i][3])) c3--, c4--;
		if (c1 == in2[0] && c2 == in2[1] && c3 == in2[2] && c4 == in2[3]) return !printf("%d\n", i);
	}
	return !printf("-1\n");
}