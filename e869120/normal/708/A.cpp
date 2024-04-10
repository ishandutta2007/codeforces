#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string S;
int main() {
	cin >> S; bool OK = false;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != 'a')OK = true;
		if (OK == false && S[i] == 'a' && i == (S.size() - 1)) {
			S[i] = 'z'; break;
		}
		if (OK == true) {
			if (S[i] == 'a')break;
			S[i]--;
		}
	}
	cout << S << endl;
	return 0;
}