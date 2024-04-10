#include<iostream>
#include<string>
#include<vector>
using namespace std;
string S, T; vector<string>U;
bool vowel(char F) {
	if (F == 'a' || F == 'i' || F == 'u' || F == 'e' || F == 'o')return true;
	return false;
}
int main() {
	cin >> S; int G = 0;
	for (int i = 0; i <= S.size(); i++) {
		bool R = true; if (i - G <= 1)R = false;
		if (i - G >= 2) {
			if (vowel(S[i - 2]) == true || vowel(S[i - 1]) == true || vowel(S[i]) == true)R = false;
			if (S[i - 2] == S[i - 1] && S[i - 1] == S[i])R = false;
		}
		if (i == S.size() || R == true) { U.push_back(T); T = ""; G = i; }
		if (i < S.size())T += S[i];
	}
	for (int i = 0; i < U.size(); i++) { if (i)cout << " "; cout << U[i]; }cout << endl;
	return 0;
}