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
int n,a[105],T,HL,lst,t;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    lst=0;
    while(true)
    {
        T=0;
        for(int i=1;i<=n;++i)
        {
            if(a[T]<a[i]&&i!=lst)
            {
                T=i;
            }
        }
        if(a[T])
        {
            --a[T];
            lst=T;
        }
        else
        {
            cout<<"HL"<<endl;
            return;
        }
        HL=0;
        for(int i=1;i<=n;++i)
        {
            if(a[HL]<a[i]&&i!=lst)
            {
                HL=i;
            }
        }
        if(a[HL])
        {
            --a[HL];
            lst=HL;
        }
        else
        {
            cout<<"T"<<endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}