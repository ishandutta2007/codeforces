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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

char in[50050];

bool chk[26];
int main() {
	int L, i, j;
	scanf("%s", in);
	L = strlen(in);

	if (L < 26) return !printf("-1\n");

	for (i = 0; i <= L - 26; i++) {
		for (j = 0; j < 26; j++) chk[j] = false;
		for (j = 0; j < 26; j++) {
			char c = in[i + j];
			if (c == '?') continue;
			if (chk[c - 'A']) break;
			chk[c - 'A'] = true;
		}
		if (j < 26) continue;

		vector <int> Vu;
		for (j = 0; j < 26; j++) if (!chk[j]) Vu.push_back(j);
		for (j = 0; j < 26; j++) {
			if (in[i + j] == '?') {
				in[i + j] = Vu.back() + 'A';
				Vu.pop_back();
			}
		}
		for (j = 0; j < L; j++) if (in[j] == '?') in[j] = 'A';
		return !printf("%s\n", in);
	}
	return !printf("-1\n");
}