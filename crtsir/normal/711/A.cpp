#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x,f=1;
	cin>>x;
	string s[x];
	for(int i=0;i<x;i++)
		cin>>s[i];
	for(int i=0;i<x;i++)
	{
		if(s[i].substr(0,2)=="OO")
		{
			f=0;
			s[i]="++|"+s[i].substr(3,2);
			break;
		}
		if(s[i].substr(3,2)=="OO")
		{
			f=0;
			s[i]=s[i].substr(0,2)+"|++";
			break;
		}

	}
	if(f==1)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<x;i++)
		cout<<s[i]<<endl;
}