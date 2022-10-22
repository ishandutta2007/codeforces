#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string s;	cin >> s;
	int ret = 1;
	for (int i = 1; i < 7; i++)
		ret += (s[i]=='1'?10:s[i] - '0');
	cout << ret << "\n";
	return	0;
}