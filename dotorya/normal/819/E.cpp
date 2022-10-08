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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <vector<int>> Vu;
void aa(int N) {
	if (N == 3) {
		vector <int> Vx = { 1,2,3 };
		Vu.push_back(Vx);
		Vu.push_back(Vx);
		return;
	}
	if (N == 4) {
		vector <int> Vx1 = { 1,2,3,4 };
		vector <int> Vx2 = { 1,2,4,3 };
		vector <int> Vx3 = { 1,4,2,3 };
		Vu.push_back(Vx1);
		Vu.push_back(Vx2);
		Vu.push_back(Vx3);
		return;
	}
	if (N % 2 == 1) {
		for (int i = 1; i <= N - 3; i += 2) {
			vector <int> Vx = { N - 1, i, N, i + 1 };
			Vu.push_back(Vx);
			Vu.push_back(Vx);
		}
		vector <int> Vx2 = { N - 1, N, N - 2 };
		Vu.push_back(Vx2);
		Vu.push_back(Vx2);
	}
	else {
		for (int i = 1; i <= N - 4; i += 2) {
			vector <int> Vx = { N - 1, i, N, i + 1 };
			Vu.push_back(Vx);
			Vu.push_back(Vx);
		}
		vector <int> Vx1 = { N - 1, N, N - 3 };
		vector <int> Vx2 = { N - 1, N, N - 2 };
		vector <int> Vx3 = { N, N - 2, N - 1, N - 3 };
		Vu.push_back(Vx1);
		Vu.push_back(Vx2);
		Vu.push_back(Vx3);
	}
	aa(N - 2);
}

int chk[305][305];
int main() {
	int N;
	scanf("%d", &N);
	aa(N);
	printf("%d\n", (int)Vu.size());
	for (auto it : Vu) {
		printf("%d ", (int)it.size());
		for (auto it2 : it) printf("%d ", it2);
		printf("\n");
	}
	for (auto it : Vu) {
		for (int i = 0; i < it.size(); i++) {
			int t1 = it[i], t2 = it[(i + 1) % it.size()];
			chk[t1][t2]++, chk[t2][t1]++;
		}
	}
	for (int i = 1; i <= N; i++) for (int j = i + 1; j <= N; j++) if (chk[i][j] != 2) printf("WRONG\n");
	return 0;
}