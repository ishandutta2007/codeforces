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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char in[1050];

int cur[5][5];
int tcur[5][5];
int main() {
	scanf("%s", in);
	for (int i = 0; in[i]; i++) {
		int x, y;
		if (in[i] == '0') {
			if (cur[3][4] && cur[4][4]) {
				printf("1 4\n");
				cur[3][4] = cur[4][4] = 0;
			}
			else {
				printf("3 4\n");
				cur[3][4] = cur[4][4] = 1;
			}
		}
		else {
			if (cur[1][1] && cur[1][2]) {
				printf("1 3\n");
				cur[1][1] = cur[1][2] = 0;
			}
			else {
				printf("1 1\n");
				cur[1][1] = cur[1][2] = 1;
			}
		}
	}
	return 0;
}