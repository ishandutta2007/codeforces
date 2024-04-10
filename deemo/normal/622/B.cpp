#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int a, b;	char c;	cin >> a >> c >> b;
	int x;	cin >> x;
	int z = x/60;
	a = (a + z) % 24;
	x %= 60;
	b += x;
	if (b >= 60)	a = (a + 1) % 24, b %= 60;
	if (a < 10)
		cout << 0;
	cout << a << ":";
	if (b < 10)
		cout << 0;
	cout << b << "\n";
	return	0;
}