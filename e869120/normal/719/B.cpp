#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
string S;
int p1, p2, q1, q2, n;
int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) {
		if (i % 2 == 0 && S[i] == 'b')p1++;
		if (i % 2 == 0 && S[i] == 'r')p2++;
		if (i % 2 == 1 && S[i] == 'r')q1++;
		if (i % 2 == 1 && S[i] == 'b')q2++;
	}
	int D1 = max(abs(p1 - (int)(S.size() + 1) / 2), abs(q1 - (int)S.size() / 2));
	int D2 = max(abs(p2 - (int)(S.size() + 1) / 2), abs(q2 - (int)S.size() / 2));
	cout << min(D1, D2) << endl;
	return 0;
}