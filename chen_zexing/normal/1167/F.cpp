#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
long long mod=1e9+7;
int n;
struct seg_tree{
    long long tree[2000005],lz[2000005];
    void pushdown(int node,int l,int r){
        if(lz[node]){
            int mid=(l+r)>>1;
            tree[node*2]+=1LL*(mid-l+1)*lz[node]%mod,tree[node*2+1]+=1LL*(r-mid)*lz[node]%mod;
            lz[node*2]+=lz[node],lz[node*2+1]+=lz[node],lz[node]=0;
        }
    }
    void update(int node,int l,int r,int L,int R,int v){
        if(L>R) return;
        if(l>=L&&r<=R){
            tree[node]+=1LL*(r-l+1)*v%mod,tree[node]%=mod;
            lz[node]+=v,lz[node]%=mod;
            return;
        }
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        if(mid>=L) update(node*2,l,mid,L,R,v);
        if(mid<R) update(node*2+1,mid+1,r,L,R,v);
        tree[node]=(tree[node*2]+tree[node*2+1])%mod;
    }
    long long query(int node,int l,int r,int L,int R){
        if(L>R) return 0;
        if(l>=L&&r<=R) return tree[node];
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        long long ans=0;
        if(mid>=L) ans=ans+query(node*2,l,mid,L,R),ans%=mod;
        if(mid<R) ans=ans+query(node*2+1,mid+1,r,L,R),ans%=mod;
        return ans;
    }
}pre,suf;
int a[500005],id[500005];
bool cmp(int x,int y){
    return a[x]<a[y];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i;
        sort(id+1,id+n+1,cmp);
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long temp=pre.query(1,1,n,id[i],id[i])*(n-id[i]+1)%mod+suf.query(1,1,n,id[i],id[i])*id[i]%mod;
            //cout<<temp<<endl;
            temp+=1LL*id[i]*(n-id[i]+1)%mod;
            //cout<<pre.query(1,1,n,id[i],id[i])<<" "<<suf.query(1,1,n,id[i],id[i])<<endl;
            //cout<<temp<<endl;
            ans+=temp%mod*a[id[i]]%mod,ans%=mod;
            pre.update(1,1,n,id[i]+1,n,id[i]),suf.update(1,1,n,1,id[i]-1,n-id[i]+1);
            //cout<<temp<<" "<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//