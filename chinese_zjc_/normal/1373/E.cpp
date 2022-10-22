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
int n,k,t,ans;
bool got;
int f(int now)
{
    int tmp=0;
    while(now)
    {
        tmp+=now%10;
        now/=10;
    }
    return tmp;
}
int work(int now)
{
    int tmp=0;
    for(int i=0;i<=k;++i)
    {
        tmp+=f(i+now);
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        got=false;
        for(int i=0;i<=100;++i)
        {
            if(work(i)==n)
            {
                cout<<i<<endl;
                got=true;
                break;
            }
        }
        if(got)
        {
            continue;
        }
        ans=80;
        for(int now=100;now<=INF;now*=10)
        {
            for(int i=1;i<=9;++i)
            {
                ans+=now;
                int l=work(ans),r=work(ans+19);
                for(int j=0;j<=19;++j)
                {
                    if(work(ans+j)==n)
                    {
                        cout<<ans+j<<endl;
                        got=true;
                        break;
                    }
                }
                if(got)
                {
                    break;
                }
            }
            if(got)
            {
                break;
            }
        }
        if(!got)
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}