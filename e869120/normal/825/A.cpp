#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
string S, T, U; int n;
int main() {
	cin >> n >> S;
	for (int i = 0; i <= S.size(); i++) {
		if (S[i] == '0' || i == S.size()) {
			if (U == "")T += "0";
			else T += ('0' + U.size());
			U = "";
		}
		else U += "1";
	}
	cout << T << endl;
	return 0;
}