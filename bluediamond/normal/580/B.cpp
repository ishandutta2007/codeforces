#include <bits/stdc++.h>
using namespace std;
const int nmax=100000;
int n,d;
struct data
{
    int money,factor;
};
bool operator<(data a,data b)
{
    return a.money<b.money;
}
data v[nmax+5];
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>v[i].money>>v[i].factor;
    sort(v+1,v+n+1);
    long long cur=0,start=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        cur+=v[i].factor;
        while(start<=i and v[i].money-v[start].money>=d)
        {
            cur-=v[start].factor;
            start++;
        }
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}
/**

**/