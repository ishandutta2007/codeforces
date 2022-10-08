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
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char u[105];

string in[205][2];
set <string> Sx[205][14];
int main() {
	int N, M, i, j, k;
	int mx = 13;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		int L = strlen(u);
		for (j = 0; j < L; j++) {
			for (k = j; k < L; k++) {
				if (k - j + 1 > mx) break;
				Sx[i][k - j + 1].emplace(u + j, u + k + 1);
			}
		}
		if (L <= mx) {
			in[i][0] = string(u);
			in[i][1] = string(u);
		}
		else {
			in[i][0] = string(u, u + mx);
			in[i][1] = string(u + L - mx, u + L);
		}
	}
	scanf("%d", &M);
	for (i = N + 1; i <= M + N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		for (j = 1; j <= mx; j++) {
			for (auto it : Sx[t1][j]) Sx[i][j].insert(it);
			for (auto it : Sx[t2][j]) Sx[i][j].insert(it);
		}
		
		string str = in[t1][1] + in[t2][0];
		for (j = 0; j < str.size(); j++) {
			for (k = j; k < str.size(); k++) {
				if (k - j + 1 > mx) break;
				Sx[i][k - j + 1].emplace(str.begin() + j, str.begin() + k + 1);
			}
		}

		for (j = 1; j <= mx; j++) if (Sx[i][j].size() != (1 << j)) break;
		printf("%d\n", j - 1);

		if (in[t1][0].size() == mx) in[i][0] = in[t1][0];
		else {
			string str = in[t1][0] + in[t2][0];
			if (str.size() <= mx) in[i][0] = str;
			else in[i][0] = string(str.begin(), str.begin() + mx);
		}
		if (in[t2][1].size() == mx) in[i][1] = in[t2][1];
		else {
			string str = in[t1][1] + in[t2][1];
			if (str.size() <= mx) in[i][1] = str;
			else in[i][1] = string(str.begin() + str.size() - mx, str.begin() + str.size());
		}
	}
	return 0;
}