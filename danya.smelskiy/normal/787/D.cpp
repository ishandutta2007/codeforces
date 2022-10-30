#include <bits/stdc++.h>
using namespace std;
const long long inf=1e18;


vector<pair<long long,long long> > v[700005];
long long d[700005];
long long n,m,st,sz,s;
long long x,y,xx,yy,z;


void update1(long long l,long long r,long long ll,long long rr,long long x,long long y,long long z){
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {
        v[st+y].push_back(make_pair(x,z));
        return;
    }
    long long mid=(l+r)/2;
    update1(l,mid,ll,rr,x+x,y,z);
    update1(mid+1,r,ll,rr,x+x+1,y,z);
}
void update2(long long l,long long r,long long ll,long long rr,long long x,long long y,long long z){
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {
        v[sz+sz+x].push_back(make_pair(st+y,z));
        return;
    }
    long long mid=(l+r)/2;
    update2(l,mid,ll,rr,x+x,y,z);
    update2(mid+1,r,ll,rr,x+x+1,y,z);
}
inline void dij(long long x){
    set<pair<long long,long long> > q;
    for (long long i=1;i<=sz*5;++i)
        d[i]=inf;
    d[st+x]=0;
    q.insert(make_pair(0,st+x));
    while (!q.empty()) {
        long long x=q.begin()->second;
        q.erase(q.begin());
        for (long long i=0;i<v[x].size();++i) {
            long long to=v[x][i].first;
            long long len=v[x][i].second+d[x];
            if (len<d[to]) {
                q.erase(make_pair(d[to],to));
                d[to]=len;
                q.insert(make_pair(d[to],to));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>s;
    sz=1;
    while (sz<=n) sz+=sz;
    st=4*sz;
    for (long long i=1;i<=sz;++i) {
        v[sz+i-1].push_back(make_pair(st+i,0));
    }
    for (long long i=sz-1;i>0;--i){
        v[i].push_back(make_pair(i+i,0));
        v[i].push_back(make_pair(i+i+1,0));
    }
    for (long long i=1;i<sz;++i) {
        v[sz+sz+i+i].push_back(make_pair(sz+sz+i,0));
        v[sz+sz+i+i+1].push_back(make_pair(sz+sz+i,0));
    }
    for (long long i=1;i<=n;++i)
        v[st+i].push_back(make_pair(sz+sz+sz+i-1,0));
    for (long long i=1;i<=m;++i){
        cin>>x;
        if (x==1) {
            cin>>x>>y>>z;
            v[st+x].push_back(make_pair(st+y,z));
        } else if (x==2) {
            cin>>x>>xx>>yy>>z;
            update1(1,sz,xx,yy,1,x,z);
        } else {
            cin>>x>>xx>>yy>>z;
            update2(1,sz,xx,yy,1,x,z);
        }
    }
    dij(s);
    for (long long i=1;i<=n;++i)
        if (d[st+i]==inf) cout<<"-1 ";
    else cout<<d[st+i]<<" ";
}