#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v[100005];
vector<pair<int,int> > q[100005];
int ans[100005];
int sz;
int t[500005];
int a[100005];


inline void update(int x,int y) {
    x+=sz-1;
    t[x]=y;
    x>>=1;
    while (x) {
        t[x]=t[x+x]+t[x+x+1];
        x>>=1;
    }
}

int get(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
}

int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]=min(a[i],n+1);
    }
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        q[y].push_back(make_pair(x,i));
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        int x=a[i];
        v[x].push_back(i);
        if (v[x].size()>=x) update(v[x][v[x].size()-x],1);
        if (v[x].size()>=x+1) update(v[x][v[x].size()-x-1],-1);
        if (v[x].size()>=x+2) update(v[x][v[x].size()-x-2],0);
        for (int j=0;j<q[i].size();++j) {
            int l=q[i][j].first;
            int res=get(1,sz,l,i,1);
            ans[q[i][j].second]=res;
        }
    }
    for (int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}