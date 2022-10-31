#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <memory.h>
#include <time.h>
#include <list>
#include <deque>
#include <complex>
#include <functional>
#include <iomanip>
using namespace std;
int N, M, P, NP, NC, NK;
#define mx 10005
int a[mx], fa[mx], A[mx], D[10 * mx], pl[mx], mi[mx], Dn;
map<int, int> hash;
int Pow(int a, int b) {
	long long rlt;
	if (!b) return 1;
	rlt = (long long) (Pow(a, b / 2));
	rlt *= rlt; rlt %= P;
	if (b & 1) rlt = rlt * a % P;
	return int(rlt);
}
int main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int i, d, b, j;
	
	cin >> N >> M >>P;
	
	for (i = 0; i < N; i ++) scanf("%d", &a[i]);
	for (i = 0; i < M; i ++) {
		scanf("%d", &b); 
		if (!i) d = b;
		else d = __gcd(d, b);
	}
	for (i = 0; i < N; i ++) {
		a[i] = Pow(a[i], d);
	}
	int NP = unique(a, a + N) - a, cn(0);
	for (i = 1; i * i < P; i ++)
		if ((P - 1) % i == 0) {
			fa[cn ++] = i;
			if (i * i != P - 1) fa[cn ++] = (P - 1) / i;
		}
	sort(fa, fa + cn);
	for (i = 0; i < NP; i ++) {
		for (j = 0; j < cn; j ++) {
			if (Pow(a[i], fa[j]) == 1) break;
		}
		A[i] = fa[j];
	}
	sort(A, A + NP);
	NK = unique(A, A + NP) - A;
	for (j = NP - 1; j >= 0; j --) {
		for (i = NP - 1; i >= j + 1; i --) {
			if (A[i] % A[j] == 0) {
				A[j] = A[i];
				break;
			}
		}
	}sort(A, A + NP);
	NC = unique(A, A + NP) - A;
	for (i = 0; i < NC; i ++) {
		int Cn = Dn;
		for (j = 0; j < Dn; j ++) {
			int kk = __gcd(A[i], D[j]);
			if (hash.count(kk)) {
				int id = hash[kk];
				pl[id] += mi[j];
				mi[id] += pl[j];
			} else {
				D[Cn] = kk;
				hash[kk] = Cn;
				pl[Cn] = mi[j];
				mi[Cn ++] = pl[j];
			}
		}
		Dn = Cn;
		D[Dn] = A[i];
		hash[A[i]] = Dn;
		pl[Dn ++] = 1;
	}
	int rlt(0);
	for (i = 0; i < Dn; i ++) rlt += D[i] * (pl[i] - mi[i]);
	cout << rlt << endl;
	return EXIT_SUCCESS;
}