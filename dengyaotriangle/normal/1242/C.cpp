#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=16;
const int maxv=5005;

int n;
vector<int> a[maxn];
long long sm[maxn],dlt[maxn];
map<long long,pair<int,int> > mp;
pair<int,int> adj[maxn][maxv];
int idg[maxn][maxv];
bool del[maxn][maxv];
vector<pair<int,int> > rss[1<<maxn];
bool vis[maxn];
vector<pair<int,int> > cur;
int stu,stv;
bool dp[1<<maxn];
int prv[1<<maxn];
int ansv[maxn],ansp[maxn];
bool cvis[maxn][maxv];
bool dfs(int u,int v){
    cvis[u][v]=1;
    if(vis[u])return 0;
    vis[u]=1;
    cur.push_back(make_pair(u,v)); 
    if(adj[u][v].first==stu&&adj[u][v].second==stv)return 1;
    bool ans=dfs(adj[u][v].first,adj[u][v].second);
    vis[u]=0;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    long long tot=0;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        while(l--){
            int v;cin>>v;
            a[i].push_back(v);
            tot+=v;
            sm[i]+=v;
            mp[v]=make_pair(i,(int)a[i].size()-1);
        }
    }
    if(tot%n!=0){
        cout<<"No";
        return 0;
    }
    tot/=n;
    for(int i=1;i<=n;i++){
        dlt[i]=tot-sm[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            if(mp.find(a[i][j]+dlt[i])!=mp.end()){
                int nxi=mp[a[i][j]+dlt[i]].first;
                int nxa=mp[a[i][j]+dlt[i]].second;
                if(nxi!=i||dlt[i]==0){
                    adj[i][j]=make_pair(nxi,nxa);
                    idg[nxi][nxa]++;
                }
            }
        }
    }
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            if(idg[i][j]==0)q.push(make_pair(i,j));
        }
    }
    while(!q.empty()){
        int cu=q.front().first;
        int cv=q.front().second;
        q.pop();
        del[cu][cv]=1;
        idg[adj[cu][cv].first][adj[cu][cv].second]--;
        if(idg[adj[cu][cv].first][adj[cu][cv].second]==0)q.push(adj[cu][cv]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            if(!del[i][j]&&!cvis[i][j]){
                memset(vis,0,sizeof(vis));
                stu=i;stv=j;
                if(dfs(i,j)){
                    //cout<<'R'<<i<<','<<j<<endl;
                    //cout<<cur.size()<<endl;
                    int stat=0;
                    for(int k=0;k<cur.size();k++){
                        stat|=(1<<(cur[k].first-1));
                    }
                    //cout<<stat<<endl;
                    rss[stat]=cur;
                }
                cur.clear();
            }
        }
    }
    dp[0]=1;
    for(int i=1;i<(1<<n);i++){
        for(int j=i;j;j=(j-1)&i){
            int v=i^j;
            if(rss[j].size()!=0u&&dp[v]){
                dp[i]=1;
                prv[i]=j;
                break;
            }
        }
       // cout<<i<<','<<dp[i]<<'/'<<prv[i]<<endl;
    }
    if(dp[(1<<n)-1]){
        cout<<"Yes\n";
        int cur=(1<<n)-1;
        while(cur){
            int k=prv[cur];
            for(int j=0;j<rss[k].size();j++){
                int nxt=j-1;
                if(j==0)nxt=rss[k].size()-1;
                ansv[rss[k][j].first]=a[rss[k][j].first][rss[k][j].second];
                ansp[rss[k][j].first]=rss[k][nxt].first;
            }
            cur^=k;
        }
        for(int i=1;i<=n;i++)cout<<ansv[i]<<' '<<ansp[i]<<'\n';
    }else{
        cout<<"No";
    }
    return 0;
}