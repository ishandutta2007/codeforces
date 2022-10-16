#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]<93)
			s[i]=s[i]+32;
	for(int i=1;i<s.size();i++)
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
		{
			s=s.substr(0,i)+s.substr(i+1,s.size()-i);
			i--;
		}
		else
		{
			s=s.substr(0,i)+'.'+s.substr(i,s.size()-i);//a.bab
			i++;
		}
	int i=0;
	if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
		s=s.substr(1,s.size()-1);
	else
		if(s[i]!='.')
			s='.'+s;
	cout<<s;
}