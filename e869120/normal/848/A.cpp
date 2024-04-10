#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N; vector<long long>vec;

int main() {
	cin >> N;
	if (N == 0) {
		cout << "a" << endl;
		return 0;
	}
	else {
		while (N >= 1) {
			for (int i = 500; i >= 2; i--) {
				if (N >= 1LL * i*(i - 1) / 2) {
					N -= 1LL * i*(i - 1) / 2;
					vec.push_back(i);
					break;
				}
			}
		}
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec[i]; j++) cout << (char)('a' + i);
		}
		cout << endl;
	}
	return 0;
}