#include<bits/stdc++.h>
using namespace std;
int n,ans=2147483647,r1,r2,c1,c2,a[103];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],a[i]++;
	cin>>r1>>c1>>r2>>c2;
	ans=fabs(r1-r2);
	int t=c1;
	for(int i=min(r1,r2);i<max(r1,r2);i++)
		t=min(t,a[i]);
	ans+=fabs(t-c2);
	if(c1>c2) 
		for(int i=0;i<n;i++)
		{
			int tmp=fabs(r1-(i+1))+fabs(r2-(i+1))+fabs(a[i]-c2);
			bool smaller=false; 
			for(int j=min(i,r1);j<max(i,r1);j++)if(a[j]<a[i])smaller=true;
			for(int j=min(i,r2);j<max(i,r2);j++)if(a[j]<a[i])smaller=true;
			if(smaller)
				continue;
			ans=min(ans,tmp);
			//cout<<tmp<<endl;
		}
	cout<<ans;
}