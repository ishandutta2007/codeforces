#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 1000000007
#define maxn 500000
using namespace std;
struct BIT{
    int tree[1000005];
    inline void mem(){
        memset(tree,0,sizeof(tree));
        return;
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void add(int pos,int val){
        while(pos<=maxn)tree[pos]+=val,tree[pos]%=mod,pos+=lowbit(pos);
        return;
    }
    inline int query(int pos){
        int ans=0;
        while(pos)ans+=tree[pos],ans%=mod,pos-=lowbit(pos);
        return ans;
    }
}bit;
int n,a[500005],ans;
int s[500005];
inline int lowwer(int x){
    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (s[mid]<=x)ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
inline void ins(int val,int pos){
    bit.add(val,pos);
    return;
}
inline int ask(int val){
    return bit.query(val);
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=a[i];
    sort(s+1,s+1+n);
    for (int i=1;i<=n;i++)a[i]=lowwer(a[i]);
    bit.mem();
    for (int i=1;i<=n;i++){
        ins(a[i],i);
        ans+=ask(a[i])*(n-i+1)%mod*s[a[i]]%mod,ans%=mod;
    }
    bit.mem();
    for (int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
    for (int i=1;i<=n;i++){
        ans+=ask(a[i])*(n-i+1)%mod*s[a[i]]%mod,ans%=mod;
        ins(a[i],i);
    }
    cout<<ans<<endl;
}