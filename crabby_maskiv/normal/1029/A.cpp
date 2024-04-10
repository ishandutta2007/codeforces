#include<iostream>
#include<cstring> 
using namespace std;
string s;
string f(string str)
{
	int len=str.length();
	if(len==1) return str;
	for(int i=1;i<len;i++)
	{
		if(str.substr(i)==str.substr(0,len-i))
		{
			return str.substr(len-i);
		}
	}
	return str;
}
int main()
{
	int n,k;
	cin>>n>>k;
	cin>>s;
	string tmp=f(s);
	while(--k) s+=tmp;
	cout<<s;
	return 0;
}