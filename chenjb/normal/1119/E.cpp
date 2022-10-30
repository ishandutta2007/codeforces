#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <set>
#include <utility>
#include <map>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define x1 gtmshb
#define y0 gtmjtjl
#define y1 gtmsf
using namespace std;
long long a[500000],n;
long long ans,now;
int main()
{
    cin>>n;
    rep(i,n)scanf("%lld",&a[i]);
    now=0;
    rep(i,n)
    {
        long long t;
        if (now<a[i]/2)t=now; else t=a[i]/2;
        ans+=t; now-=t; a[i]-=2ll*t;
        ans+=a[i]/3ll; a[i]=a[i]%3ll; 
        now+=a[i]; a[i]=0;
    }
    cout<<ans<<endl;
}