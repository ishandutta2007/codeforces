#include<bits/stdc++.h>
using namespace std;
bool ans(int x,int n)
{
	int k=x;
	while(x>0) k+=x%10,x/=10;
	if(k==n) return 1;
	return 0;
}
int n,k=0,a[1002],sum=0;
int main()
{
	cin>>n;
	for(int i=n-90; i<=n; i++) if(ans(i,n))sum++,a[++k]=i;
	cout<<sum<<endl;
    for(int i=1; i<=k; i++) printf("%d\n",a[i]);
	return 0;
}