#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int x[3], y[3];
int main() {
	for (int i = 0; i < 3; i++)cin >> x[i] >> y[i];
	cout << "3" << endl;
	int Ex = x[1] - x[2], Ey = y[1] - y[2];
	cout << x[0] - Ex << ' ' << y[0] - Ey << endl;
	cout << x[0] + Ex << ' ' << y[0] + Ey << endl;
	int Fx = x[0] - x[1], Fy = y[0] - y[1];
	cout << x[2] - Fx << ' ' << y[2] - Fy << endl;
	return 0;
}