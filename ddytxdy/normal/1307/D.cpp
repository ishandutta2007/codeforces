#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50,inf=1e9;
int n,m,k,ver[N*2],nxt[N*2],head[N],tot,q[N],l,r,d1[N],dn[N],ans;
int v1[N],v2[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
struct node{int x,d1,dn;}a[N];
bool cmp(node a,node b){return a.d1+b.dn<a.dn+b.d1;}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)scanf("%d",&a[i].x);
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    q[l=r=1]=1;memset(d1,0x3f,sizeof(d1));d1[1]=0;
    while(l<=r){
        int x=q[l++];
        for(int i=head[x],y;i;i=nxt[i])
            if(d1[y=ver[i]]>d1[x]+1)d1[y]=d1[x]+1,q[++r]=y;
    }
    q[l=r=1]=n;memset(dn,0x3f,sizeof(dn));dn[n]=0;
    while(l<=r){
        int x=q[l++];
        for(int i=head[x],y;i;i=nxt[i])
            if(dn[y=ver[i]]>dn[x]+1)dn[y]=dn[x]+1,q[++r]=y;
    }
    for(int i=1;i<=k;i++)a[i].d1=d1[a[i].x],a[i].dn=dn[a[i].x];
    sort(a+1,a+k+1,cmp);
    for(int i=2,mx=a[1].d1;i<=k;i++){
        ans=max(ans,a[i].dn+mx);
        mx=max(mx,a[i].d1);
    }
    reverse(a+1,a+k+1);
    for(int i=2,mx=a[1].dn;i<=k;i++){
        ans=max(ans,a[i].d1+mx);
        mx=max(mx,a[i].dn);
    }
    cout<<min(ans+1,d1[n]);
    return 0;
}