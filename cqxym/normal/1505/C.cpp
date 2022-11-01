#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length();
	for(register int i=2;i<l;i++){
		if(s[i]-'A'!=(s[i-1]+s[i-2]-('A'<<1))%26){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}