#include<bits/stdc++.h>
using namespace std;
int T,n,f[500010],Maxn[2000010];
long long a[500010];
int maxn[2000010],maxn2[2000010];
void Modify(int k,int l,int r,int x,int v1,int v2){
    if(l==r){maxn[k]=max(maxn[k],v1);maxn2[k]=max(maxn2[k],v2);return;}
    int mid=(l+r)>>1;
    if(x<=mid) Modify(k<<1,l,mid,x,v1,v2);
    else Modify(k<<1|1,mid+1,r,x,v1,v2);
    maxn[k]=max(maxn[k<<1],maxn[k<<1|1]);
    maxn2[k]=max(maxn2[k<<1],maxn2[k<<1|1]);
}
int Query(int k,int l,int r,int x,int y){
    if(x>y) return -1e9;
    if(x<=l&&r<=y) return maxn[k];
    int mid=(l+r)>>1,maxn=-1e9;
    if(x<=mid) maxn=max(maxn,Query(k<<1,l,mid,x,y));
    if(mid<y) maxn=max(maxn,Query(k<<1|1,mid+1,r,x,y));
    return maxn;
}
int Query2(int k,int l,int r,int x,int y){
    if(x>y) return -1e9;
    if(x<=l&&r<=y) return maxn2[k];
    int mid=(l+r)>>1,maxn=-1e9;
    if(x<=mid) maxn=max(maxn,Query2(k<<1,l,mid,x,y));
    if(mid<y) maxn=max(maxn,Query2(k<<1|1,mid+1,r,x,y));
    return maxn;
}
void solve(){
    scanf("%d",&n);
    vector<long long> vec;
    a[0]=0;vec.push_back(0);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        vec.push_back(a[i]);
    }sort(vec.begin(),vec.end());
    for(int i=0;i<=n;i++){
        a[i]=lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
        Maxn[i]=-1e9;
    }
    for(int i=1;i<=4*n+4;i++) maxn[i]=-1e9,maxn2[i]=-1e9;
    Modify(1,0,n,a[0],0,0);Maxn[a[0]]=0;
    for(int i=1;i<=n;i++){
        f[i]=max(max(Query2(1,0,n,0,a[i]-1)+i,Maxn[a[i]]),Query(1,0,n,a[i]+1,n)-i);
        // printf("%d %d %d %d\n",a[i],Query2(1,0,n,0,a[i]-1)+i,Maxn[a[i]],Query(1,0,n,a[i]+1,n)-i);
        Modify(1,0,n,a[i],f[i]+i,f[i]-i);Maxn[a[i]]=max(Maxn[a[i]],f[i]);
    }
    printf("%d\n",f[n]);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}