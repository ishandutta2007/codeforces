#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,nxt[N],pre[N],q[N],l=1,r,ans,st[N],tp;bool vis[N];
vector<int>v[N];
void erase(int x){nxt[pre[x]]=nxt[x];pre[nxt[x]]=pre[x];}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
    for(int i=1;i<=n;i++)nxt[i]=i+1,pre[i]=i-1;nxt[0]=1;pre[n+1]=n;
    while(nxt[0]<=n){
        q[++r]=nxt[0];erase(nxt[0]);ans++;
        while(l<=r){
            int x=q[l++];
            for(int i=0;i<v[x].size();i++)vis[st[++tp]=v[x][i]]=1;
            for(int i=nxt[0];i<=n;i=nxt[i])if(!vis[i])q[++r]=i,erase(i);
            while(tp)vis[st[tp--]]=0;
        }
    }
    printf("%d\n",ans-1);
    return 0;
}