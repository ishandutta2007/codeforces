#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n;
ll t[1000005];
ll ans=0;
ll last[1000005];
int main()
{	
	cin>>n;
	for(int i=1;n>=i;i++)
		cin>>t[i];
	for(int i=1;n>=i;i++)
	{
		ans+=(ll)(n-i+1)*(i-last[t[i]])*2-1;
		last[t[i]]=i;
	}
	printf("%.10lf",(double)ans/n/n);
    return 0;	
}