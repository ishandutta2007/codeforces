#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S;

int main() {
	cin >> S;
	string T = S; reverse(T.begin(), T.end());
	cout << S + T << endl;
	return 0;
}