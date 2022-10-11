#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

long long pl[1 << 20], pr[1 << 20];
char c[1000009]; string S;

int main() {
	scanf("%s", &c);
	for (int i = 0; i < 1000005; i++) {
		if (c[i] == 0) break;
		S += c[i];
	}
	for (int i = 0; i < (int)S.size() - 1; i++) {
		if (S.substr(i, 2) == "vv") { pl[i + 1]++; pr[i]++; }
	}
	for (int i = 1; i < (int)S.size(); i++) pl[i] += pl[i - 1];
	for (int i = (int)S.size() - 2; i >= 0; i--) pr[i] += pr[i + 1];

	long long ans = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'o') ans += pl[i] * pr[i];
	}
	cout << ans << endl;
	return 0;
}