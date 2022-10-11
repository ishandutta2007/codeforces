#include <bits/stdc++.h>
using namespace std;

long long N, sx, sy, gx, gy, x[100009], y[100009];
string S;

bool ispossible(long long t) {
	long long V = (t / N);
	long long vx = x[N] * V, vy = y[N] * V;
	vx += x[t % N]; vy += y[t % N];
	
	if (abs(gx - vx) + abs(gy - vy) <= t) return true;
	return false;
}

int main() {
	scanf("%lld%lld%lld%lld%lld", &sx, &sy, &gx, &gy, &N);
	gx -= sx; gy -= sy;
	cin >> S;
	for (int i = 1; i <= S.size(); i++) {
		x[i] = x[i - 1]; y[i] = y[i - 1];
		if (S[i - 1] == 'L') x[i]--;
		if (S[i - 1] == 'R') x[i]++;
		if (S[i - 1] == 'U') y[i]++;
		if (S[i - 1] == 'D') y[i]--;
	}
	
	long long cl = 0, cr = (1LL << 60), cm = 0, minx = (1LL << 60);
	for (int i = 0; i  < 60; i++) {
		cm = (cl + cr) / 2LL;
		bool I = ispossible(cm);
		if (I == true) { minx = min(minx, cm); cr = cm; }
		else cl = cm;
	}
	if (minx == (1LL << 60)) cout << "-1" << endl;
	else cout << minx << endl;
	return 0;
}