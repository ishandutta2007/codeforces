#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e6+50;
int T,n,m,a[N],d[N],q[N],l,r,f[N],dis[N],ans1,ans2,fl[N];char s[N];
vector<int>v[N];
int ID(int x,int y){return (x-1)*m+y;}
void solve(){
    scanf("%d%d",&n,&m);ans1=ans2=0;
    for(int i=1;i<=n*m;i++)v[i].clear(),dis[i]=-1,d[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)a[ID(i,j)]=s[j]=='0';
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            int id=ID(i,j),iid;
            if(s[j]=='U')iid=ID(i-1,j);
            if(s[j]=='R')iid=ID(i,j+1);
            if(s[j]=='L')iid=ID(i,j-1);
            if(s[j]=='D')iid=ID(i+1,j);
            v[iid].pb(id);d[iid]++;f[id]=iid;
        }
    }
    l=1;r=0;for(int i=1;i<=n*m;i++)if(!d[i])q[++r]=i;
    while(l<=r){
        int x=q[l++];
        if(!--d[f[x]])q[++r]=f[x];
    }
    for(int i=1;i<=n*m;i++){
        if(!d[i]||~dis[i])continue;
        q[l=r=1]=i;dis[i]=0;int len=0;
        while(l<=r){
            int x=q[l++];len+=d[x];
            for(int j=0,y;j<v[x].size();j++)
                if(dis[y=v[x][j]]==-1)dis[y]=dis[x]+1,q[++r]=y;
        }
        for(int j=0;j<len;j++)fl[j]=0;
        for(int j=1;j<=r;j++)fl[dis[q[j]]%len]|=a[q[j]];
        ans1+=len;for(int j=0;j<len;j++)ans2+=fl[j];
    }
    cout<<ans1<<" "<<ans2<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}