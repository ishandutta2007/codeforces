#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n,x,a[110],l,r;
int main()
{   cin>>n>>x;
 	int sum=0;
 	for(int i=1;i<=n;i++)
    {
		cin>>a[i];
    	sum+=a[i];
    }
    for(l=x-1,r=x+1; l>=1 && r<=n;l--,r++)
    if(a[l]!=a[r]) sum-=(a[l]+a[r]);

    cout<<sum;
    return 0;
}