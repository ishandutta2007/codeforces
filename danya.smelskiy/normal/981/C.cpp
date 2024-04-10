#include <bits/stdc++.h>
using namespace std;



int n,x,y;
vector<int> v[200005];
int mx,pos;

vector<pair<int,int> > ans;


void dfs(int x,int y) {
    int c=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        ++c;
        dfs(to,x);
    }
    if (c==0) ans.push_back(make_pair(pos,x));
    if (c>=2) {
        cout<<"No";
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i) {
        x=v[i].size();
        if (x>mx) {
            mx=x;
            pos=i;
        }
    }
    for (int i=0;i<v[pos].size();++i) {
        int to=v[pos][i];
        dfs(to,pos);
    }
    cout<<"Yes"<<'\n';
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}