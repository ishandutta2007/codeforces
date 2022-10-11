#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#pragma warning(disable:4996)
int dist[230000], n, a[230000]; queue<int>Q;
int main() {
	for (int i = 0; i < 230000; i++)dist[i] = 29999999;
	cin >> n; for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); if (a[i] == 0) { dist[i] = 0; Q.push(i); } }
	while (!Q.empty()) {
		int a1 = Q.front(); Q.pop();
		if (a1 >= 2 && dist[a1 - 1] >= dist[a1] + 1) { dist[a1 - 1] = dist[a1] + 1; Q.push(a1 - 1); }
		if (a1 < n && dist[a1 + 1] >= dist[a1] + 1) { dist[a1 + 1] = dist[a1] + 1; Q.push(a1 + 1); }
	}
	for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << dist[i]; }cout << endl;
	return 0;
}