#include <bits/stdc++.h>
using namespace std;
int n,m;
int kol[200001];
long long now1,now2;
bool used[200001];
vector<int> v[200001];
int x,y;


void dfs(int x){
    used[x]=true;
    now1+=kol[x];
    ++now2;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (used[to]==false) dfs(to);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        ++kol[x];
        ++kol[y];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
    if (used[i]==false) {
        now1=0;
        now2=0;
        dfs(i);
        now2=(now2)*(now2-1)/2;
        now1/=2;
        if (now2!=now1) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}