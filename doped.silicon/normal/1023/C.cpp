#include <iostream>
using namespace std;

int main() {
	long long int a,b,c,d;
	string s,s1="";
	cin>>a>>b;
	cin>>s;
	c=0;d=0;
	for(int i=0;i<a;i++)
	{
		if(s[i]=='('&&c<b/2)
		{
			c++;
			cout<<"(";
		}
		else if(s[i]==')'&&d<b/2)
		{
			d++;
			cout<<")";
		}
	}
	
	return 0;
}