#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long dp[100005];
long long kol;
long long n,m,k;
long long x,y;
long long a[100005];
vector<long long> v[100005];
bool t[100005];
void dfs(long long x,long long y){
    k-=a[x]*y;
    ++kol;
    for (long long i=0;i<v[x].size();++i) {
        long long to=v[x][i];
        dfs(to,y+1);
        a[x]+=a[to];
    }
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (long long i=1;i<=n;++i)
        cin>>a[i];
    for (long long i=1;i<=m;++i) {
        cin>>x>>y;
        v[y].push_back(x);
        t[x]=true;
    }
    for (long long i=1;i<=n;++i)
        if (t[i]==false) dfs(i,0);
    if (k<0 || kol!=n) cout<<"0";
    else {
        dp[0]=1;
        for (long long i=1;i<=n;++i)
            for (long long j=a[i];j<=k;++j)
                dp[j]=(dp[j]+dp[j-a[i]])%md;
    cout<<dp[k];
    }
}