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
int n,a[1000005],b[1000005],c[1000005],T,l,r;
bool answered;
bool check(int now)
{
    for(int i=1;i<=n;++i)
    {
        c[i]=a[i];
    }
    c[1]-=now;
    for(int i=1;i<n;++i)
    {
        if(c[i]>b[i])
        {
            return true;
        }
        c[i+1]-=b[i]-c[i];
        c[i+1]=max(0ll,c[i+1]);
    }
    if(b[n]-now<c[n])
    {
        return false;
    }
    cout<<"YES"<<endl;
    answered=true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        answered=false;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
        }
        l=0,r=min(b[n],a[1]);
        while(l<r&&!answered)
        {
            int mid=(l+r)>>1;
            if(check(mid))
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(!answered)
        {
            check(l);
            if(!answered)
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}