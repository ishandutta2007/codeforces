#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long int t,r,g,b,k;
	cin>>t;
	while(t--)
	{
		cin>>r>>g>>b;
		k=max(r,max(g,b));
		if(k>r+g+b-k)
			cout<<r+g+b-k;
		else
			cout<<k+(r+g+b-k-k)/2;
		cout<<"\n";
	}
	return 0;
}