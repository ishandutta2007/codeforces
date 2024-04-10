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

vector <pair<int, pii>> Ve;
vector <pair<int, pii>> Ve2[200050];
int r[200050];
int cnt[200050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) r[i] = i;
	while (M--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		r[root(t1)] = root(t2);
		Ve.emplace_back(t3, pii(t1, t2));
	}
	for (auto it : Ve) Ve2[root(it.second.first)].push_back(it);
	
	int ans = 0;
	sort(all(Ve));
	reverse(all(Ve));
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i <= N; i++) cnt[i] = 1;
	for (auto it : Ve) {
		int t1 = it.first, t2 = it.second.first, t3 = it.second.second;
		t2 = root(t2), t3 = root(t3);
		if (cnt[t2] == 0 && cnt[t3] == 0) continue;
		if (t2 == t3) {
			ans += t1;
			cnt[t2]--;
		}
		else {
			r[t2] = t3;
			cnt[t3] += cnt[t2];
			cnt[t3]--;
			ans += t1;
		}
	}
	return !printf("%d\n", ans);
}