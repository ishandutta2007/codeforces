#include <iostream>
#include <cstdio>
using namespace std;
 
int c;
string s;
int main() {
	cin >> s;
	for(int i=s.size()-1; i>=0; i--) {
		if(s[i]=='0') c++;
		else if(c) c--;
		else s[i] = '0';
	}
	cout << s;
	return 0;
}