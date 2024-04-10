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
int n,k,t,a[200005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        if(k&1)
        {
            for(int i=1;i<=n;++i)
            {
                a[i]=-a[i];
            }
            int Min=INF;
            for(int i=1;i<=n;++i)
            {
                Min=min(Min,a[i]);
            }
            for(int i=1;i<=n;++i)
            {
                a[i]-=Min;
            }
        }
        else
        {
            int Min=INF;
            for(int i=1;i<=n;++i)
            {
                Min=min(Min,a[i]);
            }
            for(int i=1;i<=n;++i)
            {
                a[i]-=Min;
            }
        }
        for(int i=1;i<=n;++i)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}