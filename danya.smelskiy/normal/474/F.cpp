#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[100005];
int t2[500005];
pair<int,int> t1[500005];
int sz;

int get_gcd(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return t2[x];
    int mid=(l+r)>>1;
    return __gcd(get_gcd(l,mid,ll,rr,x+x),get_gcd(mid+1,r,ll,rr,x+x+1));
}

pair<int,int> get_min(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return {1e9,1e9};
    if (l>=ll && r<=rr) return t1[x];
    int mid=(l+r)>>1;
    pair<int,int> res1=get_min(l,mid,ll,rr,x+x);
    pair<int,int> res2=get_min(mid+1,r,ll,rr,x+x+1);
    if (res1.first!=res2.first) return min(res1,res2);
    res1.second+=res2.second;
    return res1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        t1[sz+i-1]=make_pair(a[i],1);
        t2[sz+i-1]=a[i];
    }
    for (int i=sz-1;i>0;--i) {
        t2[i]=__gcd(t2[i+i],t2[i+i+1]);
        if (t1[i+i].first!=t1[i+i+1].first) t1[i]=min(t1[i+i],t1[i+i+1]);
        else {
            t1[i]=t1[i+i];
            t1[i].second+=t1[i+i+1].second;
        }
    }
    cin>>m;
    while (m--) {
        int x,y;
        cin>>x>>y;
        int gc=get_gcd(1,sz,x,y,1);
        pair<int,int> mn=get_min(1,sz,x,y,1);
        if (mn.first==gc) cout<<y-x+1-mn.second<<'\n';
        else cout<<y-x+1<<'\n';
    }
}