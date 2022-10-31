#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long n,m;
long long x,y;
long long mn;
unsigned long long kolmn,kol,ans;
bool used[100005];
long long a[100005];
vector<long long > v[100005];
vector<long long > vv[100005];
vector<long long > q;
void dfs(int x){
    used[x]=true;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (used[to]) continue;
        dfs(to);
    }
    q.push_back(x);
}
void dfs2(long long x){
    used[x]=true;
    long long y=a[x];
    if (y==mn) ++kolmn;
    else if (y<mn) {
        mn=y;
        kolmn=1;
    }
    for (int i=0;i<vv[x].size();++i){
        int to=vv[x][i];
        if (used[to]) continue;
        dfs2(to);
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        v[x].push_back(y);
        vv[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (used[i]==false) dfs(i);
    kol=1;
    for (int i=1;i<=n;++i)
        used[i]=false;
        reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i){
        long long  z=q[i];
        if (used[z]) continue;
        mn=md;
        kolmn=0;
        dfs2(z);
        kol=(kolmn*(kol)%md)%md;
        ans+=mn;
    }
    cout<<ans<<" "<<kol;
}