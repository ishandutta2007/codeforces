#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, cnt; string S;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S;
		if (S[0] == 'I')cnt += 20;
		if (S[0] == 'T')cnt += 4;
		if (S[0] == 'C')cnt += 6;
		if (S[0] == 'O')cnt += 8;
		if (S[0] == 'D')cnt += 12;
	}
	cout << cnt << endl;
	return 0;
}