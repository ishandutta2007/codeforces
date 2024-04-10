#include <iostream>

using namespace std;

int n;
string s;
int b=0,g=0,r=0;
int a[3];
char c[3] = {'B','G','R'};

int main() {
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'R') ++r;
		if(s[i] == 'G') ++g;
		if(s[i] == 'B') ++b;
	}
	if(r != 0 && b != 0 && g != 0) {
		cout << "BGR\n";
		return 0;
	}
	if(r == 0 && b == 0 && g != 0) {
		cout << "G\n";
		return 0;
	}
	if(r == 0 && b != 0 && g == 0) {
		cout << "B\n";
		return 0;
	}
	if(r != 0 && b == 0 && g == 0) {
		cout << "R\n";
		return 0;
	}
	a[0] = b;
	a[1] = g;
	a[2] = r;
	for(int i = 0; i < 3; ++i) {
		if(a[i] == 0) cout << c[i];
		else if(a[(i+1)%3] > 1 || a[(i+2)%3] > 1) cout << c[i];
	}
	cout << "\n";
	return 0;
}