#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e6+50,M=1010;
vector<int>v[N],p,e;
struct node{int x,d,f;};
queue<node>q;
int n,m,d1[N],d2[N],f1[N],ans=1e9,mindiv[M],vis[N];
int main(){
    scanf("%d",&n);
    for(int i=2;i<M;i++){
        if(!mindiv[i])mindiv[i]=i,p.pb(i);
        for(int j=0,y;j<p.size()&&p[j]<=mindiv[i]&&(y=p[j]*i)<M;j++)
            mindiv[y]=p[j];
    }
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);e.clear();
        for(int j=0;j<p.size();j++){
            int num=0;while(x%p[j]==0)x/=p[j],num++;
            if(num&1)e.pb(j+1);
        }
        if(x!=1)e.pb(x);while(e.size()<2)e.pb(0);
        v[e[0]].pb(e[1]),v[e[1]].pb(e[0]);
    }
    for(int i=0;i<=p.size();i++){
        memset(d1,-1,sizeof(d1));
        memset(d2,-1,sizeof(d2));
        memset(vis,0,sizeof(vis));
        for(int j=0;j<v[i].size();j++)
            if(v[i][j]==i)ans=1;
            else if(vis[v[i][j]])ans=min(ans,2);
            else q.push(node{v[i][j],1,v[i][j]}),vis[v[i][j]]=1;
        while(q.size()){
            node p=q.front();q.pop();
            int x=p.x,d=p.d,f=p.f;
            if(d1[x]==-1)d1[x]=d,f1[x]=f;
            else if(d2[x]==-1&&f1[x]!=f)d2[x]=d;
            else continue;
            for(int j=0;j<v[x].size();j++)if(v[x][j]!=i)q.push(node{v[x][j],d+1,f});
        }
        for(int j=0;j<v[i].size();j++)
            if(~d2[v[i][j]])ans=min(ans,d2[v[i][j]]+1);
    }
    printf("%d\n",ans<=n?ans:-1);
    return 0;
}