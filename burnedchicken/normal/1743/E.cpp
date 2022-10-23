#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=5005,mod=998244353;

int p[2],t[2],h,s,dp[maxn];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(i,0,2) cin >> p[i] >> t[i];
    cin >> h >> s;
    rep(i,1,h+1){
        dp[i]=4e18;
        rep(j,0,2) dp[i]=min(dp[i],dp[max(i-(p[j]-s),0ll)]+t[j]);
        rep(j,0,2) rep(k,1,i+1){
            int x=(t[j]*k)/t[j^1];
            if(!x) continue;
            dp[i]=min(dp[i],dp[max(i-((p[j]-s)*k+(p[j^1]-s)*x+s),0ll)]+t[j]*k);
        }
    }
    cout << dp[h] << "\n";
}