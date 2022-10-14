#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=5001;
vector<int> matrix[MAXN];
int par[MAXN];
int dep[MAXN];
int mi[MAXN];
pii ed[MAXN];
pair<pii,int> st[MAXN];
int get(int a){
    if(dep[ed[a].first]<dep[ed[a].second])return ed[a].second;
    return ed[a].first;
}
void dfs(int loc, int parent, int depth){
    dep[loc]=depth;
    par[loc]=parent;
    for(int x:matrix[loc]){
        if(x!=parent){
            dfs(x,loc,depth+1);
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        mi[i]=1;
        cin>>a>>b;
        ed[i]={a,b};
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    mi[n]=1;
    dfs(1,0,0);
    int m;
    cin>>m;
    int c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        st[i]={{a,b},c};
        if(dep[a]<dep[b])swap(a,b);
        while(a!=b){
            mi[a]=max(mi[a],c);
            a=par[a];
            if(dep[a]<dep[b])swap(a,b);
        }
    }
    for(int i=0;i<m;i++){
        a=st[i].first.first,b=st[i].first.second;
        int te=INT_MAX;
        if(dep[a]<dep[b])swap(a,b);
        while(a!=b){
            te=min(te,mi[a]);
            a=par[a];
            if(dep[a]<dep[b])swap(a,b);
        }
        if(te!=st[i].second){
            printf("-1\n");
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        printf("%d ",mi[get(i)]);
    }
    return 0;
}