#include<bits/stdc++.h>
using namespace std;
bool check(string s){
	for(int i=0;i<s.size();i++)
		if(s[i]!=s[s.size()-i-1])
			return 0;
	return 1;
}
int main(){
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		for(char c='A';c<='Z';c++)
			if(check(s.substr(0,i)+c+s.substr(i)))
			{
				cout<<s.substr(0,i)+c+s.substr(i);
				return 0;
			}
		for(char c='a';c<='z';c++)
			if(check(s.substr(0,i)+c+s.substr(i)))
			{
				cout<<s.substr(0,i)+c+s.substr(i);
				return 0;
			}
	}
	cout<<"NA";
}