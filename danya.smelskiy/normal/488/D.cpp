#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+7;

int n,s,l;
int tree1[400005];
int tree2[400005];
int tree3[400005];
int sz;
int g[100005];

int a[100005];
int get1(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return inf;
    if (l>=ll && r<=rr) return tree1[x];
    int mid=(l+r)>>1;
    return min(get1(l,mid,ll,rr,x+x),get1(mid+1,r,ll,rr,x+x+1));
}
int get2(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return -inf;
    if (l>=ll && r<=rr) return tree2[x];
    int mid=(l+r)>>1;
    return max(get2(l,mid,ll,rr,x+x),get2(mid+1,r,ll,rr,x+x+1));
}
inline void update(int x,int y){
    x+=sz-1;
    tree3[x]=y;
    x>>=1;
    while (x) {
        tree3[x]=min(tree3[x+x],tree3[x+x+1]);
        x>>=1;
    }
}
int get3(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return inf;
    if (l>=ll && r<=rr) return tree3[x];
    int mid=(l+r)>>1;
    return min(get3(l,mid,ll,rr,x+x),get3(mid+1,r,ll,rr,x+x+1));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s>>l;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=sz;i<=sz+sz;++i){
        tree1[i]=inf;
        tree2[i]=-inf;
    }
    for (int i=1;i<=n;++i) {
        tree1[sz+i-1]=a[i];
        tree2[sz+i-1]=a[i];
    }
    for (int i=sz-1;i>0;--i) {
        tree1[i]=min(tree1[i+i],tree1[i+i+1]);
        tree2[i]=max(tree2[i+i],tree2[i+i+1]);
    }
    int ll=1;
    for (int i=1;i<=n;++i) {
        g[i]=ll;
        while (get2(1,sz,g[i],i,1)-get1(1,sz,g[i],i,1)>s) ++g[i];
        ll=g[i];
    }
    for (int i=1;i<=sz+sz;++i)
        tree3[i]=inf;
        if (l>n) {
            cout<<"-1";
            return 0;
        }
    for (int i=1;i<=n;++i) {
        if (g[i]==1) update(i,1);
        else {
            if (g[i]>i-l+1) continue;
            int res=get3(1,sz,g[i]-1,i-l,1);
            update(i,res+1);
        }
    }
    if (tree3[sz+n-1]>=inf) cout<<"-1";
    else cout<<tree3[sz+n-1];
}