#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

string S, T;
long long hush[1 << 20], power[1 << 20], pa = 0, pb = 0, mod = 2147483647;

void init() {
	for (int i = 1; i <= T.size(); i++) { hush[i] = (311LL * hush[i - 1] + 1LL * (long long)(T[i - 1] - 'a' + 1)) % mod; }
	power[0] = 1;
	for (int i = 1; i <= T.size(); i++) power[i] = 311LL * power[i - 1] % mod;
}

long long hashval(int cl, int cr) {
	// 1-indexed, 
	return (hush[cr] - hush[cl - 1] * power[cr - cl + 1] + mod * mod) % mod;
}

int main() {
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++) { if (S[i] == '0') pa++; else pb++; }
	init();

	vector<pair<int, int>> G;
	for (int i = 1; i <= 1000000; i++) {
		int L = (int)T.size() - pa * i;
		if (L <= 0) break;
		if (L%pb == 0) G.push_back(make_pair(i, L / pb));
	}

	int cnt = 0;
	for (int i = 0; i < G.size(); i++) {
		int cx = 1; long long v1 = -1, v2 = -1; bool flag = true;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '0') {
				long long e = hashval(cx, cx + G[i].first - 1);
				if (v1 == -1) v1 = e;
				else if (e != v1) flag = false;
				cx += G[i].first;
			}
			if (S[j] == '1') {
				long long e = hashval(cx, cx + G[i].second - 1);
				if (v2 == -1) v2 = e;
				else if (e != v2) flag = false;
				cx += G[i].second;
			}
		}
		if (flag == true && v1 != v2) cnt++;
	}
	cout << cnt << endl;
	return 0;
}