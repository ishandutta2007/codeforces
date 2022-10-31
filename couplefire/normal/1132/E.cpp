#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll w,a[10],ans;
void dfs(int x,ll res)
{
    if(!x)
    {
        ans=max(ans,res);
        return;
    }
    for(ll i=4,num=min(a[x],(w-res)/x);i;i--,num--)
    dfs(x-1,res+max(0ll,num*x));
}
int main()
{
    cin>>w;
    for(int i=1;i<=8;i++)cin>>a[i];
    dfs(8,0);
    cout<<ans;
}