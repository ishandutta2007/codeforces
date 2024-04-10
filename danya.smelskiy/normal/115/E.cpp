#include <bits/stdc++.h>
using namespace std;




int n,m;
long long t[1000005];
int a[200005];
vector<pair<int,int> > v[200005];
long long q[1000005];
int sz;
void push(int x){
    if (!q[x]) return;
    q[x+x]+=q[x];
    q[x+x+1]+=q[x];
    t[x+x]+=q[x];
    t[x+x+1]+=q[x];
    q[x]=0;
}
void update(int l,int r,int ll,int rr,int x,long long val){
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l!=r) push(x);
    if (l>=ll && r<=rr) {
        t[x]+=val;
        q[x]+=val;
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x,val);
    update(mid+1,r,ll,rr,x+x+1,val);
    t[x]=max(t[x+x],t[x+x+1]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ++n;
    for (int i=2;i<=n;++i)
        cin>>a[i];
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=m;++i) {
        int x,y,z;
        cin>>x>>y>>z;
        ++x; ++y;
        v[y].push_back(make_pair(x,z));
    }
    for (int i=2;i<=n;++i) {
        update(1,sz,i,i,1,t[1]);
        update(1,sz,1,i-1,1,-a[i]);
        for (int j=0;j<v[i].size();++j) {
            int l=v[i][j].first;
            int val=v[i][j].second;
            update(1,sz,1,l-1,1,val);
        }
    }
    cout<<t[1];
}