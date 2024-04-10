#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
string S[200], T[200]; int c[200][1 << 15], n, q;
void add(int pos, string G) {
	for (int i = 0; i < G.size(); i++) {
		int cnt = 0, ret = 0;
		for (int j = i; j < G.size(); j++) {
			ret += (1 << cnt)*(G[j] - '0'); cnt++;
			c[pos][ret + (1 << cnt)] = 1;
			if (cnt == 14)break;
		}
	}
}
int check(int pos) {
	for (int i = 1; i <= 14; i++) {
		for (int j = (1 << i); j < (1 << (i + 1)); j++) {
			if (c[pos][j] == 0)return i - 1;
		}
	}
	return 14;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> S[i]; T[i] = S[i]; add(i, S[i]); }
	cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v; u--; v--;
		for (int j = 0; j < (1 << 15); j++) { if (c[u][j] == 1 || c[v][j] == 1)c[n + i][j] = 1; }
		add(n + i, T[u] + S[v]);
		if (S[u].size() == 20)S[n + i] = S[u]; else S[n + i] = S[u] + S[v]; if (S[n + i].size() >= 20)S[n + i] = S[n + i].substr(0, 20);
		if (T[v].size() == 20)T[n + i] = T[v]; else T[n + i] = T[u] + T[v]; if (T[n + i].size() >= 20)T[n + i] = T[n + i].substr(T[n + i].size() - 20, 20);
		cout << check(n + i) << endl;
	}
	return 0;
}