#include<iostream>
using namespace std;
int a[105],b[105],n,A,B,mx;
int main()
{
	int i,j;
	cin>>n>>A>>B;
	for(i=0;i<n;i++) cin>>a[i]>>b[i];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]+a[j]<=A&&b[i]<=B&&b[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
			if(a[i]+b[j]<=A&&b[i]<=B&&a[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
			if(b[i]+a[j]<=A&&a[i]<=B&&b[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
			if(b[i]+b[j]<=A&&a[i]<=B&&a[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
		}
	}
	swap(A,B);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]+a[j]<=A&&b[i]<=B&&b[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
			if(a[i]+b[j]<=A&&b[i]<=B&&a[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
			if(b[i]+a[j]<=A&&a[i]<=B&&b[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
			if(b[i]+b[j]<=A&&a[i]<=B&&a[j]<=B)
			    mx=max(a[i]*b[i]+a[j]*b[j],mx);
		}
	}
	cout<<mx;
	return 0;
}