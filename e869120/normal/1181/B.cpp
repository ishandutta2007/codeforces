#include <bits/stdc++.h>
using namespace std;

vector<int>cand;
long long N; string S;
int a[100009];

string calc(int pos) {
	for (int i = 0; i < 100009; i++) a[i] = 0;
	for (int i = 0; i < pos; i++) a[pos - i - 1] += (S[i] - '0');
	for (int i = pos; i < N; i++) a[N - i - 1] += (S[i] - '0');
	for (int i = 0; i < 100002; i++) {
		a[i + 1] += (a[i] / 10);
		a[i] %= 10;
	}
	string str = ""; bool flag = false;
	for (int i = 100001; i >= 0; i--) {
		if (a[i] >= 1) flag = true;
		if (flag == true) str += ('0' + a[i]);
	}
	return str;
}

int main() {
	cin >> N >> S;
	for (int i = (N / 2) - 2; i >= 0; i--) {
		if (S[i] != '0') { cand.push_back(i); break; }
	}
	for (int i = (N / 2) + 2; i < N; i++) {
		if (S[i] != '0') { cand.push_back(i); break; }
	}
	for (int i = (N / 2) - 1; i <= (N / 2) + 1; i++) {
		if (S[i] != '0') cand.push_back(i);
	}
	string ans = "";
	for (int i = 0; i < cand.size(); i++) {
		string B = calc(cand[i]);
		if (ans.size() == 0) ans = B;
		else if (ans.size() > B.size()) ans = B;
		else if (ans.size() == B.size() && ans > B) ans = B;
	}
	cout << ans << endl;
	return 0;
}