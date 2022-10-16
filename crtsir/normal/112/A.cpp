#include<iostream>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>64&&s1[i]<91)
			s1[i]+=32;
		if(s2[i]>64&&s2[i]<91)
			s2[i]+=32;
	}
	if(s1>s2)
		cout<<1;
	if(s1==s2)
		cout<<0;
	if(s1<s2)
		cout<<-1;
}