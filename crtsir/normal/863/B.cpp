#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,minv=10000;
	cin>>n;
	n*=2;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			{
				int ta=0,tb=0,y[1];
				y[0]=0;
				y[1]=0;
				for(int k=0;k<n;k++){
					if((k==i&&y[0]==0))
					{
						y[0]=1;
						continue;
					}
					if((k==j&&y[1]==0))
					{
						y[1]=1;	
						continue;
					}
					if(tb%2==0)
						ta-=a[k];
					else
						ta+=a[k];
					tb++;
				}
				minv=min(ta,minv);
			}
	cout<<minv;
}