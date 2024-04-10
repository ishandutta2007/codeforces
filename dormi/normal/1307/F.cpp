#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
int n,k,r;
pii dis[MAXN];
int find(int a){
    if(dis[a].first==a)return a;
    return dis[a].first=find(dis[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(dis[ap].second<dis[bp].second)swap(ap,bp);
    dis[ap].second+=dis[bp].second;
    dis[bp].first=ap;
}
vector<int> matrix[MAXN];
vector<int> rest;
int dist[MAXN];
int lcat[18][MAXN];
int depth[MAXN];
int MAXV=2e5+1;
vector<pii> edges;
void dfs(int loc, int par, int dep){
    lcat[0][loc]=par;
    depth[loc]=dep;
    for(int x:matrix[loc]){
        if(x!=par)dfs(x,loc,dep+1);
    }
}
void ml(){
    for(int i=1;i<18;i++){
        for(int j=1;j<=n;j++)lcat[i][j]=lcat[i - 1][lcat[i - 1][j]];
    }
}
int goup(int loc, int a){
    for(int i=0;i<18;i++)if(a&(1<<i))loc=lcat[i][loc];
    return loc;
}
int getlca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    a=goup(a,depth[a]-depth[b]);
    if(a==b)return a;
    for(int i=17;i>=0;i--){
        if(lcat[i][a] != lcat[i][b])a=lcat[i][a], b=lcat[i][b];
    }
    return lcat[0][a];
}
bool check(int a, int b){
    int lca=getlca(a,b);
    int tdist=depth[a]+depth[b]-2*depth[lca];
    if(tdist<=k)return true;
    int lo=0;
    int hi=tdist;
    int adis=depth[a]-depth[lca];
    int bdis=depth[b]-depth[lca];
    while(lo!=hi){
        int mid=(lo+hi)/2+1;
        int cur=(mid<=adis?goup(a,mid):goup(b,bdis-(mid-adis)));
        if(mid+dist[cur]<=k)lo=mid;
        else hi=mid-1;
    }
    int lo2=0;
    int hi2=tdist;
    while(lo2!=hi2){
        int mid=(lo2+hi2)/2+1;
        int cur=(mid<=bdis?goup(b,mid):goup(a,adis-(mid-bdis)));
        if(mid+dist[cur]<=k)lo2=mid;
        else hi2=mid-1;
    }
    if(lo2+lo>=tdist)return 1;
    int cura=(lo<=adis?goup(a,lo):goup(b,bdis-(lo-adis)));
    int curb=(lo2<=bdis?goup(b,lo2):goup(a,adis-(lo2-bdis)));
    if(find(cura)==find(curb))return 1;
    return 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>r;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        dis[i]={i,1};
        dist[i]=MAXV;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
        edges.push_back({a,b});
    }
    dis[n]={n,1};
    dist[n]=MAXV;
    queue<int> q;
    for(int i=0;i<r;i++){
        cin>>a;
        rest.push_back(a);
        q.push(a);
        dist[a]=0;
    }
    while(sz(q)){
        int cur=q.front();
        q.pop();
        for(int x:matrix[cur]){
            if(dist[cur]+1<dist[x]){
                dist[x]=dist[cur]+1;
                q.push(x);
            }
        }
    }
    for(pii x:edges){
        if(dist[x.first]+dist[x.second]+1<=k){
            uni(x.first,x.second);
        }
    }
    dfs(1,0,0);
    ml();
    int v;
    cin>>v;
    while(v--){
        cin>>a>>b;
        if(check(a,b))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}