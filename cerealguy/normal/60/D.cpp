#include <cstdio>
#include <vector>

const int max = 10000001;
const int maxn = 1000000;
using std::vector;

int pos[max];
int a[maxn];
int n;
int sets;
int p[maxn], r[maxn];

void init() {
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	sets = n;
}

int get(int i) {
	if (p[i] != i)
		p[i] = get(p[i]);
	return p[i];
}

void unionsets(int i, int j) {
	i = get(i);
	j = get(j);
	if (i == j)
		return;
	--sets;
	if (r[i] < r[j]) {
		p[i] = j;
	} else {
		p[j] = i;
		if (r[i] == r[j])
			r[i]++;
	}
}

int gcd(int a, int b) {
	return b == 0? a: gcd(b, a % b);
}

void get1() {
	for (int v = 1; 2 * v * v < max; ++v) {
		int vv = v * v;
		for (int u = v + 1; ; u+=2) {
			if (gcd(u, v) != 1) continue;
			int number = u * u + vv;
			if (number >= max) break;
			if (pos[number] == -1) continue;
			int val = number - (vv << 1);
			if (pos[val] != -1) unionsets(pos[val], pos[number]);
			val = 2 * u * v;
			if (val < max) {
				if (pos[val] != -1) unionsets(pos[val], pos[number]);
			}
		}
		for (int u = v + 1; ; u+=2) {
			if (gcd(u, v) != 1) continue;
			int number = 2 * u * v;
			if (number >= max) break;
			int val = u * u - vv;
			if (val >= max) break;
			if (pos[number] == -1) continue;
			if (pos[val] != -1) unionsets(pos[val], pos[number]);
		}
	}
}

int main() {
	for (int i = 0; i < max; i++) {
		pos[i] = -1;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &(a[i]));
		pos[a[i]] = i;
	}
	init();
	get1();
	printf("%d\n", sets);
	return 0;
}