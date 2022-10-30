#include <bits/stdc++.h>
using namespace std;

int n,m;
int x,y;
vector<int> v[100005];
int kol[100005];
int ans[100005];
set<pair<int,int> > s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        ++kol[x];
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i) {
        s.insert(make_pair(kol[i],-i));
    }
    for (int i=n;i>0;--i) {
        int x=s.begin()->second;
        s.erase(s.begin());
        x*=-1;
        ans[x]=i;
        for (int i=0;i<v[x].size();++i) {
            int to=v[x][i];
            s.erase(make_pair(kol[to],-to));
            --kol[to];
            s.insert(make_pair(kol[to],-to));
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}