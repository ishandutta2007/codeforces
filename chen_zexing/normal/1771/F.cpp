#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef std::mt19937  Random_mt19937;
Random_mt19937  rnd(time(0));
map <int,int> mp,f;
int tree[20000005],ls[20000005],rs[20000005];
int rt[200005],a[200005],cnt=1;
int insert(int pre,int l,int r,int pos,int v){
    int node=++cnt;
    tree[node]=tree[pre],ls[node]=ls[pre],rs[node]=rs[pre];
    tree[node]^=v;
    if(l==r) return node;
    int mid=(l+r)>>1;
    if(pos<=mid) ls[node]=insert(ls[pre],l,mid,pos,v);
    else rs[node]=insert(rs[pre],mid+1,r,pos,v);
    return node;
}
int query(int node1,int node2,int l,int r){
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(tree[ls[node1]]==tree[ls[node2]]) return query(rs[node1],rs[node2],mid+1,r);
    else return query(ls[node1],ls[node2],l,mid);
}
int main(){
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        rt[0]=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!mp[a[i]]){
                int r=rnd();
                while(f[r]) r=rnd();
                f[r]=1;
                mp[a[i]]=r;
            }
            rt[i]=insert(rt[i-1],1,1e9,a[i],mp[a[i]]);
        }
        int q,ans=0;
        cin>>q;
        for(int i=1,l,r;i<=q;i++){
            scanf("%d%d",&l,&r);
            l^=ans,r^=ans;
            if(tree[rt[r]]==tree[rt[l-1]]) ans=0;
            else ans=query(rt[l-1],rt[r],1,1e9);
            printf("%d\n",ans);
        }
    }
    return 0;
}