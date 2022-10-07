#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=998244353,E=502;
const long long inf=5000000000000000000ll;
int n,L,t,x[2],y[2],b[N],l,r,mn,mx,dpmn[N],dpmx[N],c[N],ans[N],a[N];
bool Findmn(int lim){
    int las=b[1];
    for(int i=2;i<=n;++i){
        if(las+b[i]<lim)
            return false;
        las=b[i]-max(0,lim-las);
    }
    if(las+b[n+1]<lim)
        return false;
    return true;
}
bool Findmx(int lim){
    int las=b[1];
    for(int i=2;i<=n;++i){
        if(las>lim)
            return false;
        las=max(0,b[i]-(lim-las));
    }
    if(las+b[n+1]>lim)
        return false;
    return true;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d %d",&L,&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    a[n+1]=L;
    for(int i=1;i<=n+1;++i)
        b[i]=a[i]-a[i-1];
    l=1,r=L+1;
    while(l<r){
        int mid=l+r>>1;
        if(Findmn(mid))
            l=mid+1;
        else
            r=mid;
    }
    mn=l-1;
    l=1,r=L;
    while(l<r){
        int mid=l+r>>1;
        if(Findmx(mid))
            r=mid;
        else
            l=mid+1;
    }
    mx=l;
    dpmn[1]=dpmx[1]=b[1];
    for(int i=2;i<=n;++i){
        dpmn[i]=max(0,b[i]-(mx-dpmn[i-1]));
        dpmx[i]=b[i]-max(0,mn-dpmx[i-1]);
        // cout<<b[i]<<' '<<dpmn[i]<<' '<<dpmx[i-1]<<endl;
    }
    c[n]=max(mn-b[n+1],dpmn[n]);
    for(int i=n;i>=3;--i)
        c[i-1]=max(mn-(b[i]-c[i]),dpmn[i-1]);
    for(int i=2;i<=n;++i){
        c[i]=b[i]-c[i];
        ans[i]=ans[i-1]+b[i-1]-c[i-1]+c[i];
    }
    ans[n+1]=L;
    for(int i=1;i<=n;++i)
        printf("%d %d\n",ans[i],ans[i+1]);
}