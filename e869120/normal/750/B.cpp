#include<iostream>
#include<string>
using namespace std;
int main() {
	int n; cin >> n; int r = 0;
	for (int i = 0; i < n; i++) {
		string S; int a; cin >> a >> S;
		if (S == "North") {
			r -= a;
			if (r < 0) { cout << "NO" << endl; return 0; }
		}
		if (S == "South") {
			r += a;
			if (r > 20000) { cout << "NO" << endl; return 0; }
		}
		if (S == "East" || S == "West") {
			if (r == 0 || r == 20000) { cout << "NO" << endl; return 0; }
		}
	}
	if (r != 0) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;
	return 0;
}