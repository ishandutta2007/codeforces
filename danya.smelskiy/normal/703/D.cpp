#include <bits/stdc++.h>
using namespace std;


int n,m;
int a[1000005];
int t[1000005];
map<int,int> last;
vector<pair<int,int> > v[1000005];
int ans[1000005];
int sz;

inline void update(int x,int y) {
    for (int i=x;i<=n;i=(i|(i+1)))
        t[i]^=y;
}



inline int get(int x) {
    int res=0;
    for (int i=x;i>=0;i=(i&(i+1))-1)
        res^=t[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[y].push_back(make_pair(x,i));
    }
    int x,y;
    for (int i=1;i<=n;++i) {
        x=last[a[i]];
        if (x) update(x,a[i]);
        last[a[i]]=i;
        for (int j=0;j<v[i].size();++j) {
            x=v[i][j].first;
            y=v[i][j].second;
            ans[y]=get(i)^get(x-1);
        }
    }
    for (int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}