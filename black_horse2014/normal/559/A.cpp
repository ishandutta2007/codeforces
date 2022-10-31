#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define bit(x) (1 << (x))
#define cnt1(x) (__builtin_popcount(x))

template<class T>
inline void chkmax(T& x, T y) {
	if (x < y) x = y;
}

template<class T>
inline void chkmin(T& x, T y) {
	if (y < x) x = y;
}

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;
int a[10];

int sqr(int x) {
	return x * x;
}

int main() {
	
	int i, rlt;
	
	for (i = 0; i < 6; i++) scanf("%d", &a[i]);
	rlt = sqr(a[0] + a[1] + a[5]) - sqr(a[1]) - sqr(a[3]) - sqr(a[5]);
	printf("%d\n", rlt);
	return 0;
}