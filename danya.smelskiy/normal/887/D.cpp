#include <bits/stdc++.h>
using namespace std;



int sz;
pair<int,int> a[300005];
long long est=0;
pair<long long,long long> s[300005];
int n;
long long qq=0;
long long aa,b,c,d;
int len;
long long ss[300005];

long long t[1500000];
inline int getr(int x){
    int l=0;
    int r=n;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (a[mid].first<=x) l=mid;
        else r=mid;
    }
    if (a[r].first<=x) l=r;
    return l;
}
long long getmin(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return min(getmin(l,mid,ll,rr,x+x),getmin(mid+1,r,ll,rr,x+x+1));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>aa>>b>>c>>d>>s[0].first>>len;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        ss[i]=ss[i-1];
        if (a[i].second==1) {
            s[i]=s[i-1];
            s[i].first+=aa;
            ss[i]+=c;
        } else {
            s[i]=s[i-1];
            s[i].first-=b;
            s[i].second=min(s[i].second,s[i].first);
            ss[i]-=d;
        }
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i)
        t[sz+i-1]=ss[i];
    for (int i=sz-1;i>0;--i)
        t[i]=min(t[i+i],t[i+i+1]);
    a[0].first=-1;
    long long ans=1e18;
    if (s[n].second>=0) ans=(long long)(a[n].first+1);
    for (int i=n;i>0;--i) {
        if (a[i].first>a[i-1].first+len) {
            ans=min(ans,(long long)(a[i-1].first+1));
            continue;
        }
        if (s[i-1].second<0ll) continue;
        int ll=a[i-1].first+len;
        ll=getr(ll);
        long long mn=getmin(1,sz,i,ll,1)-ss[i-1];
        if (s[i-1].first+mn<0) continue;
        ans=min(ans,(long long)(a[i-1].first+1));
    }
    cout<<(ans==1e18 ? -1 : ans);
}