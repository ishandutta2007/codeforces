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

ll cnt[100050];
vector <int> Vl[100050];
int main() {
	ll N, S, i, j;
	scanf("%lld %lld", &N, &S);

	if (S > N*(N + 1) / 2) return !printf("No\n");
	if (S < 2 * N - 1) return !printf("No\n");

	ll st = 1, en = N - 1, mi, rv = N;
	while (st <= en) {
		mi = (st + en) / 2;

		ll s = 1;
		cnt[1] = 1;
		for (i = 2;; i++) {
			cnt[i] = cnt[i-1] * mi;
			if (cnt[i] + s >= N) {
				cnt[i] = N - s;
				cnt[i + 1] = 0;
				break;
			}
			else s += cnt[i];
		}

		s = 0;
		for (i = 1; cnt[i]; i++) s += i * cnt[i];
		if (s <= S) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}

	memset(cnt, 0, sizeof(cnt));
	cnt[1] = 1;
	ll s = 1;
	for (i = 2;; i++) {
		cnt[i] = cnt[i - 1] * rv;
		if (cnt[i] + s >= N) {
			cnt[i] = N - s;
			break;
		}
		else s += cnt[i];
	}

	int mx = i;
	s = 0;
	for (i = 1; i <= mx; i++) s += i * cnt[i];
	
	int p = mx, cur = mx;
	while (s < S) {
		if (cnt[p] == 1) {
			p--;
			continue;
		}

		if (p + S - s <= cur + 1) {
			cnt[p]--;
			cnt[p + S - s]++;
			break;
		}
		else {
			cnt[p]--;
			cnt[cur + 1]++;
			s += cur + 1 - p;
			cur++;
			continue;
		}
	}

	printf("Yes\n");
	int n = 1;
	Vl[1].push_back(1);
	for (i = 2; cnt[i]; i++) {
		int st = n + 1, en = n + cnt[i];
		for (int j = st; j <= en; j++) Vl[i].push_back(j);
		for (int j = 0; j < Vl[i].size(); j++) printf("%d ", Vl[i - 1][j/rv]);
		n += cnt[i];
	}
	return !printf("\n");
}