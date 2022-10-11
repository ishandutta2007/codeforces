#include<iostream>
#include<string>
using namespace std;
int n, k, a, b; string S; bool OK = true;
int main() {
	cin >> n >> k >> a >> b;
	if (a < b) { OK = false; swap(a, b); }
	for (int i = 0; i < n; i++)S += "G";
	int a1 = a / (b + 1), a2 = a % (b + 1);
	if (a1 > k || (a1 == k && a2 >= 1)) { cout << "NO" << endl; return 0; }
	int c = 0;
	for (int i = 0; i < a2; i++) { c += (a1 + 1); S[c] = 'B'; c++; }
	for (int i = a2; i < b; i++) { c += a1; S[c] = 'B'; c++; }
	if (OK == false) {
		for (int i = 0; i < S.size(); i++) { if (S[i] == 'G')S[i] = 'B'; else S[i] = 'G'; }
	}
	cout << S << endl;
	return 0;
}