#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5050,K=20,M=1e5+50;
int k,n[K],a[K][N],flag[K],fr[M];LL s[N],sum,goal;bool f[M],can[M];
pair<int,int>dat[M],ans[K];
map<LL,pair<int,int> >mp;
void dfs(int x,int y,int now,int fx,int fy){
    if(flag[x]&&x==fx&&y==fy){can[now]=1,dat[now]=make_pair(x,y);return;}
    if(flag[x])return;flag[x]=1;
    LL dat=goal-(s[x]-a[x][y]);
    if(mp.find(dat)!=mp.end())dfs(mp[dat].first,mp[dat].second,now|(1<<x-1),fx,fy);
}
void solve(int x,int y){
    if(flag[x])return;
    ans[x].first=a[x][y];flag[x]=1;
    LL dat=goal-(s[x]-a[x][y]);
    ans[mp[dat].first].second=x;solve(mp[dat].first,mp[dat].second);
}
int main(){
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&n[i]);
        for(int j=1;j<=n[i];j++)scanf("%d",&a[i][j]),mp[a[i][j]]=make_pair(i,j),s[i]+=a[i][j];
        sum+=s[i];
    }
    if(sum%k)puts("No"),exit(0);
    goal=sum/k;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n[i];j++){
            memset(flag,0,sizeof(flag));
            dfs(i,j,0,i,j);
        }
    }
    f[0]=1;int mx=1<<k;
    for(int i=1;i<mx;i++)
        for(int j=i;j;j=(j-1)&i)
            if(can[j]&f[i^j])f[i]=1,fr[i]=j;
    if(!f[mx-1])puts("No"),exit(0);
    int x=mx-1;
    while(x){
        memset(flag,0,sizeof(flag));
        solve(dat[fr[x]].first,dat[fr[x]].second);x^=fr[x];
    }
    puts("Yes");
    for(int i=1;i<=k;i++)printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}