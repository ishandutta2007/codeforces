#include <bits/stdc++.h>
using namespace std;

long long n,m,k;
long long ans;
bool used[100001];
vector<int> v[100001];
long long a[10001];
long long maxkol;
long long x,y;
long long sz,sz2,sz3;
bool b[100001];
long long us;
void dfs(int x){
    if (b[x]==false) ++us;
    sz++;
    used[x]=true;
    sz2+=v[x].size();
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (used[to]==false) dfs(to);
    }
}
void dfs2(int x){
    used[x]=true;
    sz3+=v[x].size();
    for (int j=0;j<v[x].size();++j){
        int to=v[x][j];
        if (used[to]==false) dfs2(to);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=k;++i){
        cin>>a[i];
        b[a[i]]=true;
    }
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=k;++i){
        sz=0;
        sz2=0;
        dfs(a[i]);
        sz2/=2;
        long long zz=(sz)*(sz-1)/2;
        ans+=zz-sz2;
        maxkol=max(maxkol,sz);
    }
    sz3=0;
    for (int i=1;i<=n;++i)
        if (used[i]==false)
        dfs2(i);
    long long kl=n-k-us;
    long long ol=(kl)*(kl-1)/2;
    ol-=(sz3/2);
    ans+=ol;
    ans+=kl*maxkol;

    cout<<ans;
}