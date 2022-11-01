#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m,ans=0;
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans+=(i+m)/5;
		ans-=(i/5);
	}
	cout<<ans<<endl;
	return 0; 
}