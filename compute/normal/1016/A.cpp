#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int a[200007];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long cur=0,pre=0;
    for(int i=0;i<n;i++)
    {
        pre=cur;
        cur+=a[i];
        if(i==0)
        printf("%lld",cur/m-pre/m);
        else printf(" %lld",cur/m-pre/m);
    }
    cout<<endl;
    return 0;
}