#include <bits/stdc++.h>
using namespace std;


int n,m;
long long d[200005];
long long a[200005];
vector<pair<int,long long> > v[200005];

inline void dij() {
    set<pair<long long,int> > s;
    for (int i=1;i<=n;++i) {
        d[i]=a[i];
        s.insert(make_pair(d[i],i));
    }
    while (!s.empty()) {
        int x=s.begin()->second;
        s.erase(s.begin());
        for (int i=0;i<v[x].size();++i) {
            int to=v[x][i].first;
            long long len=v[x][i].second+d[x];
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
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        long long z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z+z));
        v[y].push_back(make_pair(x,z+z));
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    dij();
    for (int i=1;i<=n;++i)
        cout<<d[i]<<" ";
}