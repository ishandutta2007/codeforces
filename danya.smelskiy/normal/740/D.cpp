#include <bits/stdc++.h>
using namespace std;

long long timer,n,x,y;
long long ans[400001];
vector<long long> tree[800001];
vector<long long> o;
long long a[400001];
long long inp[400001];
long long len[400001];
long long outp[400001];
vector<pair<long long ,long long> > v[400001];
long long sz;
void dfs(int i,long long sum){
    ++timer;
    inp[i]=timer;
    o.push_back(i);
    len[i]=sum;
    for (int j=0;j<v[i].size();++j){
        int to=v[i][j].first;
        dfs(to,sum+v[i][j].second);
    }
    outp[i]=timer;
}
inline void update(long long i,long long x){
    i+=sz;
    while (i>0){
        tree[i].push_back(x);
        i/=2;
    }
}
long long get(long long v,long long l,long long r,long long ll,long long rr,long long sum){
    if(l>r||l>rr||r<ll||tree[v].size()==0)return 0;
    if (l>=ll && r<=rr){
        long long lk=0;
        long long rk=tree[v].size()-1;
        while (lk+1<rk){
            long long midd=(lk+rk)/2;
            if (tree[v][midd]>sum) rk=midd;
            else lk=midd;
        }
        if (tree[v][rk]<=sum) return rk+1;
        else if (tree[v][lk]<=sum) return lk+1;
        else return 0;
    }
    long long mid=(l+r)/2;
     return get(v*2,l,mid,ll,rr,sum)+get(v*2+1,mid+1,r,ll,rr,sum);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(make_pair(i+1,y));
    }
    dfs(1,0);
    sz=1;
    while (sz<n) sz*=2;
    for (int j=0;j<o.size();++j)
        update(j,len[o[j]]-a[o[j]]);


    for (int j=1;j<=sz;++j)
        sort(tree[j].begin(),tree[j].end());
    for (int j=0;j<o.size();++j){
        long long to=o[j];
        ans[to]=get(1,1,sz,inp[to]+1,outp[to],len[to]);
    }
    for (int j=1;j<=n;++j)
        cout<<ans[j]<<" ";
}