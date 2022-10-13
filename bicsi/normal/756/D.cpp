#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if(a >= kMod)
		a -= kMod;
	return a;
}
int sub(int a, int b) {
	a -= b;
	if(a < 0) 
		a += kMod;
	return a;
}
int mul(int a, int b) {
	return 1LL * a * b % kMod;
}

string str;
int DP[5005][5005], C[5005][5005];

int main() {
	int n;
	cin >> n >> str;

	DP[0][0] = 1;
	str = "#" + str;
	for(int i = 1; i <= n; ++i) {
		char now = str[i];

		int j;
		for(j = i - 1; j >= 0; --j) {
			if(str[j] == str[i])
				break;
		}

		DP[i][0] = 1;
		for(int k = 1; k <= i; ++k) {
			DP[i][k] = add(DP[i - 1][k], DP[i - 1][k - 1]);
			if(j >= 0) DP[i][k] = sub(DP[i][k], DP[j][k - 1]);
		}
	}

	for(int i = 0; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}

	for(int i = 0; i <= 5; ++i, cerr << endl)
		for(int j = 0; j <= i; ++j)
			cerr << DP[i][j] << " ";

	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans = add(ans, mul(DP[n][i], C[n - 1][i - 1]));	
	}
	cout << ans << endl;



	return 0;
}