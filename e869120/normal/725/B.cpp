#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
long long n; char f, g[7] = "fedabc";
string S;
int main() {
	cin >> S; n = stoll(S.substr(0, S.size() - 1)); f = S[S.size() - 1]; n--;
	int r = 0; for (int i = 0; i < 6; i++) { if (f == g[i])r = i; }r++;
	if (n % 4 == 0) { cout << n * 4 + r << endl; }
	if (n % 4 == 1) { cout << n * 4 + 3 + r << endl; }
	if (n % 4 == 2) { cout << n * 4 - 8 + r << endl; }
	if (n % 4 == 3) { cout << n * 4 - 5 + r << endl; }
	return 0;
}