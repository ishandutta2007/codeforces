//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <char, int> pci;

const int MOD = 9999991;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

char in[400050];
set <pii> S;
int main() {
	int N, T, i, t;
	char c[2];
	scanf("%d %d", &N, &T);
	scanf("%s", &in[1]);
	in[0] = in[N + 1] = 'a';

	int p = -1, ans = 0;
	for (i = 1; i <= N+1; i++) {
		if (in[i] == '.' && p == -1) p = i;
		else if (in[i] != '.' && p != -1) {
			S.insert(pii(p, i));
			ans += max(0, i-p-1);
			p = -1;
		}
	}

	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %s", &t, c);
		if (in[t] == '.' && c[0] == '.') {
			printf("%d\n", ans);
			continue;
		}
		if (in[t] != '.' && c[0] != '.') {
			printf("%d\n", ans);
			continue;
		}

		if (in[t] == '.') {
			auto it = S.lower_bound(pii(t + 1, 0));
			it--;
			int t1 = it->first, t2 = it->second;
			ans -= max(0, t2-t1-1);

			S.erase(it);
			if (t1 < t) {
				S.insert(pii(t1, t));
				ans += max(0, t - t1 - 1);
			}
			if (t + 1 < t2) {
				S.insert(pii(t + 1, t2));
				ans += max(0, t2 - t - 2);
			}
			in[t] = 'a';
			printf("%d\n", ans);
			continue;
		}
		else {
			in[t] = '.';
			auto it = S.lower_bound(pii(t, 0));
			if (it == S.end()) {
				if (in[t - 1] == '.') {
					it--;
					int t1 = it->first, t2 = it->second;
					S.erase(it);
					t2++;
					S.insert(pii(t1, t2));
					ans++;
				}
				else S.insert(pii(t, t + 1));
				printf("%d\n", ans);
				continue;
			}

			int t1 = it->first, t2 = it->second;
			if (in[t + 1] == '.') {
				if (in[t - 1] != '.') {
					S.erase(it);
					ans++;
					S.insert(pii(t1 - 1, t2));
				}
				else {
					auto it2 = it;
					it2--;
					t1 = it2->first, t2 = it->second;
					ans -= max(it2->second - it2->first - 1, 0);
					ans -= max(it->second - it->first - 1, 0);
					ans += max(it->second - it2->first-1, 0);
					S.erase(it);
					S.erase(it2);
					S.insert(pii(t1, t2));
				}
				printf("%d\n", ans);
				continue;
			}

			else {
				if (in[t - 1] == '.') {
					it--;
					int t1 = it->first, t2 = it->second;
					S.erase(it);
					t2++;
					S.insert(pii(t1, t2));
					ans++;
				}
				else S.insert(pii(t, t + 1));
				printf("%d\n", ans);
				continue;
			}
		}
	}
	return 0;
}
//*/