#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
string S, T[1000]; int n;
int main() {
	cin >> S >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i]; if (S == T[i]) { cout << "YES" << endl; return 0; }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (S[0] == T[i][1] && S[1] == T[j][0]) { cout << "YES" << endl; return 0; }
		}
	}
	cout << "NO" << endl;
	return 0;
}