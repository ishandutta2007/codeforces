#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
using namespace std;
string S; int minx = 7;
int main() {
	cin >> S;
	for (int i = 0; i < 1000000; i++) {
		string T = to_string(i); while (T.size() < 6)T = '0' + T;
		int cnt = 0; for (int j = 0; j < T.size(); j++) { if (S[j] != T[j])cnt++; }
		int R = T[0] + T[1] + T[2];
		int S = T[3] + T[4] + T[5];
		if (R == S)minx = min(minx, cnt);
	}
	cout << minx << endl;
	return 0;
}