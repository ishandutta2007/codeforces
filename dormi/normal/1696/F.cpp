#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=101;
bool gone[MN];
bool conn[MN][MN][MN];
vector<vector<int>> groups[MN];
int group[MN];
int par[MN];
vector<int> adj[MN];
int dist[MN];
int amdist[MN];
void dfs(int loc, int parent){
    dist[loc]=dist[parent]+1;
    for(auto x:adj[loc])if(!dist[x]){
        dfs(x,loc);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            par[i]=0;
            group[i]=0;
            groups[i]=vector<vector<int>>();
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    conn[i][j][k]=false;
                }
            }
            gone[i]=false;
        }
        char a;
        for(int i=1;i<n;i++){
            for(int j=1;j<=n-i;j++){
                for(int k=1;k<=n;k++){
                    cin>>a;
                    if(a=='1'){
                        conn[k][i][i+j]=true;
                        conn[k][i+j][i]=true;
                    }
                }
            }
        }
        bool work=true;
        for(int i=1;i<=n;i++){
            groups[i]=vector<vector<int>>();
            for (int j = 1; j <= n; j++)gone[j] = false,conn[i][j][j]=true;
            gone[i] = true;
            for (int j = 1; j <= n; j++) {
                if (i != j && conn[i][i][j])work = false;
                if (!gone[j]) {
                    queue<int> q;
                    q.push(j);
                    gone[j] = true;
                    groups[i].push_back({});
                    while (sz(q)) {
                        auto cur = q.front();
                        q.pop();
                        groups[i].back().push_back(cur);
                        for (int k = 1; k <= n; k++) {
                            if (conn[i][cur][k] && !gone[k]) {
                                gone[k] = true;
                                q.push(k);
                            }
                        }
                    }
                }
            }
            group[i]=-1;
            for(int gp=0;gp<sz(groups[i]);gp++){
                for(auto x:groups[i][gp])group[x]=gp;
            }
            for(auto x:groups[i]){
                for(auto y1:x){
                    for(auto y2:x){
                        if(y1!=y2&&!conn[i][y1][y2]){
                            work=false;
                        }
                    }
                }
            }
        }
        if(work==false){
            printf("NO\n");
            continue;
        }
        int root=1;
        bool complete=false;
        for(int i=0;i<sz(groups[root]);i++){
            for(auto x:groups[root][i]){
                group[x]=i;
            }
        }
        for(int stgroup=0;stgroup<sz(groups[root]);stgroup++) {
            work=true;
            for(int i=2;i<=n;i++)par[i]=0;
            for (auto y: groups[root][stgroup]) {
                par[y] = root;
            }
            int cur=stgroup;
            while(1){
                int nextgroup=-1;
                for (auto y: groups[root][cur]) {
                    if (par[y] == 0) {
                        work = false;
                        break;
                    }
                    for (auto megroup: groups[y]) {
                        bool good = false;
                        for (auto z: megroup) {
                            if (z == par[y]) {
                                good = true;
                            }
                        }
                        if (good) {
                            for (auto z: megroup) {
                                if (z != par[y]) {
                                    if (par[z]) {
                                        work = false;
                                        break;
                                    }
                                    nextgroup=group[z];
                                    par[z] = y;
                                }
                            }
                            break;
                        }
                    }
                    if (work == false)break;
                }
                if (work == false)break;
                if(nextgroup==-1)break;
                cur=nextgroup;
            }
            for(int i=2;i<=n;i++){
                if(!par[i]){
                    work=false;
                    break;
                }
            }
            if(work==false){
                continue;
            }
            for(int i=1;i<=n;i++)adj[i]=vector<int>(),dist[i]=0;
            for(int i=2;i<=n;i++){
                adj[par[i]].push_back(i);
                adj[i].push_back(par[i]);
            }
            dfs(1,0);
            for(int i=1;i<=n;i++){
                if(!dist[i]){
                    work=false;
                    break;
                }
            }
            if(work==false){
                continue;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)dist[j]=0,amdist[j]=0;
                dfs(i,0);
                for(int j=1;j<=n;j++){
                    amdist[dist[j]]++;
                }
                for(auto x:groups[i]){
                    int res=0;
                    for(auto y:x){
                        if(res==0)res=dist[y];
                        else if(res!=dist[y]){
                            res=-1;
                            break;
                        }
                    }
                    if(res==-1||amdist[res]!=sz(x)){
                        work=false;
                        break;
                    }
                }
                if(work==false)break;
            }
            if(work==false){
                continue;
            }
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                if (i != root)printf("%d %d\n", i, par[i]);
            }
            complete=true;
            break;
        }
        if (complete == false) {
            printf("NO\n");
            continue;
        }
    }
    return 0;
}