#include <iostream>
#include <cstdio>
using namespace std;
int c[1003];
string s;
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read();
	cin >> s;
	for (int i = 0; i < n; ++ i)
		++ c[s[i]];
	for (int i = 1; i <= c['n']; ++ i)
		cout << '1' << " ";
	for (int i = 1; i <= c['z']; ++ i)
		cout << '0' << " ";
}