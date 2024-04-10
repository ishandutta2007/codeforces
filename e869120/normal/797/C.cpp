#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string S, T, U;
int main() {
	cin >> S; int pos = 0;
	while (pos < S.size()) {
		char c = 'z'; int maxid = pos; for (int i = pos; i < S.size(); i++) { if (c >= S[i]) { c = S[i]; maxid = i; } }
		while (T.size() >= 1 && c >= T[T.size() - 1]) { U += T[T.size() - 1]; T.pop_back(); }
		for (int i = pos; i <= maxid; i++) {
			if (c == S[i])U += S[i];
			else T += S[i];
		}
		pos = maxid + 1;
	}
	reverse(T.begin(), T.end()); U += T;
	cout << U << endl;
	return 0;
}