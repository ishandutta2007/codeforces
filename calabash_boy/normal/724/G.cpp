#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
typedef long long ll;
struct Linear_Basis{
    //basis vector
    ll basis[62];
    int count = 0;
    void clear(){
        memset(basis,0,sizeof basis);
        count = 0;
    }
    void ins(ll x){
        if (!x)return;
        for (int i=60;i>=0;i--){
            if (x & (1ll<< i)){
                if (!basis[i]){basis[i] = x;count++;break;}
                x ^= basis[i];
            }
        }
    }
}basis;
ll C[62][62];
ll pow2[62];
vector<pair<int,ll> > E[maxn];
bool used[maxn];
ll xorsum[maxn];
int n,m;
ll ans = 0;
int num[62][2];
void dfs(int u){
    for (int i=0;i<=60;i++){
        int bit = (xorsum[u] & (1ll<<i)) != 0;
        num[i][bit] ++;
    }
    used[u] = 1;
    for (auto e : E[u]){
        int v;ll w;
        tie(v,w) = e;
        if (used[v]){
            basis.ins(xorsum[v] ^ xorsum[u] ^ w);
            continue;
        }
        xorsum[v] = xorsum[u] ^ w;
        dfs(v);
    }
}
inline ll C2(int x){
    return 1ll * x * (x-1) / 2  % mod;
}
void gao(int i){
    basis.clear();
    memset(num,0,sizeof num);
    dfs(i);
    int count = basis.count;
    int N = num[0][0] + num[0][1];
    for (int i=0;i<=60;i++){
        int cnt = 0;
        for (int j=i;j<=60;j++){
            if (basis.basis[j] & (1ll << i))cnt ++;
        }
        ll odd = 0,even = 0;
        for (int j=0;j<=cnt;j++){
            if (j&1){
                (odd += C[cnt][j]) %= mod;
            }else{
                (even += C[cnt][j]) %= mod;
            }
        }
        odd = odd * pow2[count - cnt] % mod;
        even = even * pow2[count - cnt] % mod;
        (ans += pow2[i] * odd % mod * (C2(num[i][0]) + C2(num[i][1])) % mod) %= mod;
        (ans += pow2[i] * even % mod * num[i][0] % mod * num[i][1] % mod) %= mod;
    }
}
int main(){
    pow2[0] = 1;
    for (int i=1;i<=60;i++){
        pow2[i] = pow2[i-1] * 2 % mod;
    }
    C[0][0] = 1;
    for (int i=1;i<=60;i++){
        C[i][0] = C[i][i] = 1;
        for (int j=1;j<i;j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        E[u].push_back(make_pair(v,w));
        E[v].push_back(make_pair(u,w));
    }
    for (int i=1;i<=n;i++){
        if (!used[i]){
            gao(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}