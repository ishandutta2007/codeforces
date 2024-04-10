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

vector <int> conn[100050];
vector <int> rconn[100050];

vector <int> Vin[100050];
vector <int> Vu;
bool dchk[100050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		int t1, t2;
		scanf("%d", &t1);
		while (t1--) {
			scanf("%d", &t2);
			Vin[i].push_back(t2);
		}
	}
	for (i = 1; i < N; i++) {
		for (j = 0; j < Vin[i].size() && j < Vin[i + 1].size(); j++) {
			if (Vin[i][j] == Vin[i + 1][j]) continue;
			int t1 = Vin[i][j], t2 = Vin[i + 1][j];
			conn[t1].push_back(t2);
			rconn[t2].push_back(t1);
			if (t1 > t2) {
				dchk[t1] = true;
				Vu.push_back(t1);
			}
			break;
		}
		if ((j >= Vin[i].size() || j >= Vin[i + 1].size()) && Vin[i].size() > Vin[i + 1].size()) return !printf("No\n");
	}
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : rconn[Vu[i]]) {
			if (!dchk[it]) {
				dchk[it] = true;
				Vu.push_back(it);
			}
		}
	}
	for (i = 1; i <= M; i++) {
		for (auto it : conn[i]) {
			int t1 = i, t2 = it;
			if (t1 < t2) {
				if (!dchk[t1] && dchk[t2]) return !printf("No\n");
			}
			else {
				if (!dchk[t1] || dchk[t2]) return !printf("No\n");
			}
		}
	}
	vector <int> Va;
	for (i = 1; i <= M; i++) if (dchk[i]) Va.push_back(i);
	printf("Yes\n%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}