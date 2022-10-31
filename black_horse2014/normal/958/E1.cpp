#include <bits/stdc++.h>
using namespace std;

#define sqr(x) ((x) * (x))
typedef double DB;

const DB EPS = 1e-8;

struct PT {
	DB x, y;
	PT(DB x = 0, DB y = 0) : x(x), y(y) {}
	void input() {
		scanf("%lf%lf", &x, &y);
	}
} P[22];

DB vect(PT p, PT p1, PT p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

bool cross(PT p1, PT p2, PT p3, PT p4) {
	return vect(p1, p2, p3) * vect(p1, p2, p4) < -EPS && vect(p3, p4, p1) * vect(p3, p4, p2) < -EPS;
}

bool a[11][11][11][11];
int b[11];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if (n != m) return puts("No"), 0;
	for (int i = 0; i < n+n; i++) P[i].input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == k) continue;
				for (int l = 0; l < n; l++) {
					if (j == l) continue;
					a[i][j][k][l] = cross(P[i], P[j+n], P[k], P[l+n]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) b[i] = i;
	do {
		bool found = 1;
		for (int i = 1; found && i < n; i++) {
			for (int j = 0; found && j < i; j++) found &= !a[i][b[i]][j][b[j]];
		}
		if (found) return puts("Yes"), 0;
	} while (next_permutation(b, b + n));
	return puts("No"), 0;
}