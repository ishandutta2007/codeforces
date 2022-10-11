#include <iostream>
#include <vector>
using namespace std;
int a[100][100], W, H, K, s1, s2;
void search(vector<int>V) {
	int maxn = 0, maxid = 0, P = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] == 0)continue;
		int G = 0;
		for (int j = i; j < i + K; j++) {
			if (j >= V.size())continue;
			if (V[j] == 1)G++;
		}
		if (maxn < G) { maxn = G; maxid = P; }
		if (V[i] == 1)P++;
	}
	s1 += maxn; s2 += maxid;
}
int main() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++) { for (int j = 0; j < W; j++)cin >> a[i][j]; }
	for (int i = 0; i < W; i++) { vector<int>Z; for (int j = 0; j < H; j++)Z.push_back(a[j][i]); search(Z); }
	cout << s1 << " " << s2 << endl;
	return 0;
}