#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[200005];
int kol[200005];
int dpmax[200005];
int dpmin[200005];
void dfs(int x){
    if (v[x].size()==0) {
        kol[x]=1;
        return;
    }
    int mx=1e9,mn=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs(to);
        kol[x]+=kol[to];
        mx=min(mx,dpmin[to]);
        mn+=kol[to]-dpmax[to];
    }
    dpmax[x]=kol[x]-mx-1;
    dpmin[x]=mn-1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    dfs(1);
    cout<<dpmax[1]+1<<" "<<dpmin[1]+1;
}