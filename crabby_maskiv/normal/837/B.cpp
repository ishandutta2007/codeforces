#include<iostream>
using namespace std;
char a[105][105];
int n,m;
char c1,c2,c3;
int main()
{
	cin>>n>>m;
	int i,j;
	for(i=0;i<n;i++)
	    for(j=0;j<m;j++) cin>>a[i][j];
	bool ans1=false,ans2=false;
	if(n%3==0)
	{
		ans1=true;
		c1=a[0][0];c2=a[n/3][0];c3=a[n/3*2][0];
		if(c1==c2||c2==c3||c1==c3) ans1=false;
		else
		{
			for(i=0;i<n/3;i++)
			{
				for(j=0;j<m;j++)
				    if(a[i][j]!=c1) ans1=false;
			}
			for(i=n/3;i<n/3*2;i++)
			{
				for(j=0;j<m;j++)
				    if(a[i][j]!=c2) ans1=false;
			}
			for(i=n/3*2;i<n;i++)
			{
				for(j=0;j<m;j++)
				    if(a[i][j]!=c3) ans1=false;
			}
		}
	}
	if(m%3==0)
	{
		ans2=true;
		c1=a[0][0];c2=a[0][m/3];c3=a[0][m/3*2];
		if(c1==c2||c2==c3||c1==c3) ans2=false;
		else
		{
			for(i=0;i<m/3;i++)
			{
				for(j=0;j<n;j++)
				    if(a[j][i]!=c1) ans2=false;
			}
			for(i=m/3;i<m/3*2;i++)
			{
				for(j=0;j<n;j++)
				    if(a[j][i]!=c2) ans2=false;
			}
			for(i=m/3*2;i<m;i++)
			{
				for(j=0;j<n;j++)
				    if(a[j][i]!=c3) ans2=false;
			}
		}
	}
	if(ans1||ans2) cout<<"Yes";
	else cout<<"No";
	return 0;
}