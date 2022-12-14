#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main()
{
	cin>>a>>b>>c>>d>>e>>f;
	if(d<f) swap(d,f),swap(c,e);
	a+=b*(1+b)/2-(d-1)*d/2;
	if(a>c) a-=c;
	else a=0;
	a+=(d-1)*d/2-(f-1)*f/2;
	if(a>e) a-=e;
	else a=0;
	cout<<a+(f-1)*f/2<<endl;
	return 0;
}