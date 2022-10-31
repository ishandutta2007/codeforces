#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int a[N],st[N],ans[N];
long long l[N],r[N],sum[N];
int main(){
    int n; cin>>n;
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1,tp=0;i<=n;++i){
        l[i]=l[i-1];
        while (tp&&a[st[tp]]>a[i]) l[i]-=sum[tp--];
        long long t=1LL*(i-st[tp])*a[i];
        l[i]+=t,sum[++tp]=t,st[tp]=i;
    }
    for (int i=n,tp=0;i;--i){
        r[i]=r[i+1];
        while (tp&&a[st[tp]]>a[i]) r[i]-=sum[tp--];
        long long t=1LL*((tp?st[tp]:n+1)-i)*a[i];
        r[i]+=t,sum[++tp]=t,st[tp]=i;
    }
    long long mx=0,mxp;
    for (int i=1;i<=n;++i)
        if (l[i]+r[i]-a[i]>mx) mx=l[i]+r[i]-a[i],mxp=i;
    ans[mxp]=a[mxp];
    for (int i=mxp-1;i;--i) ans[i]=min(ans[i+1],a[i]);
    for (int i=mxp+1;i<=n;++i) ans[i]=min(ans[i-1],a[i]);
    for (int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}