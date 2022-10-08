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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

char DB[10][105] =
{
	"Danil",
	"Olya",
	"Slava",
	"Ann",
	"Nikita"
};
char in[105];
int main() {
	scanf("%s", in);

	int c = 0, i, j, k;
	for (i = 0; i < 5; i++) {
		int L1 = strlen(in), L2 = strlen(DB[i]);
		for (j = 0; j + L2 - 1 < L1; j++) {
			for (k = 0; k < L2; k++) if (in[j + k] != DB[i][k]) break;
			if (k >= L2) c++;
		}
	}
	if (c == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}