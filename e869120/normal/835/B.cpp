#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int n, a[100000]; string S;
int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) { a[S[i] - '0']++; n -= (S[i] - '0'); }
	if (n <= 0) { cout << "0" << endl; return 0; }
	int cnt = 0;
	for (int i = 0; i <= 9; i++) {
		while (a[i] >= 1) { cnt++; n -= (9 - i); a[i]--; if (n <= 0) { cout << cnt << endl; break; } }
		if (n <= 0)break;
	}
	return 0;
}