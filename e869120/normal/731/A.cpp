#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string S;
int main() {
	cin >> S; S = 'a' + S; int ret = 0;
	for (int i = 0; i < S.size() - 1; i++) {
		int D = abs(S[i] - S[i + 1]);
		ret += min(D, 26 - D);
	}
	cout << ret << endl;
	return 0;
}