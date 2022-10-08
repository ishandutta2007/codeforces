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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char in[100050];

vector <int> Vp1;
vector <int> Vp2;
int main() {
	int N, i;
	scanf("%d %s", &N, in);
	for (i = 0; i < N; i++) {
		if (in[i] == '*') Vp1.push_back(i);
		if (in[i] == 'P') Vp2.push_back(i);
	}

	int st = 1, en = 300000, mi, rv = en + 1;
	while (st <= en) {
		mi = (st + en) / 2;

		int p = 0;
		for (auto it : Vp2) {
			if (p >= Vp1.size()) break;

			if (it - Vp1[p] > mi) break;
			if (Vp1[p] - it > mi) continue;

			int pos = it;
			if (Vp1[p] > it) pos = it + mi;
			else {
				pos = max(pos, it + (mi - (it - Vp1[p]) * 2));
				pos = max(pos, it + (mi - (it - Vp1[p])) / 2);
			}
			p = lower_bound(all(Vp1), pos + 1) - Vp1.begin();
		}
		if (p >= Vp1.size()) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%d\n", rv);
}