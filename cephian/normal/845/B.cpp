#include <bits/stdc++.h>
using namespace std;

int gs(string s) {return s[0]+s[1]+s[2];}

int main() {
	int sm = 0;
	string s,a,b;
	cin >> s;
	a = s.substr(0,3), b = s.substr(3,3);
	if(gs(a) > gs(b)) swap(a,b);
	while(gs(a) < gs(b)) {
		sort(a.begin(),a.end());
		sort(b.rbegin(),b.rend());
		if('9'-a[0] > b[0]-'0') a[0] = '9';
		else b[0] = '0';
		++sm;
	}
	cout << sm << "\n";
}