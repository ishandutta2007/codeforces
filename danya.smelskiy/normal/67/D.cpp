#include <bits/stdc++.h>
using namespace std;

int n;
int x,ans;
int pos[1000005];
int a[1000005];
int sz;
int tree[5000005];
void update(int x,int y){
    tree[x]=max(tree[x],y);
    x>>=1;
    while (x) {
        tree[x]=max(tree[x+x],tree[x+x+1]);
        x>>=1;
    }
}
int get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    return max(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        pos[x]=i;
    }
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]=pos[a[i]];
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        int res=get(1,sz,a[i]+1,n,1);
        ans=max(ans,res+1);
        update(a[i]+sz-1,res+1);
    }
    cout<<ans;
}