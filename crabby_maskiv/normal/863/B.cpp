#include<iostream>
#include<algorithm>
using namespace std;
int n,a[105],mn=9999999;
int main()
{
	cin>>n;
	n*=2;
	int i,j,k;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			int sum=0;
			for(k=0;k<n;k++)
			{
				if(k==i||k==j) continue;
				int k_=k+1;
				while(k_==i||k_==j) k_++;
				sum+=a[k_]-a[k];
				k=k_;
			}
			mn=min(mn,sum);
		}
	}
	cout<<mn;
	return 0;
}