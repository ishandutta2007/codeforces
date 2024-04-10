#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, inf=1e9;
    cin>>n;
    int pre[n+1], suf[n+1], ar[n];
    pre[0]=inf;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(ar[a]==0) pre[a+1]=0;
        else pre[a+1]=pre[a]+1;
    }
    suf[n]=inf;
    for(int a=n-1; a>=0; a--)
    {
        if(ar[a]==0) suf[a]=0;
        else suf[a]=suf[a+1]+1;
    }
    for(int a=0; a<n; a++) cout<<min(pre[a+1], suf[a])<<" ";
}