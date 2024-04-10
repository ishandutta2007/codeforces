#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a1,a2;
	cin >> a1 >> a2;
	int turns = 0;
	while (a1 > 0 && a2 > 0) {
		if (a1 >= a2) {
			a1 -= 2;
			a2 ++;
		} else {
			a1 ++;
			a2 -= 2;
		}
		turns++;
	}
	if (a1 == -1 || a2 == -1) turns--;
	cout << turns;
	return 0;
}