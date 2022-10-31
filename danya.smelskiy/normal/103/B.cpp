#include <bits/stdc++.h>
using namespace std;

long long n,m,x,y,q,kol;
vector<int> v[2000];
int used[2000];
void dfs(int x,int pred=-1){
    used[x]=1;
    ++kol;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==pred) continue;
        if (used[to]==1){
            ++q;
            continue;
        }
        if (used[to]==0) dfs(to,x);
    }
    used[x]=2;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    if (kol!=n) {
        cout<<"NO";
        return 0;
    }
    if (q!=1) {
        cout<<"NO";
        return 0;
    }
    cout<<"FHTAGN!";
}