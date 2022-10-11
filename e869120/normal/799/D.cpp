#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
long long a, b, h, w, n, p[100000];
vector<long long> Zen_Re_Kkyo(vector<long long>C) {
	vector<long long>V;
	for (int i = 0; i < (1 << C.size()); i++) {
		long long R = 1;
		for (int j = 0; j < C.size(); j++) { if ((i / (1 << j)) % 2 == 1)R *= C[j]; if (R >= (1LL << 40))R = (1LL << 40); }
		V.push_back(R);
	}
	sort(V.begin(), V.end());
	return V;
}
long long solve(vector<long long>E, long long F) {
	long long I = 1; for (int i = 0; i < E.size(); i++) { I *= E[i]; if (I >= F)break; }
	if (I < F)return -1;
	vector<long long>G1, G2, H1, H2;
	for (int i = 0; i < E.size() / 2; i++)H1.push_back(E[i]);
	for (int i = E.size() / 2; i < E.size(); i++)H2.push_back(E[i]);
	G1 = Zen_Re_Kkyo(H1);
	G2 = Zen_Re_Kkyo(H2);
	long long minx = 1e18;
	for (int i = 0; i < G1.size(); i++) {
		long long pos1 = lower_bound(G2.begin(), G2.end(), (F + G1[i] - 1) / G1[i]) - G2.begin();
		if (pos1 == G2.size())continue;
		minx = min(minx, G2[pos1] * G1[i]);
	}
	return minx;
}
int main() {
	cin >> a >> b >> h >> w >> n;
	for (int i = 0; i < n; i++)cin >> p[i];
	sort(p, p + n, greater<long long>());

	int minx = 20000;
	long long R = h*w;
	for (int i = -1; i < n; i++) {
		vector<long long>P;
		for (int j = 0; j <= i; j++)P.push_back(p[j]); if (i >= 0)R *= p[i];
		long long t = solve(P, (a + h - 1) / h);
		if (R / (t*h) < b || t == -1) continue;
		minx = i + 1; break;
	}
	swap(h, w);
	R = h*w;
	for (int i = -1; i < n; i++) {
		vector<long long>P;
		for (int j = 0; j <= i; j++)P.push_back(p[j]); if (i >= 0)R *= p[i];
		long long t = solve(P, (a + h - 1) / h);
		if (R / (t*h) < b || t == -1) continue;
		minx = min(minx, i + 1); break;
	}
	if (minx == 20000)minx = -1;
	cout << minx << endl;
	return 0;
}