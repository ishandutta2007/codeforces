#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	stringstream ss;
	for (int i = 1; i <= 1000; i++)	ss << i;
	string s;	ss >> s;
	int n;	cin >> n;
	cout << s[--n] << "\n";
	return 0;
}