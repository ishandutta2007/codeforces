#include<bits/stdc++.h>
using namespace std ;

#define li long int
#define modulo 1000000007 
long int arr[100001]={};
bool is_prime(long int n)
{
    long int k=sqrt(n);
    for(long int i=2;i<=k;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
long int fn(long int n)
{
    long int i=n;
    if(arr[n]!=0)return arr[n];
    while(!is_prime(i))i++;
    arr[n]=i-n;
    return arr[n];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    arr[1]=1L;

    long int n,m,i,j,temp,count;
    cin>>n>>m;
    long int a[n][m];
    for ( i = 0; i < n; ++i)
    {
        for ( j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            temp=fn(a[i][j]);
            a[i][j]=temp;
        }
    }
    temp=10e8;
    for(i=0;i<n;i++)
    {
        count=0;
        for(j=0;j<m;j++)
        {
            count+=a[i][j];
        }
        temp=min(temp,count);
    }
    for(i=0;i<m;i++)
    {
        count=0;
        for(j=0;j<n;j++)
        {
            count+=a[j][i];
        }
        temp=min(temp,count);
    }
    cout<<temp;
	return 0;
}