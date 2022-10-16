#include<iostream>
using namespace std;
int main()
{
	string a,b,c="";
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--)
		if(a[i]+b[i]-96==1)
			c=c+'1';
		else
			c=c+'0';
	for(int i=0;i<c.size()/2;i++)
		swap(c[i],c[c.size()-1-i]);
	cout<<c;
}