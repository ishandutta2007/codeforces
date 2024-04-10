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
int n,a[50][50],q,g;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=2;i<=n;i+=2)
    {
        for(int j=1;j<=n;++j)
        {
            a[i][j]=1ll<<i<<j;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    cin>>q;
    while(q--)
    {
        cin>>g;
        int x=1,y=1,now=1;
        cout<<x<<' '<<y<<endl;
        while(now<n<<1)
        {
            ++now;
            if(g&(1ll<<now))
            {
                if(a[x][y]==(1ll<<now>>1))
                {
                    ++y;
                    cout<<x<<' '<<y<<endl;
                }
                else
                {
                    if(!(x&1))
                    {
                        ++x;
                        cout<<x<<' '<<y<<endl;
                    }
                    while(a[x+1][y]!=1ll<<now)
                    {
                        ++y;
                        cout<<x<<' '<<y<<endl;
                    }
                    ++x;
                    cout<<x<<' '<<y<<endl;
                }
            }
        }
        if(x==n-1)
        {
            ++x;
            cout<<x<<' '<<y<<endl;
            while(y<n)
            {
                ++y;
                cout<<x<<' '<<y<<endl;
            }
        }
    }
    return 0;
}