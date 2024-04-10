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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
ll MOD = 1000000007ll;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)

int cnt[26];
char in[100050];
int main() {
	scanf("%s", in + 1);
	int N = strlen(in + 1), i, j;
	for (i = 1; i <= N; i++) cnt[in[i] - 'a']++;

	vector <int> Vu;
	for (i = 0; i < 26; i++) if (cnt[i]) Vu.push_back(i);

	if (Vu.size() >= 5 || Vu.size() <= 1) return !printf("No\n");
	if (Vu.size() == 2) {
		if (cnt[Vu[0]] >= 2 && cnt[Vu[1]] >= 2) return !printf("Yes\n");
		return !printf("No\n");
	}
	if (Vu.size() == 3) {
		if (cnt[Vu[0]] == 1 && cnt[Vu[1]] == 1 && cnt[Vu[2]] == 1) return !printf("No\n");
		return !printf("Yes\n");
	}
	return !printf("Yes\n");
}