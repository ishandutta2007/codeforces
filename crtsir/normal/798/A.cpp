#include<iostream>
using namespace std;
int pd(string s)
{
	int f=0;
	for(int i=0;i<s.size()/2;i++)
		if(s[s.size()-1-i]!=s[i])
			f++;
	if(f==1)
		return 1;
	else
		return f;
}
int main(){
	string s;
	cin>>s;
	if(s.size()%2&&pd(s)==0)
	{
		cout<<"YES";
		return 0;
	}
	if(pd(s)==1)
		cout<<"YES";
	else
		cout<<"NO";
}