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
int n,ans,T,a[105],ton[105];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=0;
        memset(ton,0,sizeof(ton));
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ++ton[a[i]];
        }
        for(int i=0;i<=101;++i)
        {
            if(ton[i]<1)
            {
                ans+=i;
                break;
            }
        }
        for(int i=0;i<=101;++i)
        {
            if(ton[i]<2)
            {
                ans+=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}