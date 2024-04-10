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
#pragma comment(linker, "/STACK:3336777216")  
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

int in[200050];
int rin[200050];

vector <int> conn[200050];
bool dchk[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		rin[in[i]] = i;
	}
	for (i = 1; i <= N; i++) {
		sort(all(conn[i]), [](int a, int b) {
			return rin[a] < rin[b];
		});
	}

if(in[1] != 1) return !printf("No\n");
	int st = in[1];
	vector <int> Vu;
	Vu.push_back(st);
	dchk[st] = true;
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			if (dchk[it]) continue;
			Vu.push_back(it);
			dchk[it] = true;
		}
	}
	for (i = 1; i <= N; i++) if (Vu[i - 1] != in[i]) return !printf("No\n");
	return !printf("Yes\n");
}