#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,M=100;
int n,ver[N*2],nxt[N*2],head[N],tot=1,d[N],q[N],l,r,ans=1e9,cnt;LL a[N];bool vis[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
struct node{
    int x,y;
    bool friend operator <(node a,node b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
}b[N*2];
LL read(){
    LL x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=10*x+c-'0',c=getchar();
    return x;
}
void ask(int s,int t){
    memset(d,0x3f,sizeof(d));
    d[s]=0;q[1]=s;l=r=1;
    while(l<=r){
        int x=q[l++];
        for(int i=head[x];i;i=nxt[i]){
            int y=ver[i];
            if(d[y]>d[x]+1&&!vis[i]){
                d[y]=d[x]+1;
                q[++r]=y;
            }
        }
    }
    ans=min(ans,d[t]+1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=0;i<60;i++){
        int num=0,x=0;
        for(int j=1;j<=n;j++)if((a[j]>>i)&1){
            num++;
            if(!x)x=j;
            else b[++cnt]=(node){x,j};
        }
        if(num>2)puts("3"),exit(0);
    }
    sort(b+1,b+cnt+1);
    for(int i=1;i<=cnt;i++){
        while(i<cnt&&b[i].x==b[i+1].x&&b[i].y==b[i+1].y)i++;
        add(b[i].x,b[i].y);add(b[i].y,b[i].x);
    }
    for(int i=2;i<=tot;i+=2){
        int x=ver[i],y=ver[i^1];
        vis[i]=vis[i^1]=1;
        ask(x,y);
        vis[i]=vis[i^1]=0;
    }
    printf("%d\n",ans==1e9?-1:ans);
    return 0;
}