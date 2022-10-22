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
int n,a[200005],l,r,ans;
set<int> q;
int work(int now)
{
    int tmp=0;
    for(int i=now+1;i<=n;++i)
    {
        tmp=max(tmp,a[i]%a[now]);
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        q.insert(a[i]);
    }
    n=0;
    for(set<int>::iterator i=q.begin();i!=q.end();++i)
    {
        a[++n]=*i;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=a[i]<<1;j-a[i]<=a[n];j+=a[i])
        {
            int *g=lower_bound(a+i+1,a+1+n,j)-1;
            ans=max(ans,*g%a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}