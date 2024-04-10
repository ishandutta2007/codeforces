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
int n;
long long a[110000],b[110000],s[110000];

pair<long long,long long> q[110000];

long long ans[110000];
int main()
{
    cin>>n;
    rep(i,n)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    rep(i,n-1)b[i]=a[i+1]-a[i]; b[n]=9e18;
    sort(b+1,b+n+1);
    rep(i,n)s[i]=s[i-1]+b[i]; 

    int Q;
    cin>>Q;
    rep(i,Q){ long long l,r; scanf("%lld%lld",&l,&r); q[i]=mp(r-l+1,i); }
    sort(q+1,q+Q+1);
    int now=0;
    rep(i,Q)
    {
        while (now<n && b[now+1]<=q[i].first)now++;
        ans[q[i].second]=s[now]+1ll*(n-now)*q[i].first;
    }
    rep(i,Q)printf("%lld%c",ans[i],i==Q?'\n':' ');
}