#include<bits/stdc++.h>
using namespace std;
int a[300003];
int main(){
	int n,m,x,ans1,ans2,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x,
		a[i]=a[i-1]+!x;
	for(int i=1,j=1;i<=n;j++){
		while(a[i]-a[j-1]<=m&&i<=n)
			i++;
		//cout<<j<<' '<<i<<endl;
		if(ans<i-j)
		{
			ans=i-j;
			ans1=i;
			ans2=j;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(ans2<=i&&i<ans1)
			cout<<1<<' ';
		else
			cout<<!(a[i]-a[i-1])<<' ';
}