#include <iostream>
#include <string>
using namespace std;

int N, pos; string S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < S.size(); i++) {
		if (i == S.size() - 1 || S[i] > S[i + 1]) { pos = i; break; }
	}
	string T = "";
	for (int i = 0; i < N; i++) { if (i == pos) continue; T += S[i]; }
	cout << T << endl;
	return 0;
}