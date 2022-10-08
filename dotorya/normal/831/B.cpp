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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

char in1[30];
char in2[30];
char in[1050];

int main() {
	scanf("%s %s %s", in1, in2, in);

	int N = strlen(in), i, j;
	for (i = 0; i < N; i++) {
		if (in[i] >= 'a' && in[i] <= 'z') {
			for (j = 0; j < 26; j++) if (in[i] == in1[j]) break;
			in[i] = in2[j];
		}
		else if (in[i] >= 'A' && in[i] <= 'Z') {
			in[i] += 'a' - 'A';
			for (j = 0; j < 26; j++) if (in[i] == in1[j]) break;
			in[i] = in2[j];
			in[i] += 'A' - 'a';
		}
	}
	return !printf("%s\n", in);
}