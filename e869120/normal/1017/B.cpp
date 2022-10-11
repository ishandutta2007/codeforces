#include <iostream>
#include <string>
using namespace std;

string S1, S2; long long n, a, b, c, d;

int main() {
	cin >> n >> S1 >> S2;
	for (int i = 0; i < S1.size(); i++) {
		if (S1[i] == '0') a++;
		if (S1[i] == '1') b++;
		if (S1[i] == '0' && S2[i] == '1') c++;
		if (S1[i] == '1' && S2[i] == '1') d++;
	}
	cout << a*b - c*d << endl;
	return 0;
}