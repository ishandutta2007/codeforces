#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int N=2e6+50,mod=1e9+7,inf=1e9;
int n,a[N],b[N],d[N],f[N],ver[N*2],nxt[N*2],head[N],tot=1;bool vis[N*2];pii edge[N*2];
vector<int>anss;
void add(int x,int y,pii z){
    ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;
}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);if(x^y)f[x]=y;}
bool check(int x){
    int mx=1<<x;
    for(int i=0;i<mx;i++)d[i]=0,f[i]=i;
    for(int i=1,x,y;i<=n;i++){
        x=a[i]&(mx-1),y=b[i]&(mx-1);
        d[x]++,d[y]++;merge(x,y);
    }
    int cnt=0;
    for(int i=0;i<mx;i++){
        if(d[i]&1)return 0;
        if(d[i]&&f[i]==i)cnt++;
    }
    if(cnt>1)return 0;
    return 1;
}
void dfs(int x){//cout<<x<<" ";
    for(int &i=head[x];i;i=nxt[i]){
        if(vis[i>>1])continue;
        vis[i>>1]=1;
        int id=i;dfs(ver[i]);
        anss.pb(edge[id].second);
        anss.pb(edge[id].first);
    }
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read(),b[i]=read();
    int l=0,r=20,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    int mx=1<<ans;
    for(int i=1;i<=n;i++){
        int x=a[i]&(mx-1),y=b[i]&(mx-1);
        add(x,y,mp(i*2-1,i*2));add(y,x,mp(i*2,i*2-1));
    }
    dfs(a[1]&(mx-1));
    printf("%d\n",ans);
    for(int i=anss.size()-1;~i;i--)printf("%d ",anss[i]);
    return 0;
}