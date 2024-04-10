#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)
unsigned int x = 1000000007;
long long Rand(long long p) {
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	long long T = x;
	return T%p;
}
int n, q, a[300009], b[300009], l[300009], r[300009], k[300009], ans[300009], B = 600; vector<tuple<int, int, int, int, int>>vec;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++) { scanf("%d%d%d", &l[i], &r[i], &k[i]); vec.push_back(make_tuple(l[i] / B, r[i], l[i], k[i], i)); }
	sort(vec.begin(), vec.end());
	int cl = 1, cr = 0;
	for (int i = 0; i < vec.size(); i++) {
		int L = get<2>(vec[i]), R = get<1>(vec[i]), X = get<3>(vec[i]), P = get<4>(vec[i]);
		while (cl > L) { cl--; b[a[cl]]++; }
		while (cl < L) { b[a[cl]]--; cl++; }
		while (cr > R) { b[a[cr]]--; cr--; }
		while (cr < R) { cr++; b[a[cr]]++; }
		vector<int>E;
		for (int j = 0; j < 100; j++) {
			E.push_back(a[Rand(R - L + 1) + L]);
		}
		int minx = 1e9;
		for (int j = 0; j < E.size(); j++) {
			if (b[E[j]] > (R - L + 1) / X)minx = min(minx, E[j]);
		}
		if (minx >= 1e8)ans[P] = -1; else ans[P] = minx;
	}
	for (int i = 1; i <= q; i++)printf("%d\n", ans[i]);
	return 0;
}