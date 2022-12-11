#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n,a[N],p[N],nxt[N][20],st[N],tp,lc[N],rc[N],l[N],r[N],lo[N],ans;
int query(int l,int r){
    int ll=lo[r-l+1];
    return min(nxt[l][ll],nxt[r-(1<<ll)+1][ll]);
}
void solve(int x){
    if(lc[x])solve(lc[x]),l[x]=l[lc[x]];else l[x]=x;
    if(rc[x])solve(rc[x]),r[x]=r[rc[x]];else r[x]=x;
    if(x-l[x]<r[x]-x){
        int lm=max(l[x],x-a[x]+1),rm=min(x,r[x]-a[x]+1);
        for(int i=lm;i<=rm;i++)if(query(i,i+a[x]-1)>i+a[x]-1)ans++;
    }
    else{
        int lm=max(x,l[x]+a[x]-1),rm=min(r[x],x+a[x]-1);
        for(int i=lm;i<=rm;i++)if(query(i-a[x]+1,i)>i)ans++;
    }
}
int main(){
    scanf("%d",&n);lo[0]=-1;
    for(int i=1;i<=n;i++)lo[i]=lo[i>>1]+1;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)p[i]=n+1;
    for(int i=n;i;i--)nxt[i][0]=p[a[i]],p[a[i]]=i;
    for(int i=1;i<=18;i++)for(int j=1,k=(1<<i-1)+1,l=1<<i;l<=n;j++,k++,l++)nxt[j][i]=min(nxt[j][i-1],nxt[k][i-1]);
    for(int i=1;i<=n;i++){
        int la=0;
        while(tp&&a[st[tp]]<a[i])la=st[tp--];
        lc[i]=la;rc[st[tp]]=i;st[++tp]=i;
    }
    solve(rc[0]);printf("%d\n",ans);
    return 0;
}