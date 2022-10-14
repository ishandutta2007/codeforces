#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=4e5+1;
vector<vector<char>> arr;
vector<vector<int>> ind;
int am[MN];
vector<int> adj[MN];
int nodecnt=0;
int id[MN],low[MN];
bool inst[MN];
vector<int> st;
int et;
int in[MN];
vector<vector<int>> comps;
vector<int> nadj[MN];
int marked[MN];
int leftspec[MN];
int trans[MN];
pii dp[MN];
void dfs(int loc){
    id[loc]=low[loc]=et++;
    inst[loc]=true,st.push_back(loc);
    for(auto x:adj[loc]){
        if(!id[x])dfs(x),low[loc]=min(low[loc],low[x]);
        else if(inst[x])low[loc]=min(low[loc],id[x]);
    }
    if(id[loc]==low[loc]){
        comps.push_back({});
        while(1){
            int cur=st.back();
            st.pop_back();
            in[cur]=sz(comps)-1;
            inst[cur]=false;
            comps.back().push_back(cur);
            if(cur==loc)break;
        }
    }
}
void mark(int loc){
    for(auto x:nadj[loc]){
        if(!marked[x]) {
            marked[x] = true;
            mark(x);
        }
    }
}
pii solve(int loc){
    if(dp[loc].first)return dp[loc];
    dp[loc]={INT_MAX,INT_MIN};
    for(auto x:nadj[loc]){
        if(!marked[x]){
            pii te=solve(x);
            dp[loc]={min(dp[loc].first,te.first),max(dp[loc].second,te.second)};
        }
    }
    return dp[loc];
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    arr.resize(n+1,vector<char>(m+1));
    ind.resize(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>arr[i][j];
    for(int i=1;i<=m;i++)cin>>am[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]=='#'){
                ind[i][j]=++nodecnt;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]=='#'){
                if(i-1>=1&&arr[i-1][j]=='#')adj[ind[i][j]].push_back(ind[i-1][j]);
                for(int k=i+1;k<=n;k++){
                    if(arr[k][j]=='#'){
                        adj[ind[i][j]].push_back(ind[k][j]);
                        break;
                    }
                }
                bool leftdone=false,rightdone=false;
                for(int k=i;k<=n&&(!leftdone||!rightdone)&&(arr[k][j]!='#'||k==i);k++){
                    if(j-1>=1&&!leftdone&&arr[k][j-1]=='#'){
                        adj[ind[i][j]].push_back(ind[k][j-1]),leftdone=true;
                    }
                    if(j+1<=m&&!rightdone&&arr[k][j+1]=='#'){
                        adj[ind[i][j]].push_back(ind[k][j+1]),rightdone=true;
                    }
                }
            }
        }
    }
    et=1;
    comps.push_back({});
    for(int i=1;i<=nodecnt;i++)if(!id[i])dfs(i);
    for(int i=1;i<sz(comps);i++){
        leftspec[i]=INT_MAX;
        for(auto x:comps[i])for(auto y:adj[x])if(in[y]!=i)nadj[i].push_back(in[y]);
        sort(nadj[i].begin(),nadj[i].end()),nadj[i].erase(unique(nadj[i].begin(),nadj[i].end()),nadj[i].end());
    }
    vector<int> spec;
    for(int i=1;i<=m;i++){
        for(int j=n;j>=1;j--){
            if(arr[j][i]=='#'){
                am[i]--;
                if(am[i]==0)spec.push_back(in[ind[j][i]]),leftspec[in[ind[j][i]]]=min(leftspec[in[ind[j][i]]],i);
            }
        }
    }
    sort(spec.begin(),spec.end()),spec.erase(unique(spec.begin(),spec.end()),spec.end());
    for(auto x:spec)if(!marked[x])mark(x);
    vector<int> compress;
    for(auto x:spec)if(!marked[x])compress.push_back(leftspec[x]);
    sort(compress.begin(),compress.end());
    for(auto x:spec)if(!marked[x])dp[x].first=dp[x].second=lower_bound(compress.begin(),compress.end(),leftspec[x])-compress.begin()+1;
    for(int i=1;i<sz(comps);i++){
        if(!marked[i]){
            pii te=solve(i);
            if(te.first!=INT_MAX){
                trans[te.first]=max(trans[te.first],te.second);
            }
        }
    }
    for(int i=2;i<=sz(compress);i++)trans[i]=max(trans[i-1],trans[i]);
    int cur=1,ans=0;
    while(cur<=sz(compress))ans++,cur=trans[cur]+1;
    printf("%d\n",ans);
    return 0;
}