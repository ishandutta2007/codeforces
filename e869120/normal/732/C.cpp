#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
long long a, b, c;
int main() {
	cin >> a >> b >> c;
	long long P = max({ a,b,c });
	if (P == a && P == b && P == c) { cout << "0" << endl; return 0; }
	if (P == a && P == b) { cout << (P - c - 1) << endl; }
	else if (P == b && P == c) { cout << (P - a - 1) << endl; }
	else if (P == c && P == a) { cout << (P - b - 1) << endl; }
	else if (P == a) { cout << (P - b - 1) + (P - c - 1) << endl; }
	else if (P == b) { cout << (P - c - 1) + (P - a - 1) << endl; }
	else if (P == c) { cout << (P - a - 1) + (P - b - 1) << endl; }
	return 0;
}