#include <bits/stdc++.h>
using namespace std;


int n,m,sz;
long long a[300005];
long long t[2000005];
long long tt[2000005];
int cnt[1000005];

void update(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr || t[x]<=2) return;
    if (l==r) {
        t[x]=tt[x]=cnt[t[x]];
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x);
    update(mid+1,r,ll,rr,x+x+1);
    t[x]=max(t[x+x],t[x+x+1]);
    tt[x]=tt[x+x]+tt[x+x+1];
}

long long get(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return tt[x];
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=1e6;++i)
        for (int j=i;j<=1e6;j+=i)
            cnt[j]++;
    for (int i=1;i<=n;++i) {
        t[sz+i-1]=a[i];
        tt[sz+i-1]=a[i];
    }
    for (int i=sz-1;i>0;--i)
        t[i]=max(t[i+i],t[i+i+1]),tt[i]=tt[i+i]+tt[i+i+1];
    while (m--) {
        int tp,x,y;
        cin>>tp>>x>>y;
        if (tp==1) update(1,sz,x,y,1);
        else cout<<get(1,sz,x,y,1)<<'\n';
    }
}