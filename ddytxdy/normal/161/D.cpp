#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e4+50;
int n,k,ver[N*2],nxt[N*2],head[N],tot,rt,sum,dat,sz[N],st[N],tp,num[600],st1[N],tp1;bool vis[N],flag[N];LL ans;
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+(c^48),c=getchar();
    return x;
}
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void findr(int x,int ff){
    sz[x]=1;int mx=0;
    for(int i=head[x],y;i;i=nxt[i])
        if(!vis[y=ver[i]]&&y!=ff)
        findr(y,x),sz[x]+=sz[y],mx=max(mx,sz[y]);
    mx=max(mx,sum-sz[x]);
    if(mx<dat)dat=mx,rt=x;
}
void dfs(int x,int ff,int d){
    if(d>k)return;
    ans+=num[k-d];st[++tp]=d;
    for(int i=head[x],y;i;i=nxt[i])if(!vis[y=ver[i]]&&y!=ff)
        dfs(y,x,d+1);
}
void solve(int x){
    vis[x]=1;
    for(int i=head[x],y;i;i=nxt[i])
        if(!vis[y=ver[i]]){
            dfs(y,x,1);
            while(tp){
                int x=st[tp--];num[x]++;
                if(!flag[x])flag[x]=1,st1[++tp1]=x;
            }
        }
    ans+=num[k];
    while(tp1)flag[st1[tp1]]=0,num[st1[tp1]]=0,tp1--;
    for(int i=head[x],y;i;i=nxt[i])
        if(!vis[y=ver[i]]){
            sum=sz[y];dat=1e9;
            findr(y,0);solve(rt);
        }
}
int main(){
    n=read();k=read();
    for(int i=1,x,y;i<n;i++)add(x=read(),y=read()),add(y,x);
    sum=n;dat=1e9;findr(1,0);solve(rt);
    cout<<ans;
    return 0;
}