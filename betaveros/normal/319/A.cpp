#include <iostream>
using namespace std;
#define MOD 1000000007

int main() {
	char s[120];
	cin.getline(s, 110);
	int i;
	long long res = 0; // yolo
	for (i = 0; s[i] != '\0'; i++){
		res *= 2;
		if (s[i] == '1'){
			res += 1;
		}
		res %= MOD;
	}
	for (int j = 0; j < i - 1; j++) {
		res = (2 * res) % MOD;
	}
	cout << res << endl;
}