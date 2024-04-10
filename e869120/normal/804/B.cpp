#include<iostream>
#include<string>
using namespace std;
string S; long long power[4000000], c, mod = 1000000007, cnt;
int main() {
	cin >> S; power[0] = 1;
	for (int i = 1; i < 4000000; i++) {
		power[i] = power[i - 1] * 2; power[i] %= mod;
	}
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a')c++;
		if (S[i] == 'b')cnt += (power[c] - 1);
		cnt %= mod;
	}
	cout << cnt << endl;
	return 0;
}