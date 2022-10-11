#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string S, T;
int main() {
	cin >> S; T = S;
	for (int i = 1; i <= S.size(); i++) {
		string U = T;
		for (int j = 0; j < U.size(); j++) { U[(j + 1) % U.size()] = T[j]; }
		T = U; if (S == T) { cout << i << endl; break; }
	}
	return 0;
}