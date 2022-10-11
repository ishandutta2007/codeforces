#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<functional>
#include<tuple>
using namespace std;
#pragma warning(disable: 4996)

long long n, m, k, a[200009], b[200009], c[200009], d[200009];
vector<tuple<long long, long long, long long>>E, F; long long dep[1000009], arr[1000009], v[200009];
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		if (c[i] == 0)E.push_back(make_tuple(a[i], b[i], d[i]));
		else F.push_back(make_tuple(a[i], c[i], d[i]));
	}
	sort(E.begin(), E.end()); sort(F.begin(), F.end(), greater<tuple<long long, long long, long long>>());
	for (int i = 1; i <= n; i++)v[i] = (1LL << 41);
	int cx = 0; long long T = 1LL * n * (1LL << 41);
	for (int i = 0; i <= 1000000; i++) {
		while (cx < E.size() && get<0>(E[cx]) == i) {
			int to = get<1>(E[cx]);
			long long V = min(v[to], get<2>(E[cx])); T -= (v[to] - V); v[to] = V; cx++;
		}
		dep[i] = T;
	}
	for (int i = 1; i <= n; i++)v[i] = (1LL << 41);
	cx = 0; T = 1LL * n * (1LL << 41);
	for (int i = 1000000; i >= 0; i--) {
		while (cx < F.size() && get<0>(F[cx]) == i) {
			int to = get<1>(F[cx]);
			long long V = min(v[to], get<2>(F[cx])); T -= (v[to] - V); v[to] = V; cx++;
		}
		arr[i] = T;
	}
	long long minx = (1LL << 41);
	for (int i = 0; i <= 999999 - k; i++) {
		minx = min(minx, dep[i] + arr[i + k + 1]);
	}
	if (minx >= (1LL << 41))minx = -1;
	cout << minx << endl;
	return 0;
}