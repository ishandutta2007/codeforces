#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[53][53];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		int r=0,c=0;
		for(int i=0;i<n;i++)
		{
			bool ok=1;
			for(int j=0;j<m;j++)
				if(a[i][j])
					ok=0;
			r+=ok;
		}
		for(int i=0;i<m;i++)
		{
			bool ok=1;
			for(int j=0;j<n;j++)
				if(a[j][i])
					ok=0;
			c+=ok;
		}
		if(min(r,c)%2)
			cout<<"Ashish\n";
		else
			cout<<"Vivek\n";
	} 
}