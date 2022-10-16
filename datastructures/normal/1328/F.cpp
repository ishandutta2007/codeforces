#include <iostream>
#include <cstdio>
#include <algorithm>
#define inf 1000000000000000000
#define int long long
using namespace std;
int n,k,a[200005],pre[200005],nxt[200005],sum[200005],ans=inf;
signed main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++)
        if (a[i]==a[i-1])pre[i]=pre[i-1];
        else pre[i]=i-1;
    for (int i=n;i>=1;i--)
        if (a[i]==a[i+1])nxt[i]=nxt[i+1];
        else nxt[i]=i+1;
    for (int i=1;i<=n;i++){
        int presum=(a[i]-1)*pre[i]-sum[pre[i]];
        int nxtsum=(sum[n]-sum[nxt[i]-1])-(n-nxt[i]+1)*(a[i]+1);
        ans=min(ans,presum+nxtsum+max(0ll,k-(nxt[i]-pre[i]-1)));
        if (nxt[i]-1>=k)ans=min(ans,presum+max(0ll,k-(nxt[i]-pre[i]-1)));
        if (n-pre[i]>=k)ans=min(ans,nxtsum+max(0ll,k-(nxt[i]-pre[i]-1)));
        if (nxt[i]-pre[i]-1>=k)ans=0;
    }
    cout<<ans<<endl;
    return 0;
}