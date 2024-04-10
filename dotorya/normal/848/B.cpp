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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

map <int, int> Mx;
int ch(int x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size();
	return Mx[x] = t + 1;
}

map <pair<int, pii>, int> Mch;
vector <pii> Vin[200050];

int ans[200050][2];
int main() {
	int N, W, H, i, j;
	scanf("%d %d %d", &N, &W, &H);
	for (i = 1; i <= N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		int x = ch(t3 - t2);
		Vin[x].emplace_back(t1, t2);

		Mch[mp(x, pii(t1, t2))] = i;
	}

	for (i = 1; i <= Mx.size(); i++) {
		sort(all(Vin[i]), [](pii a, pii b) {
			if (a.first != b.first) return a.first == 2;
			else if (a.first == 2) return a.second > b.second;
			else return a.second < b.second;
		});
		
		vector <pii> Va;
		for (auto it : Vin[i]) if (it.first == 1) Va.emplace_back(it.second, H);
		for (auto it : Vin[i]) if (it.first == 2) Va.emplace_back(W, it.second);

		for (j = 0; j < Vin[i].size(); j++) {
			int x = Mch[mp(i, Vin[i][j])];
			ans[x][0] = Va[j].first, ans[x][1] = Va[j].second;
		}
	}
	for (i = 1; i <= N; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}