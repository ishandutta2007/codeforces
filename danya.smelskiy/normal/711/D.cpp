#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;



long long ans=1;
int cnt;
int used[200005];
long long f[200005];
int tin[200005];

int n;
vector<int> v[200005];


inline long long pw(long long x,long long y) {
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}

inline long long cnk(long long x,long long y) {
    long long res=f[x];
    res=(res*pw(f[y],md-2))%md;
    res=(res*pw(f[x-y],md-2))%md;
    return res;
}

inline long long solve(long long x) {
    long long z=ans;
    ans=0;
    for (int i=1;i<x;++i) {
        ans=(ans+z*cnk(x,i))%md;
    }

}

void dfs(int x,int timer) {
    tin[x]=timer;
    used[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==0) dfs(to,++timer);
        else if (used[to]==1) {
            solve(tin[x]-tin[to]+1);
            cnt-=tin[x]-tin[to]+1;
        }
    }
    used[x]=2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        v[i].push_back(x);
    }
    f[0]=1;
    for (int i=1;i<=n;++i)
        f[i]=(f[i-1]*1ll*i)%md;
    cnt=n;
    for (int i=1;i<=n;++i)
        if (used[i]==0) dfs(i,0);
    while (cnt--) {
        ans=(ans*2ll)%md;
    }
    cout<<ans;
}