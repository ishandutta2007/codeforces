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
int t,p,f,cnts,cntw,s,w,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>p>>f>>cnts>>cntw>>s>>w;
        ans=0;
        for(int i=0;i<=cnts;++i)
        {
            if(i*s<=p)
            {
                int j=min(cntw,(p-i*s)/w),k,l;
                if(s<w)
                {
                    k=min(cnts-i,f/s);
                    l=min(cntw-j,(f-k*s)/w);
                }
                else
                {
                    l=min(cntw-j,f/w);
                    k=min(cnts-i,(f-l*w)/s);
                }
                ans=max(ans,i+j+k+l);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}