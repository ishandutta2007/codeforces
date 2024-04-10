#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int sqrn;
int depth[MAXN];
int parent[MAXN];
bool ids=true;
vector<int> idsv;
bool nidsable[MAXN];
void dfs(int loc, int par, int dep){
    depth[loc]=dep;
    parent[loc]=par;
    vector<int> back;
    for(int x:matrix[loc]){
        if(x!=par){
            if(depth[x]){
                if(depth[loc]-depth[x]+1>=sqrn){
                    printf("2\n%d\n",depth[loc]-depth[x]+1);
                    int cur=loc;
                    while(depth[cur]>=depth[x]){
                        printf("%d ",cur);
                        cur=parent[cur];
                    }
                    ids=false;
                    return;
                }
                if(depth[x]<depth[loc])back.push_back(x);
            }
            else{
                dfs(x,loc,dep+1);
                if(!ids)return;
            }
        }
    }
    if(!nidsable[loc]){
        idsv.push_back(loc);
        nidsable[par]=true;
        for(int x:back)nidsable[x]=true;//only affects sqrtn-1 edges at most(start assigning bottom up)
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a,b;
    sqrn=ceil(sqrt(n));
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,1);
    if(ids){
        printf("1\n");
        for(int i=0;i<sqrn;i++)printf("%d ",idsv[i]);
    }
    return 0;
}