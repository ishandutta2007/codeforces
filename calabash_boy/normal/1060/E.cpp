#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/
const int maxn = 2e5+100;
int first[maxn],des[maxn*2],nxt[maxn*2],tot;
int n;
ll sum[maxn][2],cnt[maxn][2];
ll ans = 0;
inline void addEdge(int x,int y){
    tot ++;
    des[tot ]= y;
    nxt[tot] = first[x];
    first[x] = tot;
}
void dfs(int node,int father){
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == father)continue;
        dfs(v,node);
    }
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (v == father)continue;
//        cout<<node<<" "<<v<<" "<<ans<<endl;
        ans += cnt[node][0] * cnt[v][0] + cnt[node][0] * sum[v][0] + cnt[v][0] * sum[node][0];
//        cout<<node<<" "<<v<<" "<<ans<<endl;
        ans +=   cnt[node][1] * sum[v][1] + cnt[v][1] * sum[node][1];
//        cout<<node<<" "<<v<<" "<<ans<<endl;
        ans +=  cnt[node][1] * sum[v][0] + cnt[v][0] *sum[node][1];
//        cout<<node<<" "<<v<<" "<<ans<<" "<<cnt[node][1]<<endl;
        ans +=  cnt[node][0] * sum[v][1] + cnt[v][1] * sum[node][0];
//        cout<<node<<" "<<v<<" "<<ans<<endl;
        ans += sum[v][1];
        sum[node][0] += sum[v][1];
        cnt[node][0] += cnt[v][1];
        ans += sum[v][0] + cnt[v][0];
        sum[node][1] += sum[v][0] + cnt[v][0];
        cnt[node][1] += cnt[v][0];
    }
    cnt[node][0] ++;
}
int main(){
    untie;
    cin>>n;
    for (int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
        addEdge(y,x);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}