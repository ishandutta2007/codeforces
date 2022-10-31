#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	long long l, r;
	cin >> l >> r;
	cout << "YES" << endl;
	for (long long i = l; i <= r; i += 2)
		cout << i << " " << i + 1 << endl;
}