#include<bits/stdc++.h>
using namespace std;
bool isvo(char ch)
{
	if(ch=='a'||ch=='i'||ch=='e'||ch=='o'||ch=='u') return true;
	return false;
}
int main()
{
	string s,t;
	cin>>s>>t;
	if(s.length()!=t.length())
	{
		cout<<"No"<<endl;
	}
	else{
		bool ok=1;
		for(int i=0;i<s.length();i++)
		{
			if(isvo(s[i])&&!isvo(t[i])) ok=0;
			if(!isvo(s[i])&&isvo(t[i])) ok=0;
		}
		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}