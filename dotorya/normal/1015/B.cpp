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

char cnt[26];

char in1[100];
char in2[100];
vector <int> Va;
void myswap(int p) {
	Va.push_back(p);
	swap(in1[p], in1[p+1]);
}

int main() {
	int N, i, j;
	scanf("%d", &N);
	scanf("%s %s", in1, in2);
	for (i = 0; i < N; i++) cnt[in1[i] - 'a']++;
	for (i = 0; i < N; i++) cnt[in2[i] - 'a']--;
	for (i = 0; i < 26; i++) if (cnt[i]) return !printf("-1\n");

	
	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) if (in1[j] == in2[i]) break;
		for (j = j - 1; j >= i; j--) myswap(j);
	}
	
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it + 1);
	return !printf("\n");
}