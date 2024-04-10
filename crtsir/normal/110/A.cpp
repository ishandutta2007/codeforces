#include<iostream>
using namespace std;
int main(){
	string s;
	int f=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='4'||s[i]=='7')
			f++;
	if(f==0)
	{
		cout<<"NO";
		return 0;
	}
	while(f!=0)
	{
		if(f%10!=4&&f%10!=7)
		{
			cout<<"NO";
			return 0;
		}
		f=f/10;
	}
	cout<<"YES";
}