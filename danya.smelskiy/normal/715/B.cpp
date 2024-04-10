#include <bits/stdc++.h>
using namespace std;

long long d[100005];
long long d2[100005];
vector<pair<int,long long> > v[100005];
vector<pair<pair<int,int>,long long> > ans;
int n,m;
int s,t;
long long l;


inline void dij1(int x) {
    for (int i=1;i<=n;++i)
        d[i]=1e18;
    d[x]=0;
    set<pair<long long,int> > s;
    s.insert(make_pair(0,x));
    while (!s.empty()) {
        int y=s.begin()->second;
        s.erase(s.begin());
        for (int i=0;i<v[y].size();++i) {
            int to=v[y][i].first;
            long long len=v[y][i].second;
            if (len==0) len=1;
            len+=d[y];
            if (len<d[to]) {
                s.erase(make_pair(d[to],to));
                d[to]=len;
                s.insert(make_pair(d[to],to));
            }
        }
    }
}

bool used[100005];

inline void dij2(int x) {
    for (int i=1;i<=n;++i)
        d2[i]=1e18;
    d2[x]=0;
    set<pair<long long,int> > s;
    s.insert(make_pair(0,x));
    while (!s.empty()) {
        int y=s.begin()->second;
        used[y]=true;
        s.erase(s.begin());
        for (int i=0;i<v[y].size();++i) {
            int to=v[y][i].first;
            long long len=v[y][i].second;
            if (len==0) {
                len=max(1ll,l-d2[y]-d[to]);
                if (used[to]==false) ans.push_back(make_pair(make_pair(y-1,to-1),len));
            }
            len+=d2[y];
            if (len<d2[to]) {
                s.erase(make_pair(d2[to],to));
                d2[to]=len;
                s.insert(make_pair(d2[to],to));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>l>>s>>t;
    ++s; ++t;
    for (int i=1;i<=m;++i) {
        int x,y,z;
        cin>>x>>y>>z;
        ++x;++y;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    dij1(s);
    dij2(t);
    if (d2[s]!=l) {
        cout<<"NO";
        return 0;
    }
    for (int i=1;i<=n;++i) {
        for (int j=0;j<v[i].size();++j)
            if (v[i][j].first>i && v[i][j].second!=0) ans.push_back(make_pair(make_pair(i-1,v[i][j].first-1),v[i][j].second));
    }
    cout<<"YES"<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<'\n';
}