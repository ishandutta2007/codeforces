#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=4e5+5;
namespace qio{
    const int sz=1e7;
    char i[sz],o[sz];
    char *li=i,*ri=i,*po=o;
    inline char get(){
        if(li==ri){
            fread(i,1,sz,stdin);
            li=i;ri=i+sz;
        }
        return *(li++);
    }
    inline int read(){
        int x=0;char ch=get();
        while(ch<'0'||ch>'9') ch=get();
        while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=get();}
        return x;
    }
    inline void put(char ch){
        if(po==o+sz){
            fwrite(o,1,sz,stdout);
            po=o;
        }
        *(po++)=ch;
    }
    char stk[20];
    int top;
    inline void print(int x){
        top=0;
        if(x==0) stk[top++]='0';
        while(x){
            stk[top++]=x%10+'0';
            x/=10;
        }
        for(int i=top-1;i>=0;i--)
            put(stk[i]);
    }
    inline void endio(){fwrite(o,1,po-o,stdout);}
}
int n,m;
int dis[N],pre[N];
vector<int> g[N];
int w[N];
void dfs(int u,int la){
    w[u]=1;
    for(auto v:g[u])if(v!=la){
        dfs(v,u);
        w[u]=max(w[u],w[v]+1);
    }
}
int main(){
    int i,j;
    int _=qio::read();
    while(_--){
        n=qio::read();m=qio::read();
        for(i=1;i<=n;i++){
            pre[i]=0;
            dis[i]=-1;
            g[i].clear();
        }
        for(i=1;i<n;i++){
            int u=qio::read(),v=qio::read();
            g[u].pb(v);
            g[v].pb(u);
        }
        queue<int> q;
        q.push(1);dis[1]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto v:g[u]){
                if(dis[v]==-1){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        int s=1;
        for(i=2;i<=n;i++)
            if(dis[i]>dis[s]) s=i;
        for(i=1;i<=n;i++) dis[i]=-1;
        q.push(s);dis[s]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto v:g[u]){
                if(dis[v]==-1){
                    dis[v]=dis[u]+1;
                    pre[v]=u;
                    q.push(v);
                }
            }
        }
        int t=1;
        for(i=2;i<=n;i++)
            if(dis[i]>dis[t]) t=i;
        if(m*2>dis[t]){
            qio::put('0');
            qio::put('\n');
            continue;
        }
        int rt=t,x=dis[t]/2;
        while(x--) rt=pre[rt];
        dfs(rt,0);
        int ans=0;
        for(i=1;i<=n;i++) ans+=(w[i]>m);
        qio::print(ans);
        qio::put('\n');
    }
    qio::endio();
    return 0;
}