#include<iostream>
#include<map>
using namespace std;
long long a, b, c, d, x[300000];
map<long long, long long>M;
int main() {
	cin >> a >> b >> c >> d;
	for (long long i = 0; i*i <= 4 * (a + b + c + d); i++) { M[i*(i - 1) / 2] = i + 1; x[i] = i*(i - 1) / 2; }
	if (M[a] == 0 || M[d] == 0) { cout << "Impossible" << endl; return 0; }
	long long e0 = M[a] - 1, e1 = M[d] - 1, e = e0 + e1;
	if (a == 0 || d == 0) {
		if (a == 0 && d == 0) {
			if (b == 0 && c == 0) { cout << "0" << endl; return 0; }
			else if (b == 0 && c == 1) { cout << "10" << endl; return 0; }
			else if (b == 1 && c == 0) { cout << "01" << endl; return 0; }
			else { cout << "Impossible" << endl; return 0; }
		}
		if (a == 0) {
			if (b == 0 && c == 0) {
				for (int i = 0; i < e1; i++) { cout << "1"; } cout << endl; return 0;
			}
		}
		if (d == 0) {
			if (b == 0 && c == 0) {
				for (int i = 0; i < e0; i++) { cout << "0"; } cout << endl; return 0;
			}
		}
	}
	if (a + b + c + d != x[e]) { cout << "Impossible" << endl; return 0; }
	long long A1 = b / e1, A2 = b%e1;
	for (int i = 0; i < A1; i++)cout << "0";
	for (int i = 0; i < e1 - A2; i++)cout << "1"; if (A1 != e0)cout << "0";
	for (int i = 0; i < A2; i++)cout << "1";
	for (int i = 0; i < e0 - 1 - A1; i++)cout << "0"; cout << endl;
	return 0;
}