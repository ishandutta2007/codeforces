#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
    int x,v;
}a[200005];
int n,ans,s[200005],tree[200005][2];
inline int lowbit(int x){
    return x&(-x);
}
inline void add(int pos,int t,int val){
    while(pos<=n)tree[pos][t]+=val,pos+=lowbit(pos);
    return;
}
inline int query(int pos,int t){
    int ans=0;
    while(pos)ans+=tree[pos][t],pos-=lowbit(pos);
    return ans;
}
bool cmp(node a,node b){
    return a.x<b.x;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)scanf("%lld",&a[i].x);
    for (int i=1;i<=n;i++)scanf("%lld",&a[i].v),s[i]=a[i].v;
    sort(s+1,s+1+n);
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++){
        int l=1,r=n,x=0;
        while(l<=r){
            int mid=(l+r)/2;
            if (s[mid]<=a[i].v)x=mid,l=mid+1;
            else r=mid-1;
        }
        a[i].v=x;
    }
    for (int i=1;i<=n;i++){
        ans+=query(a[i].v,0)*a[i].x-query(a[i].v,1);
        add(a[i].v,0,1),add(a[i].v,1,a[i].x);
    }
    cout<<ans<<endl;
    return 0;
}