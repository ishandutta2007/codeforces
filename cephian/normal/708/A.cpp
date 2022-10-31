#include <iostream>

using namespace std;

string s;

char cnv(char c) {
	return (c-'a'+26-1)%26 + 'a';
}

int main() {
	ios::sync_with_stdio(0);
	cin >> s;
	int a=0,n=s.size(),b;	
	while(a < n && s[a] == 'a') ++a;
	b=a;
	while(b < n && s[b] != 'a') ++b;
	if(a == n) --a;
	for(int i = a; i < b; ++i)
		s[i] = cnv(s[i]);
	cout << s << "\n";
	return 0;
}