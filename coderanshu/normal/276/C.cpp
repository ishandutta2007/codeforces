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
    long long int n,q,i,count,x,y;
    cin>>n>>q;
    long long int a[n],b[n][2],c[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i][0]=b[i][1]=0;
    }
    sort(a,a+n);
    for(i=0;i<q;i++)
    {
        cin>>x>>y;
        b[x-1][0]++;b[y-1][1]--;

    }
    count=0;
    for(i=0;i<n;i++)
    {
        if(b[i][0]>0)count+=b[i][0];
        c[i]=count;
        if(b[i][1]<0)count+=b[i][1];
    }
    sort(c,c+n);
    count=0;
    for(i=0;i<n;i++)
    {
        count+=a[i]*c[i];
    }
    cout<<count;
	return 0;
}