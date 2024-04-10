#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	int n;	cin >> n;
	string s;	cin >> s;
	int b = 0;
	int tn = n;
	while (s[b] == '.')	b++;
	while (s[n - 1] == '.')	n--;
	if (s[b] == 'R'){
		cout << b + 1 << " ";
		while (b < n && s[b] == 'R')	b++;
		if (b == n)	cout << b + 1 << endl;
		else	cout << b << endl;
		return 0;
	}
	int temp = b;
	cout << n << " " << temp << endl;
	return 0;
}