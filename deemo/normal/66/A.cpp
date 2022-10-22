#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool grt(string a, string b){
	if (a.size() > b.size())
		return	true;
	if (a.size() < b.size())
		return	false;
	return	a > b;
}

int main(){
	string s;	cin >> s;
	if (grt(s, "9223372036854775807"))	cout << "BigInteger\n";
	else if (grt(s, "2147483647"))	cout << "long\n";
	else if (grt(s, "32767"))	cout << "int\n";
	else if (grt(s, "127"))	cout << "short\n";
	else cout << "byte\n";
	return	0;
}