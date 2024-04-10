#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>vec; string S;
int main() {
	cin >> S; S = 'A' + S + 'A';
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U' || S[i] == 'Y')vec.push_back(i);
	}
	int maxn = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		maxn = max(maxn, vec[i + 1] - vec[i]);
	}
	cout << maxn << endl;
	return 0;
}