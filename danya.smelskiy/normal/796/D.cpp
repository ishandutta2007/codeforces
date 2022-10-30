#include <bits/stdc++.h>
using namespace std;

set<int> s;
int n,m,d,x,y;
vector<pair<int,int> > v[500005];
bool used[500005];
vector<int> q;
int pred[500005];
bool used2[500005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>d;
    for (int i=1;i<=m;++i){
        cin>>x;
        q.push_back(x);
        used2[x]=true;
    }
    for (int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(make_pair(y,i));
        v[y].push_back(make_pair(x,i));
    }
    for (int i=1;i<=q.size();++i){
        x=q[i-1];
        if (used[x]) continue;
        if (used2[x]) pred[x]=0;
        used[x]=true;
        for (int j=0;j<v[x].size();++j){
            int to=v[x][j].first;
            if (to!=pred[x]) {
                if (used[to]) {
                    s.insert(v[x][j].second);
                } else if (pred[to]==0) {
                    q.push_back(to);
                    pred[to]=x;
                }
            }
        }
    }
    cout<<s.size()<<'\n';
    while (!s.empty()) {
        cout<<*s.begin()<<" ";
        s.erase(s.begin());
    }
}