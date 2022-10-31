#include <iostream>

using namespace std;

int n, k;
string str;

void handle2() {
	int t1 = 0, t2 = 0;
	for (int i = 0; i < str.size(); ++i) {
		t1 += (i % 2) ^ (str[i] == 'B');
		t2 += (i % 2) ^ (str[i] == 'A');
	}
	cout << min(t1, t2) << "\n";
	for (int i = 0; i < str.size(); ++i) {
		cout << (((i % 2) ^ (t1 <= t2)) ? "A" : "B");
	}
	cout << "\n";
}

char getc(int i) {
	if (i < 0 || i >= str.size())
		return '0';
	return str[i];
}

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> k;
	cin >> str;
	if (k == 2) {
		handle2();
	} else {
		int change = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == getc(i - 1)) {
				++change;
				char j = 'A';
				while (j == getc(i - 1) || j == getc(i + 1))
					++j;
				str[i] = j;
			}
		}
		cout << change << "\n" << str << "\n";
	}

	return 0;
}