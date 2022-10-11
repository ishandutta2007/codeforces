#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[300000]; string S;
bool used[300000];
int main() {
	cin >> n >> S; int E = 0, cnt = 0;
	for (int i = 0; i < S.size(); i++) { if (S[i] == 'D')a[i] = 1; if (S[i] == 'R')a[i] = 2; }
	int T = n, B = 0, R = 0;
	while (T > 1 && R < 10000000) {
		R++;
		if (used[B] == true) { B++; B %= S.size(); continue; }
		if (cnt >= 1 && E != a[B]) { cnt--; used[B] = true; T--; continue; }
		if (E != a[B]) { cnt = 1; E = a[B]; }
		else { cnt++; }
		B++; B %= S.size();
	}
	for (int i = 0; i < n; i++) { if (used[i] == false) { cout << S[i] << endl; break; } }
	return 0;
}