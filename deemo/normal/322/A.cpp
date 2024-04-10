#include<iostream>

using namespace std;

int main(){
	int a, b;	cin >> a >> b;
	cout << a + b - 1 << endl;
	for (int i = 1; i <= b; i++)
		cout << 1 << " " << i << endl;
	for (int i = 2; i <= a; i++)
		cout << i << " " << 1 << endl;
	return 0;
}