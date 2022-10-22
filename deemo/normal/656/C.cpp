#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, res = 0;
string s;

void f(int a, int b, char c){
	if (c < 'A' || c == '.')	return; 
	if (c < 'a')	c -= 'A';
	else	c -= 'a';
	int z = c + 1;
	res += z * a - z * b;
}

int main(){
	cin >> s;	n = s.size();
	for (char c:s)	
		f('@' < c && '[' > c, '`' < c && '{' > c, c);
	cout << res << "\n";
	return	0;	
}