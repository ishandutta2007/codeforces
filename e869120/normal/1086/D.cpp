#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

class BIT {
public:
	vector<int>dat; int sz;

	void init(int size_) {
		sz = size_ + 2;
		dat.resize(sz + 2, 0);
	}

	void add(int pos, int x) {
		pos++;
		while (pos <= sz) {
			dat[pos] += x; pos += (pos&-pos);
		}
	}
	int sum(int pos) {
		if (pos < 0) return 0;
		int s = 0; pos++; pos = min(pos, sz);
		while (pos >= 1) {
			s += dat[pos]; pos -= (pos&-pos);
		}
		return s;
	}
	int Least(int pos) {
		int L = pos, R = sz + 1, M, minx = (1 << 28);
		int I = sum(pos - 1);

		for (int i = 0; i < 20; i++) {
			M = (L + R) / 2;
			if (sum(M) != I) { minx = min(minx, M); R = M; }
			else { L = M; }
		}
		return minx;
	}
	int Most(int pos) {
		int L = 0, R = pos, M, maxn = -(1 << 28);
		int I = sum(pos);

		for (int i = 0; i < 20; i++) {
			M = (L + R) / 2;
			if (sum(M) != I) { maxn = max(maxn, M + 1); L = M; }
			else { R = M; }
		}
		return maxn;
	}
};

string S; int N, Q; char P[200009];
BIT Z[3];

int calc(int pos, int cl, int cr, int dl, int dr) {
	if (cl >= cr && dl >= dr) return 0;
	if (cl >= cr) return Z[pos].sum(dr - 1) - Z[pos].sum(dl - 1);
	if (dl >= dr) return Z[pos].sum(cr - 1) - Z[pos].sum(cl - 1);
	if (cr <= dl || dr <= cl) return Z[pos].sum(dr - 1) - Z[pos].sum(dl - 1) + Z[pos].sum(cr - 1) - Z[pos].sum(cl - 1);
	return Z[pos].sum(max(dr, cr) - 1) - Z[pos].sum(min(dl, cl) - 1);
}

int solve() {
	// R 
	int AL, AR, BL, BR;
	AL = Z[2].Least(0);
	AR = Z[1].Least(0);
	BL = Z[1].Most(N + 1);
	BR = Z[2].Most(N + 1);
	int Z1 = Z[0].sum(N + 1) - calc(0, AL, AR, BL, BR);

	// S 
	AL = Z[0].Least(0);
	AR = Z[2].Least(0);
	BL = Z[2].Most(N + 1);
	BR = Z[0].Most(N + 1);
	int Z2 = Z[1].sum(N + 1) - calc(1, AL, AR, BL, BR);

	// P 
	AL = Z[1].Least(0);
	AR = Z[0].Least(0);
	BL = Z[0].Most(N + 1);
	BR = Z[1].Most(N + 1);
	int Z3 = Z[2].sum(N + 1) - calc(2, AL, AR, BL, BR);

	return Z1 + Z2 + Z3;
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < 3; i++) Z[i].init(N + 2);
	for (int i = 0; i <= N; i++) {
		scanf("%c", &P[i]);
		if (P[i] == 'R') Z[0].add(i, 1);
		if (P[i] == 'S') Z[1].add(i, 1);
		if (P[i] == 'P') Z[2].add(i, 1);
	}

	printf("%d\n", solve());

	for (int i = 1; i <= Q; i++) {
		char c; int d; scanf("%d", &d); cin >> c;

		if (P[d] == 'R') Z[0].add(d, -1);
		if (P[d] == 'S') Z[1].add(d, -1);
		if (P[d] == 'P') Z[2].add(d, -1);

		P[d] = c;

		if (P[d] == 'R') Z[0].add(d, 1);
		if (P[d] == 'S') Z[1].add(d, 1);
		if (P[d] == 'P') Z[2].add(d, 1);

		printf("%d\n", solve());
	}
	return 0;
}