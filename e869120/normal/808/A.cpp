#include<iostream>
#include<string>
using namespace std;
long long n, power[10000000];
int main() {
	cin >> n; string S = to_string(n);
	power[0] = 1; for (int i = 1; i < 12; i++)power[i] = power[i - 1] * 10;
	if (S[0] == '9') {
		cout << power[S.size()] - n << endl;
	}
	else {
		cout << (1LL * (S[0] - '0' + 1)*power[S.size() - 1]) - n << endl;
	}
	return 0;
}