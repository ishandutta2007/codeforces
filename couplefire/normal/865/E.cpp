#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 14;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int lowbit(int x){return x&(-x);}

int n, arr[N], p[N], sum[1<<N]; ll dp[1<<N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    string _tmp; cin >> _tmp;
    n = _tmp.length();
    for(int i = 0; i<n; ++i)
        if(_tmp[i]<='9') arr[i] = _tmp[i]-'0';
        else arr[i] = _tmp[i]-'a'+10;
    int _sum = 0;
    for(int i = 0; i<n; ++i)
        _sum += arr[i];
    if(_sum%15){cout << "NO" << '\n'; return 0;}
    reverse(arr, arr+n); ll ans = INF;
    for(int _ = 0; _<(1<<(n-1)); ++_){
        if(__builtin_popcount(_)!=_sum/15) continue;
        memcpy(p, arr, sizeof(int)*N);
        for(int i = 0; i<n; ++i)
            if(_&(1<<i)) ++p[i+1], p[i] -= 16;
        memset(sum, 0, sizeof sum);
        memset(dp, 63, sizeof dp);
        for(int i = 0; i<n; ++i)
            sum[1<<i] = p[i];
        for(int i = 1; i<(1<<n); ++i)
            sum[i] = sum[i^lowbit(i)]+sum[lowbit(i)];
        dp[0] = 0;
        for(int i = 1; i<(1<<n); ++i){
            if(sum[i]<0 || sum[i]>=16) continue;
            for(int j = 0; j<n; ++j){
                if(!(i&(1<<j))) continue;
                if(dp[i^(1<<j)]==INF) continue;
                dp[i] = min(dp[i], dp[i^(1<<j)]+(1ll<<(4*j))*sum[i^(1<<j)]);
            }
        }
        ans = min(ans, dp[(1<<n)-1]);
    } if(ans==INF){cout << "NO" << '\n'; return 0;}
    string res = "";
    for(int i = 0; i<n; ++i){
        int val = ans%16; ans /= 16;
        if(val<=9) res += string(1, '0'+val);
        else res += string(1, 'a'+val-10);
    } reverse(res.begin(), res.end());
    cout << res << '\n';
}