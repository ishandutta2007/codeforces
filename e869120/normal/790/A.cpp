#include <iostream>
#include <string>
using namespace std;

string S[100], T[100]; int N, K, C[109];

int main() {
	cin >> N >> K;
	for (int i = K; i <= N; i++) cin >> S[i];
	for (int i = 1; i <= K - 1; i++) C[i] = i;
	
	for (int i = K; i <= N; i++) {
		if (S[i] == "YES") {
			bool used[109]; for (int j = 0; j < 109; j++) used[j] = false;
			for (int j = i - (K - 1); j < i; j++) used[C[j]] = true;

			for (int j = 1; j <= K; j++) {
				if (used[j] == false) { C[i] = j; break; }
			}
		}
		else C[i] = C[i - (K - 1)];
	}

	for (int i = 1; i <= N; i++) {
		if (C[i] <= 25) { T[i] = 'A'; T[i] += ('a' + C[i]); }
		else { T[i] = 'B'; T[i] += ('a' + (C[i] - 26)); }
	}
	for (int i = 1; i <= N; i++) { if (i >= 2) cout << " "; cout << T[i]; }
	cout << endl;
	return 0;
}