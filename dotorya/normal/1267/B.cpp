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

char in[300050];
int main() {
	vector <pair<char, int>> Vl;

	scanf("%s", in);
	int N = strlen(in), i, j;
	for (i = 0; i < N; i++) {
		if (Vl.empty() || Vl.back().first != in[i]) Vl.emplace_back(in[i], 1);
		else Vl.back().second++;
	}
	if (Vl.size() % 2 != 1) return !printf("0\n");

	int X = Vl.size();
	if (Vl[(X - 1) / 2].second == 1) return !printf("0\n");
	for (int i = (X - 3) / 2; i >= 0; i--) {
		if (Vl[i].first != Vl[X - 1 - i].first) return !printf("0\n");
		if (Vl[i].second + Vl[X - 1 - i].second < 3) return !printf("0\n");
	}
	return !printf("%d\n", Vl[(X - 1) / 2].second + 1);
}