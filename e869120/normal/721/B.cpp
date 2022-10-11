#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
string S[100], T; int n, k, cnt, w[10000], sum;
int WA(int p) {
	return p + ((p - 1) / k) * 5;
}
int main() {
	cin >> n >> k; for (int i = 0; i < n; i++)cin >> S[i]; cin >> T;
	for (int i = 0; i < n; i++) { if (S[i] == T)cnt++; w[S[i].size()]++; }
	for (int i = 1; i < T.size(); i++) { sum += w[i]; }
	int L = sum + 1, R = sum + (w[T.size()] - cnt + 1);
	cout << WA(L) << ' ' << WA(R) << endl;
	return 0;
}