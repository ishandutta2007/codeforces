#include<iostream>
#include<string>
using namespace std;
int dp[1 << 18], Q;
int main() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		char c; long long p; cin >> c >> p;
		string S = to_string(p);
		while (S.size() < 18)S = "0" + S;
		int G = 0;
		for (int j = 0; j < 18; j++)G += (1 << j)*((S[j] - '0') % 2);
		if (c == '+')dp[G]++;
		if (c == '-')dp[G]--;
		if (c == '?')cout << dp[G] << endl;
	}
	return 0;
}