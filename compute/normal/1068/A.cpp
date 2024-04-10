#include<bits/stdc++.h>
using namespace std;
//mx<=n
//x<=n/m
//mx-k>=l
//x>=(l+k)/m
int main()
{
	long long n,m,k,l;
	cin>>n>>m>>k>>l;
	long long ans=ceil((double)(l+k)/m);
	if(ans>n/m)
		cout<<-1<<endl;
	else cout<<ans<<endl;


}