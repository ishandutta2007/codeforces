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
int n,p[10005],cnt,kills[10005],lft,a[10005],b[10005],zyz[10005],tim[10005],g,tmp,per=100;
bool killed[100005],flag=true;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    lft=n;
    for(int i=2;i<=n;++i)
    {
        if(!killed[i])
        {
            p[++cnt]=i;
            for(int j=i;j<=n;j+=i)
            {
                if(!killed[j])
                {
                    ++kills[cnt];
                    killed[j]=true;
                }
            }
        }
    }
    for(int i=1;i<=cnt;++i)
    {
        cout<<"B "<<p[i]<<endl;
        cin>>a[i];
        lft-=a[i];
        if(!flag&&a[i]!=kills[i])
        {
            zyz[++g]=p[i];
            tim[g]=1;
        }
        if(flag&&(i%per==0||i==cnt))
        {
            cout<<"A "<<1<<endl;
            cin>>tmp;
            if(tmp!=lft)
            {
                for(int j=(i-1)/per*per+1;j<=i;++j)
                {
                    cout<<"A "<<p[j]<<endl;
                    cin>>tmp;
                    if(tmp)
                    {
                        zyz[++g]=p[j];
                        tim[g]=1;
                        flag=false;
                    }
                }
            }
        }
    }
    int ans=1;
    for(int i=1;i<=g;++i)
    {
        ans*=zyz[i];
        int now=zyz[i];
        if(now*zyz[i]>n)
        {
            continue;
        }
        cout<<"A "<<now*zyz[i]<<endl;
        cin>>tmp;
        while(tmp)
        {
            ans*=zyz[i];
            ++tim[i];
            now*=zyz[i];
            if(now*zyz[i]>n)
            {
                break;
            }
            cout<<"A "<<now*zyz[i]<<endl;
            cin>>tmp;
        }
    }
    cout<<"C "<<ans<<endl;
    return 0;
}