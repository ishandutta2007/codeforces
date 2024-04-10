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
int n,t,a[500005];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]!=a[1])
        {
            cout<<1<<endl;
            while(i<n)
            {
                cin>>a[++i];
            }
            return;
        }
    }
    cout<<n<<endl;
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