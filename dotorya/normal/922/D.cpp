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

int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

ll cnt[100050][2];
string in[100050];
char u[100050];

int ch[100050];

string str;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		in[i] = string(u);
		for (auto it : in[i]) {
			if (it == 's') cnt[i][0]++;
			else cnt[i][1]++;
		}
	}
	for (i = 1; i <= N; i++) ch[i] = i;
	sort(ch + 1, ch + N + 1, [](int a, int b) {
		return cnt[a][0] * cnt[b][1] > cnt[a][1] * cnt[b][0];
	});
	for (i = 1; i <= N; i++) str += in[ch[i]];
	
	ll ans = 0, c = 0;
	for (auto it : str) {
		if (it == 's') c++;
		else ans += c;
	}
	return !printf("%lld\n", ans);
}