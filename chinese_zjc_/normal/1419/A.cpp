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
int T,n;
char a[1005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            a[i]-='0';
        }
        if(n&1)
        {
            bool ans=false;
            for(int i=1;i<=n;i+=2)
            {
                if(a[i]&1)
                {
                    ans=true;
                }
            }
            cout<<(ans?1:2)<<endl;
        }
        else
        {
            bool ans=false;
            for(int i=2;i<=n;i+=2)
            {
                if(!(a[i]&1))
                {
                    ans=true;
                }
            }
            cout<<(ans?2:1)<<endl;
        }
    }
    return 0;
}