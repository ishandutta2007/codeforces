#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	string B;
};

bool operator<(const Node &a1, const Node &a2) {
	if (a1.B.size() < a2.B.size()) return true;
	if (a1.B.size() > a2.B.size()) return false;
	if (a1.B < a2.B) return true;
	return false;
}

Node dp[256][3];

void init() {
	for (int i = 0; i < 256; i++) {
		dp[i][0].B = "E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E8";
		dp[i][1].B = "E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E8";
		dp[i][2].B = "E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E869120E8";
	}
	dp[240][2].B = "x";
	dp[204][2].B = "y";
	dp[170][2].B = "z";
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 256; j++) dp[255 - j][2] = min(dp[255 - j][2], Node{ "!" + dp[j][2].B });
		for (int j = 0; j < 256; j++) dp[j][1] = min(dp[j][1], dp[j][2]);
		for (int j = 0; j < 256; j++) dp[j][0] = min(dp[j][0], dp[j][1]);
		for (int j = 0; j < 256; j++) dp[j][2] = min(dp[j][2], Node{ "(" + dp[j][0].B + ")" });
		for (int j = 0; j < 256; j++) {
			for (int k = 0; k < 256; k++) {
				dp[j & k][1] = min(dp[j & k][1], Node{ dp[j][1].B + "&" + dp[k][2].B });
				dp[j | k][0] = min(dp[j | k][0], Node{ dp[j][0].B + "|" + dp[k][1].B });
			}
		}
	}
}

int main() {
	init();
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		string B; cin >> B; int sum = 0;
		for (int j = 0; j < 8; j++) { if (B[j] == '1') sum += (1 << j); }
		cout << dp[sum][0].B << endl;
	}
	return 0;
}