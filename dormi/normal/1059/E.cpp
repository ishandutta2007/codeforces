#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int n,l;
lli s;
int lift[17][MAXN];
lli pval[MAXN];
int depth[MAXN];
int am=0;
vector<int> matrix[MAXN];
void predfs(int loc, int parent, int dep){
    lift[0][loc]=parent;
    depth[loc]=dep;
    pval[loc]+=pval[parent];
    for(int x:matrix[loc]){
        if(x!=parent)predfs(x,loc,dep+1);
    }
}
int maxfunc(int a, int b){
    if(depth[a]<depth[b])return a;
    return b;
}
void ml(){
    for(int i=1;i<17;i++){
        for(int j=1;j<=n;j++){
            lift[i][j]=lift[i-1][lift[i-1][j]];
        }
    }
}
int goup(int loc, int am){
    for(int i=0;i<17;i++){
        if(am&(1<<i))loc=lift[i][loc];
    }
    return loc;
}
int dfs(int loc, int parent){
    int ma=0;
    for(int x:matrix[loc]){
        if(x!=parent){
            int te=dfs(x,loc);
            ma=maxfunc(ma,te);
        }
    }
    if(depth[ma]>depth[loc]){
        int lo=0;
        int hi=min(depth[loc],l-1);
        while(lo!=hi){
            int mid=(lo+hi)/2+1;
            int node=goup(loc,mid);
            if(pval[loc]-pval[lift[0][node]]<=s)lo=mid;
            else hi=mid-1;
        }
        am++;
        ma=goup(loc,lo);
    }
    return ma;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>s;
    for(int i=1;i<=n;i++){
        cin>>pval[i];
        if(pval[i]>s){
            printf("-1\n");
            return 0;
        }
    }
    int a;
    depth[0]=n+1;
    for(int i=2;i<=n;i++){
        cin>>a;
        matrix[i].push_back(a);
        matrix[a].push_back(i);
    }
    predfs(1,0,0);
    ml();
    dfs(1,0);
    printf("%d\n",am);
    return 0;
}