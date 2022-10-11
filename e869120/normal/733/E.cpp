#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string S; int n;
bool solve1(int pos) {
	if (pos < 0)return false;
	if (pos >= n)return true;
	int lc = pos, rc = pos, turn = 0;
	if (S[pos] == 'U')turn = 1;
	while (true) {
		if (lc < 0)return false;
		if (rc >= S.size())return true;
		if (turn == 1) { rc++; }
		if (turn == 0) { lc--; }
		if (turn == 1 && rc < S.size() && S[rc] == 'D')turn = 0;
		else if (turn == 0 && lc >= 0 && S[lc] == 'U')turn = 1;
	}
	return false;
}
vector<long long>solve(string T, int pos) {
	if (pos < 0 || pos >= T.size())return vector<long long>{};
	vector<long long>E;
	long long ct = T.size() - 2;
	if (T[T.size() - 1] == 'U')E.push_back(1);
	else {
		int v = T.size() - 1;
		while (T[v] == 'D')v--;
		E.push_back((T.size() - v) * 2 - 1);
		ct = v - 1;
	}
	long long rt = E[0], v = T.size() - 1;
	for (int i = T.size() - 2; i >= pos; i--) {
		v = min(v, 1LL * i);
		if (T[i] == 'D' && T[i + 1] == 'D') {
			while (T[v] == 'D')v--;
			rt += 2LL * (i - v) + 1;
		}
		if (T[i] == 'U' && T[i + 1] == 'U') { rt++; }
		if (T[i] == 'U' && T[i + 1] == 'D') { rt++; }
		if (T[i] == 'D' && T[i + 1] == 'U') {
			while (T[v] == 'D')v--;
			rt += 2LL * (i - v) + 1;
		}
		while (T[v] == 'D')v--;

		ct = min(ct, 1LL * i);
		while (T[ct] == 'D')ct--;
		rt += (v - ct) * 2; ct--;
		E.push_back(rt);
	}
	return E;
}
int main() {
	cin >> n >> S;
	int L = -1, R = n + 1, M;
	while (true) {
		M = (L + R) / 2;
		int p1 = solve1(M - 1), p2 = solve1(M);
		if (p1 == false && p2 == true) { break; }
		if (p1 == true)R = M;
		if (p2 == false)L = M;
	}
	vector<long long>a1 = solve(S, M);
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'U')S[i] = 'D'; else S[i] = 'U';
	}
	reverse(S.begin(), S.end());
	vector<long long>a2 = solve(S, S.size() - M);
	reverse(a1.begin(), a1.end());
	vector<long long>a3 = a2;
	for (int i = 0; i < a1.size(); i++)a3.push_back(a1[i]);
	for (int i = 0; i < a3.size(); i++) { if (i)cout << ' '; cout << a3[i]; }cout << endl;
	return 0;
}