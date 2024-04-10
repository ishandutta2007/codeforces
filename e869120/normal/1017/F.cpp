#include <iostream>
#include <algorithm>
using namespace std;

unsigned int N, A, B, C, D, sum; unsigned char prime[12500009]; bool pp[100009];

unsigned int pol(unsigned int x) {
	return A * x * x * x + B * x * x + C * x + D;
}

int Get(int pos) {
	return ((prime[pos >> 3] & (1 << (pos & 7))) >> (pos & 7));
}

void init() {
	pp[1] = true;
	for (int i = 2; i*i <= 100000; i++) {
		for (int j = i*i; j <= 100000; j += i) pp[j] = true;
	}
}

int main() {
	init();
	cin >> N >> A >> B >> C >> D; int Backet = 100000000;
	for (int i = 1; i <= N; i += Backet) {
		for (int j = 0; j < Backet / 8; j++) prime[j] = 0;

		if (i == 1) prime[0] = 1;
		for (int j = 2; j*j < i + Backet; j++) {
			if (pp[j] == true) continue;
			int G = (i - 1) / j; G++;
			for (int k = max(j * j, G * j) - i; k < Backet; k += j) prime[k >> 3] |= (1 << (k & 7));
		}
		for (int j = i; j < i + Backet; j++) {
			if (Get(j - i) == 1) continue;
			unsigned int r = 0;
			unsigned int cx = N; while (cx >= 1) { cx /= j; r += cx; }
			sum += pol(j) * r;
		}
	}
	cout << sum << endl;
	return 0;
}