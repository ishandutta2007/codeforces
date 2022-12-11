#include<bits/stdc++.h>
#define LL long long
#define calc(j,i) f[j]+s2[j+1][i]
#define G ++ip==ie?fread(ip=buf,L,1,stdin):0
using namespace std;
const int N=4040,L=1<<19;
int n,k,s1[N][N],s2[N][N],g[N];LL f[N],ans;
struct node{int l,r,p;}q[N];
char buf[L],*ie=buf+L,*ip=ie-1;
int read(){
    G;
    while(!isdigit(*ip))G;
    return *ip^48;
}
void check(int C){
    int l,r;q[l=r=1]=(node){1,n,0};
    for(int i=1;i<=n;i++){
        int j=q[l].p;
        f[i]=f[j]+s2[j+1][i]+C;g[i]=g[j]+1;
        if(q[l].r==i)l++;else q[l].l=i+1;
        if(i==n)break;
        while(l<=r){
            LL d1=calc(q[r].p,q[r].l),d2=calc(i,q[r].l);
            if(d1>d2||d1==d2&&g[q[r].p]>=g[i])r--;
            else break;
        }
        if(l>r)q[++r]=(node){i+1,n,i};
        else{
            int ll=q[r].l,rr=q[r].r,pos=-1;
            while(ll<=rr){
                int mid=(ll+rr)>>1;
                LL d1=calc(q[r].p,mid),d2=calc(i,mid);
                if(d1>d2||d1==d2&&g[q[r].p]>=g[i])pos=mid,rr=mid-1;
                else ll=mid+1;
            }
            if(pos>0)q[r].r=pos-1;
            int pp=q[r].r+1;
            if(pp<=n)q[++r]=(node){pp,n,i};
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s1[i][j]=s1[i][j-1]+read();
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)s2[i][j]=s2[i][j-1]+s1[j][j]-s1[j][i-1];
    int l=-1e9,r=1e9;
    while(l<=r){
        int mid=(l+r)>>1;
        check(mid);
        if(g[n]<=k)ans=f[n]-1ll*mid*k,r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}