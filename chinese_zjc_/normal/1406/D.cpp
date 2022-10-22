//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[100005],ans,q,l,r,x;
int getans()
{
    return max((a[1]+ans)/2,a[1]+ans-(a[1]+ans)/2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=n;i>1;--i)
    {
        a[i]=a[i]-a[i-1];
        ans+=max(0ll,a[i]);
    }
    cout<<getans()<<endl;
    cin>>q;
    for(int i=1;i<=q;++i)
    {
        cin>>l>>r>>x;
        if(l>1)
        {
            ans-=max(0ll,a[l]);
            a[l]+=x;
            ans+=max(0ll,a[l]);
        }
        else
        {
            a[1]+=x;
        }
        ++r;
        if(r<=n)
        {
            ans-=max(0ll,a[r]);
            a[r]-=x;
            ans+=max(0ll,a[r]);
        }
        cout<<getans()<<endl;
    }
    return 0;
}