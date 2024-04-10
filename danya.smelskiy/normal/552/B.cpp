#include <bits/stdc++.h>
using namespace std;
long long i,n,x,m,k,ans;
int main()
{
    cin>>n;
	x=n;
	while(x>0){
		x/=10;
		m++;
	}
	ans=n*m+m-1;
	k=1;
	for (i = 0; i < m-1; i++)
	{
		k*=10;
		ans-=k;
	}
	cout<<ans<<endl;
	return 0;
}