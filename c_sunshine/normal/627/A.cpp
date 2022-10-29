#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL s,t;
int main()
{
	cin>>s>>t;
	LL ans=1;
	int flag=1;
	for(int i=60;~i;i--)
		if((t>>i&1LL))
			s-=1LL<<i,ans*=2;
		else
			if(s>=2LL<<i)s-=2LL<<i,flag=0;
	if(s!=0)cout<<0<<endl;
	else cout<<ans-flag*2<<endl;
	return 0;
}