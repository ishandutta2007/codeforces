#include <stdio.h>  
#include <algorithm>  
#include <assert.h>  
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
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <int> Vs[300050];
vector <int> conn[300050];

int ans[300050];
bool chk[500050];
bool dchk[300050];
vector <int> Vu;
void DFS(int n) {
	dchk[n] = true;

	for (auto it : Vs[n]) {
		if (ans[it]) chk[ans[it]] = true;
		else Vu.push_back(it);
	}

	int a = 1;
	for (auto it : Vu) {
		while (chk[a]) a++;
		ans[it] = a++;
	}
	for (auto it : Vs[n]) chk[ans[it]] = false;
	Vu.clear();

	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		DFS(it);
	}
}
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			Vs[i].push_back(t2);
		}
	}
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);

	int mx = 0;
	for (i = 1; i <= M; i++) {
		mx = max(mx, ans[i]);
		if (ans[i] == 0) ans[i] = 1;
	}
	mx = max(mx, 1);
	printf("%d\n", mx);
	for (i = 1; i <= M; i++) printf("%d ", ans[i]);
	
	return !printf("\n");
}