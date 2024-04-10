#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<string> read_inner() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	return a;
}

int nxt(string s) {
	cout << "next ";
	for (auto& ch : s) {
		cout << ch << " ";
	}
	cout << endl;
	return (int)read_inner().size();
}

int main() {
	/*

	they meet after t + smth steps

	the first one made t + smth steps
	the second one made 2 * (t + smth) steps

	since they are at the same position:

	2 * (t + smth) - c * ? = t + smth
	t + smth = c * ?

	after t steps the ones remaing in start will reach the finish

	and the other ones will be at position
	smth + t on the circle <=> the finish line

	*/

	string a = "01234567";
	string b = "8";
	string c = "9";
	while (1) {
		nxt(b + c);
		if (nxt(c) == 2) {
			break;
		}
	}
	while (1) {
		if (nxt(a + b + c) == 1) {
			cout << "done" << endl;
			exit(0);
		}
	}
}