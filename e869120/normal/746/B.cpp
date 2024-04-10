#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string S, T; int n;
int main() {
	cin >> n >> S; T = S;
	if (S.size() % 2 == 0) {
		int t = S.size() / 2 - 1, r = 0;
		while (t >= 0) {
			T[t] = S[2 * r];
			T[S.size() - 1 - t] = S[2 * r + 1];
			t--; r++;
		}
	}
	if (S.size() % 2 == 1) {
		int t = S.size() / 2 - 1, r = 0;
		T[S.size() / 2] = S[0];
		while (t >= 0) {
			T[t] = S[2 * r + 1];
			T[S.size() - 1 - t] = S[2 * r + 2];
			t--; r++;
		}
	}
	cout << T << endl;
	return 0;
}