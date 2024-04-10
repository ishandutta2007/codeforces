#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<s.size();i++)
		if(s[i]>='a'&&s[i]<='z')
			a++;
		else if(s[i]>='A'&&s[i]<='Z')
			b++;
	if(a<b)
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>=97&&s[i]<=122)
				s[i]=s[i]-32;
			cout<<s[i];
		}
	else
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
				s[i]+=32;
			cout<<s[i];
		}
}