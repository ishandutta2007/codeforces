#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, a[10009], b[10009], c[10009], cc[10009], s = 0;

long long d[10009], e[20009], f[20009];

void add(int pos, long long B) {
	int cl = 0, cr = 0;
	while (cl < pos || cr < pos) {
		long long v1 = (1LL << 60); if (cl < pos) v1 = d[cl];
		long long v2 = (1LL << 60); if (cr < pos) v2 = d[cr] - K;
		if (v1 < v2) { e[cl + cr] = v1; f[cl + cr] = 1; cl++; }
		else { e[cl + cr] = v2; f[cl + cr] = 2; cr++; }
	}

	long long dep = 1, val = B, goal = e[0], bit = 0;
	for (int i = pos * 2 - 2; i >= 0; i--) {
		if (e[i + 1] - val < (e[i + 1] - e[i]) * (dep + 1LL)) {
			long long G = (e[i + 1] - val) / (dep + 1LL); G = max(G, 0LL);
			val += G * dep;
			goal = e[i + 1] - G;
			if (val < goal) { bit = (goal - val - 1); val = goal - 1; }
			break;
		}
		else {
			val += (e[i + 1] - e[i]) * dep;
		}
		if (f[i] == 1) dep++;
		if (f[i] == 2) dep--;
	}

	int stt = -1, stt2 = pos;
	for (int i = 0; i < pos; i++) {
		if (d[i] >= goal) {
			if (stt == -1) stt = i;
			d[i] = max(d[i] - K, goal);
		}
	}

	for (int i = stt; i < stt + bit; i++) d[i]--;
	for (int i = 0; i < pos; i++) { cc[i] = d[i]; if (cc[i] >= val && stt2 == pos) stt2 = i; }

	for (int i = 0; i < stt2; i++) d[i] = cc[i];
	d[stt2] = val;
	for (int i = stt2; i < pos; i++) d[i + 1] = cc[i];
	return;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	for (int i = 0; i < N; i++) c[i] = a[i] - b[i];

	long long S1 = 0;
	for (int i = 0; i < N; i++) S1 += b[i];

	d[0] = c[0];
	for (int i = 1; i < N; i++) add(i, c[i]);

	long long S2 = 0;
	for (int i = 0; i < N; i++) S2 += max(0LL, -d[i]);

	cout << S1 - S2 << endl;
	return 0;
}