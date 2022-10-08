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

char in[105];
char u[105];
set <string> Sx;
int main() {
	int N, i, j;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", in);
		int L = 0;
		for (i = 0; in[i] != 0; i++) {
			if (in[i] == 'u') {
				u[L] = 'o';
				u[L + 1] = 'o';
				L += 2;
			}
			else if (in[i] == 'h') {
				while (L >= 1 && u[L - 1] == 'k') L--;
				u[L++] = in[i];
			}
			else u[L++] = in[i];
		}
		u[L] = 0;
		Sx.emplace(u);
	}
	printf("%d\n", (int)Sx.size());
}