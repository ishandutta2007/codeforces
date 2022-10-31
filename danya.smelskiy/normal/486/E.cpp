#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
int a[100005];
int sz;
pair<int,long long> tree[800005];
pair<int,long long> dp1[100005];
pair<int,long long> dp2[100005];



pair<int,long long > get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return make_pair(0,0);
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    pair<int,long long> res1 = make_pair(0,0);
    pair<int,long long> res2 = make_pair(0,0);
    res1=get(l,mid,ll,rr,x+x);
    res2=get(mid+1,r,ll,rr,x+x+1);
    if (res2.first>res1.first) swap(res1,res2);
    if (res2.first==res1.first) res1.second=(res1.second+res2.second)%md;
    return res1;
}
inline void update(int x,pair<int,long long> res) {
    x+=sz-1;
    if (tree[x].first==res.first) {
        tree[x].second=(tree[x].second+res.second)%md;
    } else if (tree[x].first<res.first) tree[x]=res; else return;
    x>>=1;
    while (x) {
        tree[x]=tree[x+x];
        if (tree[x+x+1].first>tree[x].first) tree[x]=tree[x+x+1];
        else if (tree[x+x+1].first==tree[x].first) tree[x].second=(tree[x].second+tree[x+x+1].second)%md;
        x>>=1;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        ++a[i];
    }
    sz=1;
    while (sz<2e5) sz+=sz;
    for (int i=1;i<=n;++i) {
        int x=a[i];
        pair<int,long long> res = get(1,sz,1,x-1,1);
        ++res.first;
        if (res.first==1) res.second=1;
        dp1[i]=res;
        update(x,res);
    }
    for (int i=sz+sz;i>0;--i) {
        tree[i]=make_pair(0,0);
    }
    int mx=0;
    long long kol=0;
    for (int i=n;i>0;--i) {
        int x=a[i];
        pair<int,long long> res=get(1,sz,x+1,2e5,1);
        ++res.first;
        if (res.first==1) res.second=1;
        dp2[i]=res;
        update(x,res);
        if (res.first>mx) {
            mx=res.first;
            kol=res.second;
        } else if (mx==res.first) kol=(kol+res.second)%md;
    }
    for (int i=1;i<=n;++i) {
        if (dp1[i].first+dp2[i].first-1<mx) cout<<"1";
        else if ((dp1[i].second*dp2[i].second)%md==kol) cout<<"3";
        else cout<<"2";
    }
}