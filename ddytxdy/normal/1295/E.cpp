#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,p[N],a[N];LL mn[N*4],laz[N*4],ans=1e18;
void change(int x,int l,int r,int ql,int qr,LL d){
    if(l>=ql&&r<=qr){mn[x]+=d;laz[x]+=d;return;}
    int mid=(l+r)>>1;
    if(laz[x]){
        change(x<<1,l,mid,0,n,laz[x]);
        change(x<<1|1,mid+1,r,0,n,laz[x]);
        laz[x]=0;
    }
    if(ql<=mid)change(x<<1,l,mid,ql,qr,d);
    if(qr>mid)change(x<<1|1,mid+1,r,ql,qr,d);
    mn[x]=min(mn[x<<1],mn[x<<1|1]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),change(1,0,n,p[i],n,a[i]);
    for(int i=1;i<n;i++){
        change(1,0,n,p[i],n,-a[i]);
        change(1,0,n,0,p[i]-1,a[i]);
        ans=min(ans,mn[1]);
    }
    cout<<ans;
    return 0;
}