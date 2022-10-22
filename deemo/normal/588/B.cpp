#include<iostream>

using namespace std;

int main(){
	long long x;
	cin >> x;
	for (long long i = 2; i * i <= x; i++)
		while (x % (i * i) == 0)	x /= i;
	cout << x << endl;
	return 0;
}