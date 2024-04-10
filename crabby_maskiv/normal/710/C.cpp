#include<iostream>
using namespace std;
int a[50][50];
int n;
int main()
{ 
    cin>>n;
    a[1][n/2+1]=1;
    int x=1;
    int y=n/2+1;
    int cnt=2;
    while(cnt<=n*n)
    {
    	if(x==1&&y==n)
    	{
    		a[x+1][y]=cnt;
    		x++;
    		cnt++;
		}
		else if(x==1)
		{
			if(a[n][y+1]==0)
			{
				x=n;
				y++;
				a[x][y]=cnt;
				cnt++;
			}
			else
			{
				a[x+1][y]=cnt;
    			x++;
    			cnt++;
			}
		}
		else if(y==n)
		{
			if(a[x-1][1]==0)
			{
				x--;
				y=1;
				a[x][y]=cnt;
				cnt++;
			}
			else
			{
				a[x+1][y]=cnt;
    			x++;
    			cnt++;
			}
		}
		else
		{
			if(a[x-1][y+1]==0)
			{
				x--;
				y++;
				a[x][y]=cnt;
				cnt++;
			}
			else
			{
				a[x+1][y]=cnt;
    			x++;
    			cnt++;
			}
		}
	}
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}