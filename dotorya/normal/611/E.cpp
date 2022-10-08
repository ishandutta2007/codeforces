//*
#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>


#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

multiset <int> Sx;
int main() {
	int ans = 0;
	int N, A, B, C, t;
	scanf("%d %d %d %d", &N, &A, &B, &C);
	if (A > B) swap(A, B);
	if (B > C) swap(B, C);
	if (A > B) swap(A, B);

	while (N--) {
		scanf("%d", &t);
		if (t > A + B + C) return !printf("-1\n");
		Sx.insert(t);
	}

	while (1) {
		auto it = Sx.lower_bound(B+C+1);
		if (it == Sx.end()) break;
		ans++;
		Sx.erase(it);
	}

	while (1) {
		auto it = Sx.lower_bound(A + C + 1);
		if (it == Sx.end()) break;
		ans++;
		Sx.erase(it);

		it = Sx.lower_bound(A + 1);
		if (it != Sx.begin()) {
			it--;
			Sx.erase(it);
		}
	}

	while (1) {
		auto it = Sx.lower_bound(max(C, A + B) + 1);
		if (it == Sx.end()) break;
		ans++;
		Sx.erase(it);

		it = Sx.lower_bound(B + 1);
		if (it != Sx.begin()) {
			it--;
			Sx.erase(it);
		}
	}

	if (A + B >= C) {
		while (!Sx.empty()) {
			ans++;
			auto it = Sx.lower_bound(C + 1);
			if (it != Sx.end()) {
				Sx.erase(it);
				it = Sx.lower_bound(C + 1);
				if (it != Sx.begin()) {
					it--;
					Sx.erase(it);
				}
			}
			else {
				it = Sx.lower_bound(C + 1);
				if (it != Sx.begin()) {
					it--;
					Sx.erase(it);
				}

				it = Sx.lower_bound(A + 1);
				if (it != Sx.begin()) {
					it--;
					Sx.erase(it);
					it = Sx.lower_bound(B + 1);
					if (it != Sx.begin()) {
						it--;
						Sx.erase(it);
					}
					continue;
				}
				else {
					it = Sx.lower_bound(A + B + 1);
					if (it != Sx.begin()) {
						it--;
						Sx.erase(it);
					}
				}
			}
		}
	}
	else {
		while (!Sx.empty()) {
			ans++;
			auto it = Sx.lower_bound(C + 1);
			it--;
			Sx.erase(it);

			it = Sx.lower_bound(A + 1);
			if (it != Sx.begin()) {
				it--;
				Sx.erase(it);
				it = Sx.lower_bound(B + 1);
				if (it != Sx.begin()) {
					it--;
					Sx.erase(it);
				}
			}
			else {
				it = Sx.lower_bound(A + B + 1);
				if (it != Sx.begin()) {
					it--;
					Sx.erase(it);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}