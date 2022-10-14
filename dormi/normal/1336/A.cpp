#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
vector<int> matrix[MAXN];
priority_queue<lli> values;
lli dfs(int loc, int parent, lli dep){
    lli val=dep;
    lli sum=0;
    for(int x:matrix[loc]){
        if(x!=parent){
            sum+=dfs(x,loc,dep+1);
        }
    }
    values.push(val-sum);
    return sum+1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    dfs(1,0,0);
    lli ans=0;
    for(int i=0;i<k;i++){
        ans+=values.top();
        values.pop();
    }
    printf("%lli\n",ans);
    return 0;
}