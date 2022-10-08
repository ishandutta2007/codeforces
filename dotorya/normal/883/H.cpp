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
//#include <unordered_map>  
//#include <unordered_set>  
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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

map <char, int> Mx;
char in[400050];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	scanf("%s", in);
	for (i = 0; in[i] != 0; i++) Mx[in[i]]++;

	int c = 0;
	for (auto it : Mx) if (it.second % 2) c++;

	for (i = 1; i <= N; i++) {
		if (N%i) continue;

		int L = N / i, mx = i;
		if (L % 2 == 0) mx = 0;
		if (mx < c) continue;

		printf("%d\n", i);
		for (j = 1; j <= i; j++) {
			string u;
			string u2;
			for (k = 1; k <= L / 2; k++) {
				auto it = Mx.begin();
				while (it->second < 2) it++;
				u += it->first;
				it->second -= 2;
				if (it->second == 0) Mx.erase(it);
			}
			for (k = L / 2 - 1; k >= 0; k--) u2 += u[k];
			if (L % 2) {
				auto it = Mx.begin();
				for (it = Mx.begin(); it != Mx.end(); it++) if (it->second % 2 == 1) break;
				if (it == Mx.end()) it--;
				u += it->first;
				it->second--;
				if (it->second == 0) Mx.erase(it);
			}
			string ans = u + u2;
			printf("%s ", ans.c_str());
		}
		return !printf("\n");
	}
	return 0;
}