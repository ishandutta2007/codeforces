#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
#include<tuple>
using namespace std;
#pragma warning(disable: 4996)

long long bit[2][2509][2509], H, W, q, p1, p2, p3, p4, p5; map<tuple<int, int, int, int, int>, long long>M;
void add(long long e, long long p, long long q, long long x) {
	long long r = p, s = q;
	while (p <= 2508) {
		while (q <= 2508) {
			bit[e][p][q] += x; q += (q&-q);
		}
		q = s; p += (p&-p);
	}
}
long long sum(long long e, long long p, long long q) {
	long long r = p, s = q, res = 0;
	while (p >= 1) {
		while (q >= 1) {
			res += bit[e][p][q]; q -= (q&-q);
		}
		q = s; p -= (p&-p);
	}
	return res;
}
void solve(long long e, long long p, long long q, long long r, long long s, long long x) {
	add(e, p - 1, q - 1, x);
	add(e, r, s, x);
	add(e, p - 1, s, -x);
	add(e, r, q - 1, -x);
}
long long sums(long long e, long long p, long long q) {
	long long A1 = sum(e, p, q);
	long long A2 = sum(e, H + 2, W + 2);
	long long A3 = sum(e, p, W + 2);
	long long A4 = sum(e, H + 2, q);
	return (A1 + A2 + A3 + A4);
}
long long Rand() {
	long long I = 0;
	for (int i = 0; i < 4; i++)I += (1LL << (16 * i))*(rand() % 65536);
	return I;
}
int main() {
	srand((unsigned)time(NULL));
	cin >> H >> W >> q;
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d%d", &p1, &p2, &p3, &p4, &p5);
		if (p1 == 1 || p1 == 2) { p2++; p3++; p4++; p5++; }
		if (p1 == 1) {
			for (int j = 0; j < 2; j++) { long long B = Rand(); solve(j, p2, p3, p4, p5, B); M[make_tuple(j, p2, p3, p4, p5)] = B; }
		}
		if (p1 == 2) {
			for (int j = 0; j < 2; j++) {
				long long B = M[make_tuple(j, p2, p3, p4, p5)];
				solve(j, p2, p3, p4, p5, -B);
				M[make_tuple(j, p2, p3, p4, p5)] = 0;
			}
		}
		if (p1 == 3) {
			bool OK = true;
			for (int j = 0; j < 2; j++) {
				long long V1 = sums(j, p2, p3), V2 = sums(j, p4, p5);
				if (V1 != V2)OK = false;
			}
			if (OK == true)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}