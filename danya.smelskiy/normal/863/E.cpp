#include <bits/stdc++.h>
using namespace std;

vector<int> v;
pair<int,int> a[300005];
int q[7000000];
int t[7000000];
int n,sz;
map<int,int> mt;
void push(int x){
    if (!q[x]) return;
    q[x+x]+=q[x];
    q[x+x+1]+=q[x];
    t[x+x]+=q[x];
    t[x+x+1]+=q[x];
    q[x]=0;
}

int get(int l,int r,int ll,int rr,int x){
    if (l!=r) push(x);
    if (l>r || ll>r || l>rr || ll>rr) return 1e9;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return min(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}
void update(int l,int r,int ll,int rr,int x){
    if (l!=r) push(x);
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l>=ll && r<=rr) {
        ++t[x];
        ++q[x];
        if (l!=r) push(x);
        return;
    }
    int mid=(l+r)>>1;
    update(l,mid,ll,rr,x+x);
    update(mid+1,r,ll,rr,x+x+1);
    t[x]=min(t[x+x],t[x+x+1]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
        for (int i=1;i<=n;++i) {
            v.push_back(a[i].first);
            v.push_back(a[i].first-1);
            v.push_back(a[i].second);
            v.push_back(a[i].second+1);
        }
        sort(v.begin(),v.end());
        int last=0;
    for (int i=0;i<v.size();++i)
    if (i==0 || v[i]!=v[i-1]) {
        ++last;
        mt[v[i]]=last;
    }
    for (int i=1;i<=n;++i) {
        a[i].first=mt[a[i].first];
        a[i].second=mt[a[i].second];
    }
    sz=1;
    while (sz<last) sz+=sz;
    for (int i=1;i<=n;++i){
        update(1,sz,a[i].first,a[i].second,1);
    }
    for (int i=1;i<=n;++i)
    if (get(1,sz,a[i].first,a[i].second,1)>=2) {
        cout<<i;
        return 0;
    }
    cout<<"-1";
}