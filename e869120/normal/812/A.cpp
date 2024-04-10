#include<iostream>
using namespace std;
int a[4][4];
int main() {
	for (int i = 0; i < 4; i++) { for (int j = 0; j < 4; j++)cin >> a[i][j]; }
	for (int i = 0; i < 4; i++) {
		if (a[i][3] == 0)continue;
		if (a[i][0] == 1 || a[i][1] == 1 || a[i][2] == 1 || a[(i + 1) % 4][0] == 1 || a[(i + 2) % 4][1] == 1 || a[(i + 3) % 4][2] == 1) { cout << "YES" << endl; return 0; }
	}
	cout << "NO" << endl;
	return 0;
}