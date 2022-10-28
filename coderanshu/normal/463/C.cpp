#include<bits/stdc++.h>
using namespace std ;

#define li long int
#define modulo 1000000007 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    int n,i,j,x1=0,x2=0,y1=0,y2=1;
    long long int sum,m1,m2;
    cin>>n;
    long long int a[n][n],b[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            b[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
            sum+=a[j][i-j];
        for(j=0;j<=i;j++)
            b[j][i-j]+=sum;
        sum=0;
        for(j=0;j<=i;j++)
            sum+=a[j][n-1-i+j];
        for(j=0;j<=i;j++)
            b[j][n-1-i+j]+=sum;
        sum=0;
        if(i<n-1)
        {
        for(j=0;j<=i;j++)
            sum+=a[n-1-j][i-j];
        for(j=0;j<=i;j++)
            b[n-1-j][i-j]+=sum;
        sum=0;
        for(j=0;j<=i;j++)
            sum+=a[n-1-j][n-1-i+j];
        for(j=0;j<=i;j++)
            b[n-1-j][n-1-i+j]+=sum;
    	}
    }
    m1=b[0][0]-a[0][0];m2=b[0][1]-a[0][1];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]-=a[i][j];
            if((i+j)%2==0 && b[i][j]>m1)
            {
            	m1=b[i][j];
            	x1=i;y1=j;
            }
            else if((i+j)%2!=0 && b[i][j]>m2)
            {
            	m2=b[i][j];
            	x2=i;y2=j;
            }
        }
    }
    cout<<m1+m2<<"\n"<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1;
	return 0;
}