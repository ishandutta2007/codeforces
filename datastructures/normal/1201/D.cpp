#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
struct node{
    int x,y;
}a[200005];
int n,m,k,q,b[200005],tot,c[200005][2],f[200005][2],ans;
inline bool cmp(node a,node b){
    if (a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
inline int lowwer(int x){
    int l=1,r=q,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (b[mid]<=x)ans=mid,l=mid+1;
        else r=mid-1;
    }
    return ans;
}
inline int larger(int x){
    int l=1,r=q,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if (b[mid]>=x)ans=mid,r=mid-1;
        else l=mid+1;
    }
    return ans;
}
inline int dis(int l,int r){
    if (l>r)swap(l,r);
    int mn=2e9;
    if (lowwer(r)!=-1)mn=min(mn,r-b[lowwer(r)]+abs(l-b[lowwer(r)]));
    if (larger(l)!=-1)mn=min(mn,b[larger(l)]-l+abs(b[larger(l)]-r));
    return mn;
}
signed main(){
    cin>>n>>m>>k>>q;
    for (int i=1;i<=k;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
    for (int i=1;i<=q;i++)scanf("%lld",&b[i]);
    sort(a+1,a+1+k,cmp);
    sort(b+1,b+1+q);
    for (int i=1;i<=k;i++){
        int j=i;
        while(a[j].x==a[i].x&&j<=k)j++;
        j--;
        ++tot;
        c[tot][0]=a[i].y,c[tot][1]=a[j].y;
        i=j;
    }
    c[0][0]=c[0][1]=1;
    ans=a[k].x-1;
    if (a[1].x==1){
        f[1][0]=abs(1-c[1][1])+c[1][1]-c[1][0];
        f[1][1]=abs(1-c[1][0])+c[1][1]-c[1][0];
    }
    else{
        f[1][0]=dis(1,c[1][1])+c[1][1]-c[1][0];
        f[1][1]=dis(1,c[1][0])+c[1][1]-c[1][0];
    }
    for (int i=2;i<=tot;i++){
        f[i][0]=min(f[i-1][0]+dis(c[i-1][0],c[i][1]),f[i-1][1]+dis(c[i-1][1],c[i][1]))+c[i][1]-c[i][0];
        f[i][1]=min(f[i-1][1]+dis(c[i-1][1],c[i][0]),f[i-1][0]+dis(c[i-1][0],c[i][0]))+c[i][1]-c[i][0];
    }
    ans+=min(f[tot][0],f[tot][1]);
    cout<<ans<<endl;
    return 0;
}