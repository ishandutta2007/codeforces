#include<bits/stdc++.h>
using namespace std;
int g(int n)
{
	int res=1;
	for(int i=2; i<=sqrt(n); i++) if(n%i==0) 
	{
		res=n/i;
		break;
	}
	return res;
}
void f(int n)
{
	int k=1;
	while(true)
	{
		if(k>n) break;
		k*=2;
	}
	if(k-n!=1) cout<<k-1<<endl;
	else cout<<g(n)<<endl;
	return ;
}
int main()
{
	int n,k;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>k;
		f(k);
	}
	return 0;
}