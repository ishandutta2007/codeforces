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
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 14;
const ll MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <int> V[200];
bool gogo(int x) {
	printf("? %d\n", x);
	fflush(stdout);

	int t1, t2;
	scanf("%d", &t1);
	while (t1--) {
		scanf("%d", &t2);
		V[x].push_back(t2);
	}
	if (V[x].size() == 2) {
		printf("! %d\n", x);
		fflush(stdout);
		return true;
	}
	return false;
}
int findnxt(int x) {
	for (auto it : V[x]) if (V[it].empty()) return it;
	while (1);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int H, i, j, d, st;
		scanf("%d", &H);
		vector <int> Vu;

		if (gogo(1)) goto foo;
		Vu.push_back(1);
		i = 1;
		while (V[i].size() != 1) {
			j = V[i][0];
			if (V[j].size() != 0) j = V[i][1];
			if (gogo(j)) goto foo;
			Vu.push_back(j);
			i = j;
		}

		st = 0, d = 0;
		if (Vu.size() == 1) st = Vu[0], d = 1;
		else if (Vu.size() == 2) st = Vu[0], d = 2;
		else if (Vu.size() == 3) st = Vu[0], d = 3;
		else {
			st = Vu[(Vu.size() - 2) / 2], d = (Vu.size() + 3) / 2;
			for (i = 0; i < (Vu.size() - 2) / 2; i++) V[Vu[i]].clear();
		}
		Vu.clear();

		while (1) {
			int c = 0;
			for (auto it : V[st]) if (V[it].empty()) c++;
			if (d == 6) {
				while (1) {
					c = 0;
					for (auto it : V[st]) if (V[it].empty()) c++;
					if (c == 1) {
						for (auto it : V[st]) {
							if (V[it].empty()) {
								printf("! %d\n", it);
								fflush(stdout);
								goto foo;
							}
						}
					}
					int nxt = findnxt(st);
					if (gogo(nxt)) goto foo;
				}
			}
			if (c == 1) {
				for (auto it : V[st]) {
					if (V[it].empty()) {
						st = it;
						break;
					}
				}
				d++;
				if (gogo(st)) goto foo;
				continue;
			}
			if (d == 5) {
				if (c != 3) {
					int t1 = findnxt(st);
					if (gogo(t1)) goto foo;

					int t2 = findnxt(t1);
					if (gogo(t2)) goto foo;

					int t3 = findnxt(t1);
					if (gogo(t3)) goto foo;

					t1 = findnxt(st);
					if (gogo(t1)) goto foo;
					
					st = t1, d = 6;
					continue;
				}
			}
			
			int t = st;
			do {
				int nxt = findnxt(t);
				if (gogo(nxt)) goto foo;
				Vu.push_back(nxt);
				t = nxt;
			} while (V[Vu.back()].size() != 1);
			int x = ((int)Vu.size() - d + 1) / 2;

			st = x?Vu[x - 1]:st;
			d += x;

			Vu.clear();
		}
	foo:
		Vu.clear();
		for (i = 1; i <= 127; i++) V[i].clear();
	}
	return 0;
}