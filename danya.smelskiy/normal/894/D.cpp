#include <bits/stdc++.h>
using namespace std;



vector<pair<int,int> > v[1000005];
vector<long long> q[1000005];
vector<long long> sum[1000005];
long long ans;
long long pred[1000005];
int n,m;

vector<long long> mrg(vector<long long> x,vector<long long> y){
    int l=0;
    int r=0;
    vector<long long> res;
    res.clear();
    while ((l<x.size()) || (r<y.size())) {
        if (l==x.size()) {
            res.push_back(y[r++]);
        } else if (r==y.size()) {
            res.push_back(x[l++]);
        } else {
            if (x[l]<y[r]) res.push_back(x[l++]);
            else res.push_back(y[r++]);
        }
    }
    return res;
}
void build(int x,long long yy){
    pred[x]=yy;
    vector<long long > v2;
    q[x].push_back(yy);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        build(to,v[x][i].second);
        v2=q[to];
        for (int j=0;j<v2.size();++j)
            v2[j]+=yy;
        q[x]=mrg(q[x],v2);
    }
    long long last=0;
    for (int i=0;i<q[x].size();++i) {
        last+=q[x][i];
        sum[x].push_back(last);
    }
}
inline long long solve(int x,long long y){
    int l=0;
    int r=q[x].size()-1;
    if (r==-1) return 0;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (q[x][mid]<=y) l=mid;
        else r=mid;
    }
    if (q[x][r]<=y) l=r;
    if (q[x][l]>y) return 0;
    return (long long)(l+1)*y-sum[x][l];
}
void get(int x,int y,long long z){
    if (!x || z<=0) return;
    ans+=z;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        ans+=solve(to,z);
    }
    get(x/2,x,z-pred[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<n;++i) {
        int l;
        cin>>l;
        v[(i+1)/2].push_back(make_pair(i+1,l));
    }
    build(1,0);
    for (int i=1;i<=m;++i) {
        int x;
        long long y;
        cin>>x>>y;
        ans=0;
        ans=y;
        for (int j=0;j<v[x].size();++j) {
            int to=v[x][j].first;
            ans+=solve(to,y);
        }
        get(x/2,x,y-pred[x]);
        cout<<ans<<'\n';
    }
}