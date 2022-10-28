#include<bits/stdc++.h>
using namespace std;
#define ll long long
int tobinary(int b[],int n,int k)
{
    while(k!=0)
    {
        b[--n]=k%2;
        k/=2;
    }
    while(--n>=0)b[n]=0;
    return 0;
}
int main()
{
    ll int n,m,k,l,count=0,i,j;
    cin>>n>>m>>k;
    ll int a[m+1];
    int  a1[n],a2[n];
    for(i=0;i<m+1;i++)
    {
        cin>>a[i];
    }
    tobinary(a1,n,a[m]);
    for(i=0;i<m;i++)
    {
        tobinary(a2,n,a[i]);
        l=0;
        for(j=0;j<n;j++)
        {
        if(a1[j]^a2[j])l++;
        }
        if(l<=k)count++;
    }
    cout<<count;
    return 0;
}