#include<bits/stdc++.h>
using namespace std;
long long n,m,a,needs[101234],has[101234],ans;
bool check(int nn)
{
    long long res=a;
    ans=0;
    for(int i=1;i<=nn;i++)
    {
        long long x=max(0ll,needs[i]-has[n-nn+i]);
        if(res<x)return false;
        res-=x;
        ans+=needs[i]-x;
    }
    ans=max(0ll,ans-res);
    return 1;
}
int main()
{
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++)cin>>has[i];
    for(int i=1;i<=m;i++)cin>>needs[i];
    sort(has+1,has+n+1);
    //reverse(has+1,has+n+1);
    sort(needs+1,needs+m+1);
    int r=min(n,m),l=0;
    while(l<=r)
    {
        int mid=(r+l)/2;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    check(l-1);
    cout<<l-1<<' '<<ans;
}