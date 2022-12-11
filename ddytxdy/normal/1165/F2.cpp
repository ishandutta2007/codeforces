#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+50;
int n,m,a[N],c[N];
struct node{
    int d,t;
    bool friend operator <(node a,node b){
        return a.t<b.t;
    }
}b[N];
bool check(int x){
    for(int i=1;i<=n;i++)c[i]=a[i];
    int now=2e5,num=0;
    for(int i=m;i;i--){
        if(b[i].t>x)continue;
        now=min(now,b[i].t);
        int y=min(c[b[i].d],now);
        c[b[i].d]-=y;
        now-=y;num+=y;
    }
    now=0;
    for(int i=1;i<=n;i++)now+=c[i];
    return now*2<=x-num;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d%d",&b[i].t,&b[i].d);
    sort(b+1,b+m+1);
    int l=1,r=4e5,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}