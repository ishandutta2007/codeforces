#include<iostream>
using namespace std;
bool aeiou(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
		return true;
	return false;
}
int main()
{
	string s,x;
	cin>>x>>s;
	cout<<s[0];
	for(int i=1;i<s.size();i++)
		if(!aeiou(s[i-1])||!aeiou(s[i]))
			cout<<s[i];
}