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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

string in[1000050];
char u[1000500];

char ans[2000050];

vector <pair<int, pii>> Vq;

multiset <pii> Sx;
int main() {
	int N, i, L = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		in[i] = string(u);

		int t1, t2;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			t2--;
			Vq.emplace_back(t2, pii(i, t2));
			Vq.emplace_back(t2 + in[i].size(), pii(-i, t2));
			L = max(L, t2 + (int)in[i].size());
		}
	}
	sort(all(Vq));
	int p = 0;
	for (i = 0; i < L; i++) {
		while (p < Vq.size()) {
			if (Vq[p].first > i) break;
			
			pii u = Vq[p].second;
			if (u.first > 0) Sx.insert(u);
			else Sx.erase(Sx.lower_bound(pii(-u.first, u.second)));
			p++;
		}
		if (Sx.empty()) ans[i] = 'a';
		else {
			pii u = *Sx.begin();
			ans[i] = in[u.first][i - u.second];
		}
	}
	return !printf("%s\n", ans);
}