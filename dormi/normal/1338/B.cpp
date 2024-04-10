#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int leaf=0;
bool odd=false;
int leafcnt=0;
set<int> leafparents;
void dfs(int loc, int parent, int dep){
    if(sz(matrix[loc])==1&&dep%2)odd=true;
    for(int x:matrix[loc])if(x!=parent)dfs(x,loc,dep+1);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(sz(matrix[i])==1){
            leaf=i;
            leafcnt++;
            leafparents.insert(matrix[i][0]);
        }
    }
    dfs(leaf,0,0);
    if(odd)printf("3 %d\n",n-leafcnt-1+sz(leafparents));
    else printf("1 %d\n",n-leafcnt-1+sz(leafparents));
    return 0;
}