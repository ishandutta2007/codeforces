#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long n, q, a, power[63]; string S;
int main() {
	cin >> n >> q;
	power[0] = 1; for (int i = 1; i < 63; i++)power[i] = power[i - 1] * 2;
	int Y = 0; for (int i = 0; i < 63; i++) { if (n == power[i] - 1)Y = i - 1; }
	for (int i = 0; i < q; i++) {
		cin >> a >> S;
		int depth = 0; for (int j = 0; j < 63; j++) { if (a%power[j] == 0)depth = j; }
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == 'U' && depth < Y && (a%power[depth + 2]) < power[depth + 1]) { a += power[depth]; depth++; }
			else if (S[j] == 'U' && depth < Y && (a%power[depth + 2]) > power[depth + 1]) { a -= power[depth]; depth++; }
			if (S[j] == 'L' && depth >= 1) { a -= power[depth - 1]; depth--; }
			if (S[j] == 'R' && depth >= 1) { a += power[depth - 1]; depth--; }
		}
		cout << a << endl;
	}
	return 0;
}