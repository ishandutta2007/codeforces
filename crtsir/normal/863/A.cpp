#include<iostream>
using namespace std;
bool pd(string s)
{
	for(int i=0;i<s.size()/2;i++)
		if(s[s.size()-1-i]!=s[i])
			return false;
	return true;
}
int main(){
	string s;
	cin>>s;
	while(s[s.size()-1]=='0')
		s=s.substr(0,s.size()-1);
	if(pd(s))
		cout<<"YES";
	else
		cout<<"NO";
}