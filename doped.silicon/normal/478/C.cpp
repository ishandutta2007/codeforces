#include <iostream>
using namespace std;

int main() {
	long long int r,g,b,mn,mid,mx;
	cin>>r>>g>>b;
	mn=min(r,min(g,b));
	mx=max(r,max(b,g));
	mid=r+g+b-mn-mx;
	long long int a=mx-mn,a1=mid-mn;
	long long int table=0;
	if(a>=2*a1)
	{
		table+=a1;
		mid=mn;
		mx=mx-2*a1;
	    if(mx>4*mn)
	    {
	    	table+=2*mn;
	    }
	    else
	    table+=(mx+mn+mid)/3;
	}
	else
	{
		table+=(mx+mn+mid)/3;
	}
	cout<<table;
	return 0;
}