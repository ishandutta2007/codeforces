#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,k,a[N],ll,rr,c[N];LL f[N],g[N],dat;
void init(){memset(c,0,sizeof(c));c[a[1]]=ll=rr=1;dat=0;}
void solve(int l,int r,int L,int R){
    if(l>r)return;int mid=(l+r)>>1;
    while(ll>L+1)dat+=c[a[--ll]]++;
    while(rr<mid)dat+=c[a[++rr]]++;
    while(ll<L+1)dat-=--c[a[ll++]];
    while(rr>mid)dat-=--c[a[rr--]];
    int pos=L;g[mid]=dat+f[L];
    for(int i=L+1;i<=min(mid-1,R);i++){
        dat-=--c[a[ll++]];
        if(dat+f[i]<g[mid])g[mid]=dat+f[i],pos=i;
    }
    solve(l,mid-1,L,pos);
    solve(mid+1,r,pos,R);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(f,0x3f,sizeof(f));f[0]=0;
    for(int i=1;i<=k;i++){
        init();
        solve(i,n,i-1,n-1);
        memcpy(f,g,sizeof(g));
    }
    printf("%lld\n",f[n]);
    return 0;
}