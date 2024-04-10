#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2*200*200;
string arr[201];
vector<int> matrix[MAXN];
int topind[MAXN],level[MAXN],nextedge[MAXN];
vector<pii> edges;
bool gone[MAXN];
int ind=1;
void addedge(int a, int b){
    matrix[a].push_back(sz(edges)),matrix[b].push_back(sz(edges)+1);
    edges.push_back({b,0}),edges.push_back({a,0});
}
void colour(int loc, int col){
    gone[loc]=true;
    for(auto x:matrix[loc]){
        if(!gone[edges[x].first])colour(edges[x].first,!col);
        edges[x].second+=col;
    }
    addedge(col?0:ind,loc);
    edges[matrix[loc].back()^col].second+=1;
}
bool reach(int s, int t){
    fill(level,level+ind+1,-1);
    queue<int> q;
    q.push(s);
    level[s]=0;
    while(sz(q)){
        auto cur=q.front();
        q.pop();
        for(auto x:matrix[cur]){
            if(edges[x].second&&level[edges[x].first]==-1){
                level[edges[x].first]=level[cur]+1;
                q.push(edges[x].first);
            }
        }
    }
    return level[t]!=-1;
}
int dfs(int loc, int flow, int t){
    if(loc==t)return flow;
    for(;nextedge[loc]<sz(matrix[loc]);nextedge[loc]++){
        pii& ne=edges[matrix[loc][nextedge[loc]]];
        if(level[ne.first]==level[loc]+1&&ne.second){
            if(int retflow=dfs(ne.first,min(flow,ne.second),t)){
                ne.second-=retflow,edges[matrix[loc][nextedge[loc]]^1].second+=retflow;
                return retflow;
            }
        }
    }
    return 0;
}
int dinics(int s, int t){
    int flow=0;
    while(reach(s,t)){
        fill(nextedge,nextedge+ind+1,0);
        while(int curflow=dfs(s,1,t))flow+=curflow;
    }
    return flow;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++)cin>>arr[i],ans+=count(arr[i].begin(),arr[i].end(),'#');
    fill(topind,topind+m,-1);
    for(int i=0;i<n;i++){
        int prev=-1;
        for(int j=0;j<m;j++){
            if(arr[i][j]=='#'){
                int bot=(i+1<n&&arr[i+1][j]=='#'?ind++:-1);
                int right=(j+1<m&&arr[i][j+1]=='#'?ind++:-1);
                if(prev!=-1&&topind[j]!=-1)addedge(prev,topind[j]);
                if(prev!=-1&&bot!=-1)addedge(prev,bot);
                if(bot!=-1&&right!=-1)addedge(bot,right);
                if(right!=-1&&topind[j]!=-1)addedge(right,topind[j]);
                prev=right,topind[j]=bot;
            }
            else prev=-1,topind[j]=-1;
        }
    }
    for(int i=1;i<ind;i++)if(!gone[i])colour(i,1);
    printf("%d\n",ans-((ind-1)-dinics(0,ind)));
    return 0;
}