#include<bits/stdc++.h>
using namespace std;
int ask(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<endl;
	int ret;
	cin>>ret;
	return ret;
}
int ans[1005];
int main()
{
	int n;
	cin>>n;
	int tot=ask(1,n);
	ans[n]=tot-ask(1,n-1);
	int cur=0;
	for(int i=1;i<n-1;i++)
	{
		int suf=ask(i+1,n);
		ans[i]=tot-suf-cur;
		cur+=ans[i];
	}
	ans[n-1]=tot-cur-ans[n];
	cout<<"! ";
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
}