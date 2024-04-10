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
struct L
{
    int v,p;
    bool operator < (const L &TMP)const
    {
        return v==TMP.v?p<TMP.p:v<TMP.v;
    }
}a[100005];
int n,T;
bool flag;
signed main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i].v;
            a[i].p=i;
        }
        sort(a+1,a+1+n);
        flag=true;
        for(int i=1;i<=n;++i)
        {
            if(__gcd(a[i].v,a[1].v)!=a[1].v&&a[i].p!=i)
            {
                flag=false;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}