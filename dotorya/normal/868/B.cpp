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
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int main() {
	int H, M, S, t1, t2;
	scanf("%d %d %d %d %d", &H, &M, &S, &t1, &t2);
	if (t1 == 12) t1 = 0;
	if (t2 == 12) t2 = 0;
	t1 *= 5;
	t2 *= 5;
	if (H == 12) H = 0;
	H = (H * 5 + M / 12);
	if (t1 > t2) swap(t1, t2);

	bool c1 = false, c2 = false;
	if (t1 <= H && H < t2) c1 = true;
	else c2 = true;

	if (t1 <= M && M < t2) c1 = true;
	else c2 = true;
	
	if (t1 <= S && S <= t2) c1 = true;
	else c2 = true;
	if (!c1 || !c2) printf("YES\n");
	else printf("NO\n");
	return 0;
}