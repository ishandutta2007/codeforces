#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int n, c, maxn; string S;
int main() {
	cin >> n;
	while (c < n) {
		cin >> S;
		int F = 0; for (int i = 0; i < S.size(); i++) { if (S[i] <= 'Z')F++; }
		maxn = max(maxn, F);
		c += S.size() + 1;
	}
	cout << maxn << endl;
	return 0;
}