#include <bits/stdc++.h>
using namespace std;



int n,m,st;
int d[100005];
vector<pair<int,int> > v[100005];


inline void dij(int x) {
    for (int i=1;i<=n;++i)
        d[i]=2e9;
    d[x]=0;
    set<pair<int,int> > s;
    s.insert(make_pair(0,x));
    while (!s.empty()) {
        x=s.begin()->second;
        s.erase(s.begin());
        for (int i=0;i<v[x].size();++i) {
            int to=v[x][i].first;
            int len=d[x]+v[x][i].second;
            if (len<d[to]) {
                s.erase(make_pair(d[to],to));
                d[to]=len;
                s.insert(make_pair(d[to],to));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>st;
    while (m--) {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dij(st);
    int s;
    cin>>s;
    int ans=0;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<v[i].size();++j) {
            int x=i;
            int y=v[i][j].first;
            int len=v[i][j].second;
            if (x<y) continue;
            if (d[x]<s && s-d[x]<len && d[y]+len-(s-d[x])>=s) { ++ans; }
            if (d[y]<s && s-d[y]<len && d[x]+len-(s-d[y])>=s) { ++ans; }
            if (d[x]<s && s-d[x]<len && d[y]+len-(s-d[x])>=s && d[y]<s && s-d[y]<len && d[x]+len-(s-d[y])>=s && s-d[x]+s-d[y]==len) --ans;
        }
    }
    for (int i=1;i<=n;++i)
        if (d[i]==s) ++ans;
    cout<<ans;
}