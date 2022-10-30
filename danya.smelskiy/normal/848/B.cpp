#include <bits/stdc++.h>
using namespace std;
const int MX=1e5;

int n,w,h;
vector<int> v[200005];
pair<int,int> ans[200005];
int tp[100005];
int g[100005];
int t[100005];

inline bool cmp1(int x,int y) {
    if (tp[x]!=tp[y]) return tp[x]==1;
    else {
        if (tp[x]==1) return g[x]>g[y];
        else return g[x]<g[y];
    }
}

inline bool cmp2(int x,int y) {
    if (tp[x]!=tp[y]) return tp[x]==2;
    else {
        if (tp[x]==2) return g[x]<g[y];
        else return g[x]>g[y];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>w>>h;
    for (int i=1;i<=n;++i) {
        cin>>tp[i]>>g[i]>>t[i];
        v[MX+g[i]-t[i]].push_back(i);
    }
    for (int i=0;i<=MX+MX;++i) if (v[i].size()) {
        vector<int> vv;
        vv=v[i];
        sort(v[i].begin(),v[i].end(),cmp1);
        sort(vv.begin(),vv.end(),cmp2);
        for (int j=0;j<vv.size();++j) {
            int x=v[i][j];
            int zz=vv[j];
            int xx,yy;
            if (tp[zz]==1) xx=g[zz],yy=h;
            else xx=w,yy=g[zz];
            ans[x]=make_pair(xx,yy);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}