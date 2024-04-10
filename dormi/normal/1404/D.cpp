#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e6+1;
vector<int> matrix[MAXN];
vector<int> pairs[MAXN];
bool gone[MAXN];
vector<int> nodes[2];
void dfs(int loc, bool use){
    nodes[use].push_back(loc);
    gone[loc]=true;
    for(auto x:matrix[loc])if(!gone[x])dfs(x,!use);
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n%2==0){
        printf("First\n");
        fflush(stdout);
        for(int i=1;i<=n;i++)printf("%d ",i);
        for(int i=1;i<=n;i++)printf("%d ",i);
        printf("\n");
        fflush(stdout);
        int ans;
        cin>>ans;
        return 0;
    }
    else{
        printf("Second\n");
        fflush(stdout);
        int a;
        for(int i=1;i<=2*n;i++){
            cin>>a;
            pairs[a].push_back(i);
            matrix[((i+n-1)%(2*n))+1].push_back(i);
        }
        for(int i=1;i<=n;i++)matrix[pairs[i][0]].push_back(pairs[i][1]),matrix[pairs[i][1]].push_back(pairs[i][0]);
        for(int i=1;i<=2*n;i++)if(!gone[i])dfs(i,true);
        if(accumulate(nodes[1].begin(),nodes[1].end(),ll(0))%ll(2*n)==0)nodes[0].swap(nodes[1]);
        assert(sz(nodes[0])==n);
        for(auto x:nodes[0])printf("%d ",x);
        printf("\n");
        fflush(stdout);
        int ans;
        cin>>ans;
        return 0;
    }
    return 0;
}