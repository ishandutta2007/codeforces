#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y, z, idx;
	bool operator< (const point& o) const {
		if(z == o.z) {
			if(y == o.y) return x < o.x;
			return y < o.y;
		}
		return z < o.z;
	}
}A[50505];

int N;
vector<int> v1;
vector<int> v2;

void solve1(int s, int e) {
	for(int i = s; i <= e; i += 2) {
		if(i + 1 > e) v1.push_back(A[i].idx);
		else printf("%d %d\n", A[i].idx, A[i + 1].idx);
	}
}

void solve2(int s, int e) {
	int p = s;

	int bef = s - 1;
	while(p <= e) {
		if(A[p].y != A[p + 1].y || p + 1 > e) {
			solve1(bef + 1, p);
			bef = p;
		}
		p++;
	}

	for(int i = 0; i < v1.size(); i += 2) {
		if(i + 1 == v1.size()) v2.push_back(v1[i]);
		else printf("%d %d\n", v1[i], v1[i + 1]);
	}
	v1.clear();
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].z);
		A[i].idx = i;
	}
	sort(A + 1, A + N + 1);

	int p = 1;
	int bef = 0;
	while(p <= N) {
		if(A[p].z != A[p + 1].z || p + 1 > N) {
			solve2(bef + 1, p);
			bef = p;
		}
		p++;
	}

	for(int i = 0; i < v2.size(); i += 2) printf("%d %d\n", v2[i], v2[i + 1]);

	return 0;
}