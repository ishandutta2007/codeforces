#include <bits/stdc++.h>
using namespace std;

struct st{
    long long x,y,z;
};
st a[100005];
long long tree[600005];
vector<long long> v;
map<long long,long long> q;
long long sz,n;
long long ans,last;
inline bool cmp(st a,st b){
    return (a.y<b.y) || (a.y==b.y && a.x<b.x);
}
inline void update(long long x,long long y){
    x+=sz-1;
    tree[x]=max(tree[x],y);
    x/=2;
    while (x){
        tree[x]=max(tree[x+x],tree[x+x+1]);
        x/=2;
    }
}
long long get(long long l,long long r,long long ll,long long rr,long long v){
    if (l>r || l>rr || r<ll) return 0;
    if (l>=ll && r<=rr) return tree[v];
    long long mid=(l+r)/2;
    return max(get(l,mid,ll,rr,v+v),get(mid+1,r,ll,rr,v+v+1));
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].y>>a[i].z;
        v.push_back(a[i].x);
        v.push_back(a[i].y);
    }
    sort(v.begin(),v.end());
    q[v[0]]=1;
    last=1;
    for (int i=1;i<v.size();++i)
    if (v[i]!=v[i-1]){
        ++last;
        q[v[i]]=last;
    }
    for (int i=1;i<=n;++i)
        a[i].x=q[a[i].x],a[i].y=q[a[i].y];
    sort(a+1,a+n+1,cmp);
    sz=1;
    while (sz<2*1e5) sz*=2;
    for (int i=1;i<=n;++i){
        long long z=get(1,sz,a[i].x+1,a[i].y,1);
        update(a[i].y,a[i].z+z);
        ans=max(ans,a[i].z+z);
    }
    cout<<ans;
}