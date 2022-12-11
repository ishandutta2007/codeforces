#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,k,t,a[N],mx,tot,out;
struct node{int l,r,d;bool friend operator <(node a,node b){return a.l<b.l;}}b[N],c[N];
bool check(int x){
    tot=0;for(int i=1;i<=k;i++)if(b[i].d>x)c[++tot]=b[i];
    sort(c+1,c+tot+1);int now=m+1;
    for(int i=1,j,r;i<=tot;i++){
        j=i;r=c[i].r;
        while(j<tot&&c[j+1].l<=r)r=max(r,c[++j].r);
        now+=(r-c[i].l+1)*2;
        i=j;
    }
    return now<=t;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
    for(int i=1;i<=k;i++)scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].d);
    int l=1,r=mx,ans=mx+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    for(int i=n;i;i--)if(a[i]>=ans)out++;
    printf("%d\n",out);
    return 0;
}