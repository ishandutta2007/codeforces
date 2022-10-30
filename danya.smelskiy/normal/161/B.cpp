#include <bits/stdc++.h>
using namespace std;

int n,m;
int tp[1005];
long double val[1005];
vector<pair<int,int> > v[3];
vector<int> ans[1005];


inline bool cmp(pair<int,int> x,pair<int,int> y) {
    return x>y;
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        int x,y;
        cin>>x>>y;
        tp[i]=y;
        val[i]=x;
        v[y].push_back(make_pair(x,i));
    }
    sort(v[1].begin(),v[1].end(),cmp);
    int z=min((int)v[1].size(),m-1);
    for (int i=1;i<=z;++i)
        ans[i].push_back(v[1][i-1].second);
    int c1=z;
    int c2=0;
    int last=z;
    while (c1<v[1].size() || c2<v[2].size()) {
        if (last<m) ++last;
        if (c1<v[1].size()) ans[last].push_back(v[1][c1].second),++c1;
        else ans[last].push_back(v[2][c2].second),++c2;
    }
    long double res=0;
    for (int i=1;i<=m;++i) {
        bool t=false;
        long double mn=1e9;
        long double s=0;
        for (int j=0;j<ans[i].size();++j) {
            int x=ans[i][j];
            if (tp[x]==1) t=true;
            mn=min(mn,val[x]);
            s+=val[x];
        }
        if (t) s-=(long double)mn/(2.);
        res+=s;
    }
    cout<<fixed<<setprecision(1)<<res<<'\n';
    cout<<fixed<<setprecision(0);
    for (int i=1;i<=m;++i) {
        cout<<ans[i].size()<<" ";
        for (int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}