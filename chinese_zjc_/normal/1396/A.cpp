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
int n,a[100005];
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<1<<' '<<1<<endl;
        cout<<0<<endl;
        cout<<1<<' '<<1<<endl;
        cout<<0<<endl;
        cout<<1<<' '<<1<<endl;
        cout<<-a[1]<<endl;
        return 0;
    }
    cout<<1<<' '<<n-1<<endl;
    for(int i=1;i<n;++i)
    {
        cout<<a[i]*(n-1)<<' ';
        a[i]+=a[i]*(n-1);
    }
    cout<<endl;
    cout<<n<<' '<<n<<endl;
    cout<<n-a[n]<<endl;
    a[n]=n;
    cout<<1<<' '<<n<<endl;
    for(int i=1;i<=n;++i)
    {
        cout<<-a[i]<<' ';
        a[i]+=-a[i];
    }
    return 0;
}