#include <bits/stdc++.h>
using namespace std;

int n;
int kol[5005];
vector<int> v[5005];
bitset<5005> s,q;

int dfs(int x,int y){
    kol[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        kol[x]+=kol[to];
    }
    s.reset();
    s.set(0);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        s|=(s<<kol[to]);
    }
    if (n-kol[x]) s|=(s<<(n-kol[x]));
    q|=s;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    vector<int> ans;
    for (int i=1;i<n-1;++i)
        if (q.test(i)) ans.push_back(i);
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" "<<n-1-ans[i]<<'\n';
}