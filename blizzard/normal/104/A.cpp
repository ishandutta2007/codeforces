#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, a[50], b[50];
	cin >> n;
	if (n <= 10) {
		cout << "0";
		return 0;
	}
	if (n <= 19 || n == 21) {
		cout << "4";
		return 0;
	}
	if (n == 20) {
		cout << "15";
		return 0;
	}
	if (n > 21) {
		cout << "0";
	}
}