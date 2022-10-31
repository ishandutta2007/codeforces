#include <bits/stdc++.h>
using namespace std;

int timer;
int n;
vector<int> v[1005];
int tin[1005];
bool used[1005];
vector<pair<int,int> >ans;
vector<int> q;

void dfs(int x,int y) {
    tin[x]=++timer;
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        if (used[to]==false) dfs(to,x);
        else if (tin[to]>tin[x]) { ans.push_back(make_pair(x,to)); }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i) if (used[i]==false) {
        q.push_back(i);
        dfs(i,-1);
    }
    int last=1;
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<q[last-1]<<" "<<q[last]<<'\n';
        ++last;
    }
}