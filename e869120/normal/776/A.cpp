#include<iostream>
#include<string>
using namespace std;
int n; string S, T, U, V;
int main() {
	cin >> S >> T >> n;
	cout << S << ' ' << T << endl;
	for (int i = 0; i < n; i++) {
		cin >> U >> V;
		if (S == U)S = V;
		else if (T == U)T = V;
		cout << S << ' ' << T << endl;
	}
	return 0;
}