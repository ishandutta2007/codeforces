#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, k, dp[N], a[N], b[N], to[N], sufmx[N], bit[N], ans;
bool vis[N];

void upd(int pos, int bruh){
    for(; pos<N; pos = pos|(pos+1))
        inc(bit[pos], bruh);
}

int sum(int r){
    int res = 0;
    for(; r>=0; r = (r&(r+1))-1)
        inc(res, bit[r]);
    return res;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; ++i){
        cin >> a[i] >> b[i];
        to[a[i]] = b[i];
    }
    for(int i = 2*n; i>=1; --i)
        if(to[i]){
            dp[i] = add(sum(to[i]), 1);
            upd(to[i], dp[i]);
        } cin >> k;
    for(int i = 1; i<=k; ++i){
        int pos; cin >> pos;
        int x = a[pos];
        sufmx[x] = to[x];
        vis[x] = 1;
    }
    for(int i = 2*n; i>=1; --i)
        sufmx[i] = max(sufmx[i], sufmx[i+1]);
    for(int i = 1; i<=2*n; ++i)
        if(to[i]) if(vis[i] || to[i]<sufmx[i+1])
            inc(ans, dp[i]);
    cout << ans << '\n';
}