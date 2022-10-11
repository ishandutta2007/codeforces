#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, b = 0; string e = "1";
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string S; cin >> S;
		if (S == "0") { cout << "0" << endl; return 0; }
		bool OK = true; for (int i = 1; i < S.size(); i++) { if (S[i] != '0')OK = false; }
		if (OK == true && S[0] == '1') { b += (S.size() - 1); }
		else { e = S; }
	}
	cout << e;
	for (int i = 0; i < b; i++)cout << "0"; cout << endl;
	return 0;
}