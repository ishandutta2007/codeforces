#include <iostream>
using namespace std;

int N, M, digit = 1500;

int main() {
	cin >> N >> M;
	for (int i = 0; i < digit; i++) { if (i % 2 == 0) cout << "1"; else cout << "8"; } cout << "2" << endl;
	for (int i = 0; i < digit; i++) { if (i % 2 == 1) cout << "1"; else cout << "8"; } cout << "8" << endl;
	return 0;
}