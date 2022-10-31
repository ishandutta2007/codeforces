#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 200010;
const int MX = 1 << 19;

int N;
int X[MAXN], Y[MAXN];
double SS[MAXN];
ld S[MAXN];
ld ene[2 * MAXN];
int ss[MAXN];
ld seg[2 * MX], lazy[2 * MX];

void mkseg(int idx, int l, int r) {
	if(l == r) seg[idx] = ene[l];
	else {
		int m = (l + r) / 2;
		mkseg(idx * 2, l, m);
		mkseg(idx * 2 + 1, m + 1, r);
		seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
	}
}

ld gseg(int idx, int l, int r, int x, int y) {
	if(x <= l && r <= y) return seg[idx];
	if(r < x || y < l) return 1e10;
	int m = (l + r) / 2;
	return min(gseg(idx * 2, l, m, x, y), gseg(idx * 2 + 1, m + 1, r, x, y)) + lazy[idx];
}
ld gseg(int x) { return gseg(1, 0, 2 * N, x, 2 * N); }

void updseg(int idx, int l, int r, int x, int y, double z) {
	if(x <= l && r <= y) {
		seg[idx] += z;
		lazy[idx] += z;
	}
	else if(x <= r && l <= y) {
		int m = (l + r) / 2;
		updseg(idx * 2, l, m, x, y, z);
		updseg(idx * 2 + 1, m + 1, r, x, y, z);
		seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]) + lazy[idx];
	}
}
void updseg(int x, double z) { updseg(1, 0, 2 * N, x, 2 * N, z); }

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int L;
	cin >> N >> L;
	for(int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> SS[i];

	for(int i = 0; i < N; i++) S[i] = SS[i];
	ld ans = X[0];
	for(int i = 0; i < N; i++) {
		if(i > 0) {
			ene[2 * i] = max(ene[2 * i - 1] - (X[i] - Y[i - 1]) / ld(2), ld(0));
			ans += X[i] - Y[i - 1];
		}
		ene[2 * i + 1] = ene[2 * i] + (Y[i] - X[i]) / S[i];
	}
	ene[2 * N] = max(ene[2 * N - 1] - (L - Y[N - 1]) / ld(2), ld(0));
	ans += L - Y[N - 1];
	mkseg(1, 0, 2 * N);

	for(int i = 0; i < N; i++) ss[i] = i;
	sort(ss, ss + N, [&](const int a, const int b) { return S[a] < S[b]; } );
	
	for(int i = 0; i < N; i++) {
		ld t = min(gseg(2 * ss[i] + 1), (Y[ss[i]] - X[ss[i]]) * (1 / S[ss[i]] + 1 / (S[ss[i]] + 2)));
		updseg(2 * ss[i] + 1, -t);
		ans += S[ss[i]] * t / (S[ss[i]] + 1);
	}

	cout << fixed;
	cout.precision(20);
	cout << double(ans);
	return 0;
}