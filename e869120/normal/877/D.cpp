#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<ctime>
using namespace std;
#pragma warning(disable: 4996)
double dist[1009][1009][2]; string S[1009]; int H, W, K, sx, sy, tx, ty;
priority_queue < tuple<double, int, int, int>, vector<tuple<double, int, int, int>>, greater<tuple<double, int, int, int>>>Q;
int main() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++)cin >> S[i];
	cin >> sx >> sy >> tx >> ty; sx--; sy--; tx--; ty--;
	for (int i = 0; i < H; i++) { for (int j = 0; j < W; j++) { for (int k = 0; k < 2; k++) dist[i][j][k] = 1000000.0; } }
	for (int i = 0; i < 2; i++) { dist[sx][sy][i] = 0; Q.push(make_tuple(dist[sx][sy][0], sx, sy, i)); }

	while (!Q.empty()) {
		int a1 = get<1>(Q.top()), a2 = get<2>(Q.top()), a3 = get<3>(Q.top()); Q.pop();
		int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int fx = a1 + dx[i], fy = a2 + dy[i];
			if (fx < 0 || fy < 0 || fx >= H || fy >= W || S[fx][fy] == '#')continue;
			
			double T = 0;
			if (i % 2 == a3) T = dist[a1][a2][a3] + (1.0 / K);
			else T = (int)(dist[a1][a2][a3] + 0.99999) + (1.0 / K);

			if (dist[fx][fy][i % 2] > T) { dist[fx][fy][i % 2] = T; Q.push(make_tuple(dist[fx][fy][i % 2], fx, fy, i % 2)); }
		}
	}
	double maxn = 1000000.0; for (int i = 0; i < 2; i++)maxn = min(maxn, dist[tx][ty][i]);
	if (maxn >= 999999.9)cout << "-1" << endl;
	else cout << (int)(maxn + 0.99999) << endl;
	return 0;
}