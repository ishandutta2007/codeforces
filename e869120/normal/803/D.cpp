#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string S; vector<int>D; int n;
bool solve(int p) {
	if (p <= 0)return false;
	int G = 0, H = 1;
	for (int i = 0; i < D.size(); i++) {
		if (D[i] + G <= p) { G += D[i]; }
		else { H++; G = D[i]; }
		if (G > p)return false;
	}
	if (H > n)return false;
	return true;
}
int main() {
	cin >> n; S = "";
	while (S == "") { getline(cin, S); }
	int t = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ' ' || S[i] == '-' || i == S.size() - 1) { D.push_back(t + 1); t = 0; }
		else { t++; }
	}
	int L = 0, R = 10000000, M;
	while (true) {
		M = (L + R) / 2;
		bool p1 = solve(M - 1), p2 = solve(M);
		if (p1 == false && p2 == true) { cout << M << endl; break; }
		if (p1 == true) { R = M; }
		else { L = M; }
	}
	return 0;
}