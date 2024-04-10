#include <bits/stdc++.h>
using namespace std;

long long tree[500005];
long long tree2[500005];
int n;
int x,y,sz;
char c[100005];
long long a[100005];
long long ans;
long long b[100005];
void update1(int x,long long y){
    x+=sz-1;
    tree[x]=max(tree[x],y);
    x/=2;
    while (x) {
        tree[x]=max(tree[x+x],tree[x+x+1]);
        x/=2;
    }
}
void update2(int x,long long y){
    x+=sz-1;
    tree2[x]=max(tree2[x],y);
    x/=2;
    while (x) {
        tree2[x]=max(tree2[x+x],tree2[x+x+1]);
        x/=2;
    }
}
long long get1(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)/2;
    return max(get1(l,mid,ll,rr,x+x),get1(mid+1,r,ll,rr,x+x+1));
}
long long get2(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return tree2[x];
    int mid=(l+r)/2;
    return max(get2(l,mid,ll,rr,x+x),get2(mid+1,r,ll,rr,x+x+1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>x>>y;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i]>>c[i];
    sz=1;
    while (sz<1e5) sz+=sz;
    for (int i=1;i<=n;++i) {
        if (c[i]=='C' && b[i]<=x) {
            if (x-b[i]>0) {
                long long z=get1(1,sz,1,x-b[i],1);
                if (z)
                ans=max(ans,z+a[i]);
            }
            if (y) {
                long long z=get2(1,sz,1,y,1);
                if (z)
                ans=max(ans,z+a[i]);
            }
            update1(b[i],a[i]);
        } else if (c[i]=='D' && b[i]<=y) {
            if (y-b[i]>0) {
                long long z=get2(1,sz,1,y-b[i],1);
                if (z)
                ans=max(ans,z+a[i]);
            }
            if (x) {
                long long z=get1(1,sz,1,x,1);
                if (z)
                ans=max(ans,z+a[i]);
            }
            update2(b[i],a[i]);
        }
    }
    cout<<ans;
}