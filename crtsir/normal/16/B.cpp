#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,m;
	cin>>m>>n;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
				swap(a[i],a[j]);
			}
	int i=1;
	while(m-a[i]>=0&&i<=n){
		ans+=a[i]*b[i];
		m=m-a[i];
		i++;
	}
	if(i>n)
		cout<<ans;
	else
		cout<<m*b[i]+ans;
}