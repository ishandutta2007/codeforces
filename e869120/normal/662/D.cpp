#include<iostream>
#include<string>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		int t = stoi(S.substr(4, S.size() - 4));
		int u = S.size() - 4;
		int L = 1989, M = 1;
		for (int j = 0; j < u - 1; j++) { M *= 10; L += M; }M *= 10;
		while (t < L) { t += M; }
		cout << t << endl;
	}
	return 0;
}