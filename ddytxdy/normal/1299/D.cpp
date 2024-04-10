#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int N=1e5+50,K=400,mod=1e9+7;
int n,m,f[N],s[N],d[N],dat[N],val[N],id[N],iid[N],cnt,to[K][K],dp[K],h[K],ans;
struct node{
    int a[5],flag;
    bool insert(int x){
        for(int i=4;~i;i--)
            if(x>>i&1){
                if(!a[i]){return a[i]=x,1;}
                else x^=a[i];
            }
        flag=1;return 0;
    }
    void init(int x){a[0]=x&1;a[1]=x>>1&3;a[2]=x>>3&7;a[3]=x>>6&15;a[4]=x>>10;}
    int hsh(){
        for(int i=0;i<5;i++)if(a[i]&&!(a[i]>>i&1))return 2;
        for(int i=0;i<5;i++)
            for(int j=i+1;j<5;j++)
                if(a[j]>>i&1)a[j]^=a[i];
        return a[0]|a[1]<<1|a[2]<<3|a[3]<<6|a[4]<<10;
    }
}tmp,t[N];
int Merge(int x,int y){
    node a,b;a.init(x);b.init(y);
    for(int i=0;i<5;i++)if(b.a[i]&&!a.insert(b.a[i]))return 2;
    return a.hsh();
}
vector<pii>v[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);if(x!=y)f[x]=y;}
void dfs(int x,int ff){
    int Z=find(x);
    for(int i=0,y,z;i<v[x].size();i++){
        if((y=v[x][i].first)==ff)continue;
        z=v[x][i].second;
        if(!d[y])d[y]=d[x]+1,dat[y]=dat[x]^z,dfs(y,x);
        else if(d[y]<d[x]){
            if(y==1)val[Z]=dat[x]^z;
            else t[Z].insert(dat[x]^dat[y]^z);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(val,-1,sizeof(val));
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(x!=1&&y!=1)merge(x,y);
        v[x].pb(mp(y,z)),v[y].pb(mp(x,z));
    }
    for(int i=0;i<(1<<15);i++){
        tmp.init(i);int dat=tmp.hsh();
        if(dat==2||id[dat])continue;
        id[dat]=++cnt;iid[cnt]=dat;
    }
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            to[i][j]=id[Merge(iid[i],iid[j])];
    d[1]=1;dfs(1,0);dp[1]=1;
    for(int i=2;i<=n;i++){
        if(find(i)!=i||t[i].flag)continue;
        memset(h,0,sizeof(h));
        int id=::id[t[i].hsh()];
        for(int j=1;j<=cnt;j++)h[to[j][id]]=(0ll+h[to[j][id]]+(dp[j]<<(!!~val[i])))%mod;
        if(~val[i]&&t[i].insert(val[i])){
            id=::id[t[i].hsh()];
            for(int j=1;j<=cnt;j++)(h[to[j][id]]+=dp[j])%=mod;
        }
        for(int j=1;j<=cnt;j++)(dp[j]+=h[j])%=mod;
    }
    for(int i=1;i<=cnt;i++)(ans+=dp[i])%=mod;
    cout<<ans;
    return 0;
}