#include <bits/stdc++.h>
using namespace std;


int n;
int m;
vector<int> v[10001];
int ans,res;

int dfs(int x,int y){
    int sz1=0;
    int sz2=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int res=dfs(to,x);
        sz2=max(sz2,res);
        if (sz2>sz1) swap(sz2,sz1);
    }
    ans=max(ans,sz1+sz2);
    return sz1+1;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x,y;

    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>m;
        for (int i=1;i<=m;++i)
            v[i].clear();
        for (int i=1;i<m;++i) {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans=0;
        dfs(1,-1);
        res+=ans;
    }
    cout<<res;
}