#include <bits/stdc++.h>
using namespace std;

long long kol[100005];
vector<long long> v[100005];
long long n;


pair<long long,long long> dfs(long long x,long long y){
    long long all=0;
    vector<long long> q;
    for (long long i=0;i<v[x].size();++i) {
        long long to=v[x][i];
        if (to==y) continue;
        --kol[to];
        pair<long long,long long> res=dfs(to,x);
        q.push_back(res.first+2ll);
        all+=res.second;
    }
    sort(q.begin(),q.end());
    long long k=0,res=0;
    for (long long i=q.size()-1ll;i>=max(0ll,(long long)q.size()-kol[x]);--i) {
        ++k;
        res+=q[i];
    }
    if (k<kol[x]) {
        long long l=kol[x]-k;
        l=min(l,all);
        res+=2ll*l;
        k+=l;
    }
    return make_pair(res,kol[x]-k);
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i)
        cin>>kol[i];
    for (long long i=1;i<n;++i) {
        long long x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    long long s;
    cin>>s;
    pair<long long,long long> res=dfs(s,-1);
    cout<<res.first;
}