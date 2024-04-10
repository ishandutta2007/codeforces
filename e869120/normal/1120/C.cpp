#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

const int MAX_N = 5009;
const int Debug = 1;

// -------------------------  ---------------------

class CompressString1 {
public:
	vector<vector<int>> c;
	vector<int> t, dp;

	int solve(int N, int A, int B, string S) {
		c.resize(N + 1, vector<int>(N + 1, 0));
		t.resize(N + 1, 0);
		dp.resize(N + 1, 0);

		for (int i = 0; i <= N; i++) { c[N][i] = 0; c[i][N] = 0; }
		for (int i = N - 1; i >= 0; i--) {
			for (int j = N - 1; j >= i; j--) {
				if (S[i] == S[j]) c[i][j] = c[i + 1][j + 1] + 1;
				else c[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			t[i] = 0;
			for (int j = 0; j <= i - 1; j++) {
				t[i] = max(t[i], min(i - j, c[j][i]));
			}
		}

		for (int i = 0; i <= N; i++) dp[i] = (1 << 30);
		dp[0] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j <= i + t[i]; j++) dp[j] = min(dp[j], dp[i] + B);
			dp[i + 1] = min(dp[i + 1], dp[i] + A);
		}
		return dp[N];
	}
};

// ----------------------------  ------------------------------

class CompressString2 {
public:
	int dp[MAX_N];

	bool check(string A1, string A2) {
		// A1  A2 
		for (int i = 0; i < A1.size(); i++) {
			for (int j = i; j <= A1.size(); j++) {
				string V = A1.substr(i, j - i);
				if (V == A2) return true;
			}
		}
		return false;
	}

	int solve(int N, int A, int B, string S) {
		for (int i = 0; i <= N; i++) dp[i] = (1 << 30);
		dp[0] = 0;
		for (int i = 0; i < N; i++) {
			dp[i + 1] = min(dp[i + 1], dp[i] + A);
			for (int j = i + 1; j <= N; j++) {
				string V1 = S.substr(i, j - i);
				string V2 = S.substr(0, i);
				bool I = check(V2, V1);
				if (I == true) dp[j] = min(dp[j], dp[i] + B);
			}
		}
		return dp[N];
	}
};

int main() {
	if (Debug == 1) {
		int n, a, b; string str;
		CompressString1 G;
		cin >> n >> a >> b >> str;
		cout << G.solve(n, a, b, str) << endl;
	}
	if (Debug == 2) {
		for (int t = 0; t <= 10000; t++) {
			int n, a, b; string str = "";
			n = 4; a = rand() % 5000 + 1; b = rand() % 5000 + 1;
			for (int j = 0; j < n; j++) { str += (char)('a' + (rand() % 4)); }

			CompressString1 V1; int J1 = V1.solve(n, a, b, str);
			CompressString2 V2; int J2 = V2.solve(n, a, b, str);

			if (J1 != J2) {
				cout << "Wrong Answer on Test #" << t + 1 << endl;
				cout << "Jury = " << J2 << ", Output = " << J1 << endl;
				cout << endl;
				cout << n << " " << a << " " << b << endl;
				cout << str << endl;
				cout << endl;
			}
			//cout << J1 << " " << clock() << endl;
		}
	}
	return 0;
}