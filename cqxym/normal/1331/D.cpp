#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int c=s[s.length()-1]-'0';
	cout<<c%2;
	return 0;
}