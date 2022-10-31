#include <bits/stdc++.h>
using namespace std;
const long long inf=1e15;
long long q[300005];
long long d[300005];
long long dd[300005];
struct st{
    long long x,w,id;
};
vector<st> v[300005];
st t;

vector<long long> ans;
long long sum;
long long n,m;
long long x,y,z;

inline void dij(long long st){
    for (long long i=1;i<=n;++i)
        d[i]=inf;
    set<pair<long long,long long> > s;
    d[st]=0;
    s.insert(make_pair(0,st));
    while (!s.empty()) {
        long long x=s.begin()->second;
        s.erase(s.begin());
        for (long long i=0;i<v[x].size();++i){
            long long to=v[x][i].x;
            long long len=d[x]+v[x][i].w;
            if (d[to]>len) {
                s.erase(make_pair(d[to],to));
                d[to]=len;
                s.insert(make_pair(d[to],to));
            }
        }
    }
}


 int main(){
     //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (long long i=1;i<=m;++i) {
        cin>>x>>y>>z;
        t.x=y;
        t.w=z;
        t.id=i;
        v[x].push_back(t);
        t.x=x;
        v[y].push_back(t);
    }
    long long stt;
    cin>>stt;
    dij(stt);
    for (long long i=1;i<=n;++i) {
            long long mx=1e9;
        for (long long j=0;j<v[i].size();++j) {
            long long to=v[i][j].x;
            if (d[to]!=d[i]-v[i][j].w) continue;
            mx=min(mx,v[i][j].w);
        }
        for (long long j=0;j<v[i].size();++j) {
            long long to=v[i][j].x;
            if (d[to]!=d[i]-v[i][j].w) continue;
            if (v[i][j].w==mx) {
                ans.push_back(v[i][j].id);
                sum+=v[i][j].w;
                break;
            }
        }
    }
    cout<<sum<<'\n';
    for (long long i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}