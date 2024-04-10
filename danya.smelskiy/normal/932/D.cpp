#include <bits/stdc++.h>
using namespace std;


int all;
pair<int,long long> dp[500005][21];
pair<int,long long> dp2[500005][21];
long long val[500005];


inline int get_pred(int x,long long y) {
    for (int i=20;i>=0;--i)
        if (dp[x][i].first && dp[x][i].second<y) x=dp[x][i].first;
    if (val[x]<y) x=dp[x][0].first;
    return x;
}

inline void upd(int x,long long y) {
    ++all;
    val[all]=y;
    dp[all][0]=make_pair(x,-1);
    for (int i=1;i<=20;++i) {
        dp[all][i]=make_pair(dp[dp[all][i-1].first][i-1].first,max(dp[all][i-1].second,dp[dp[all][i-1].first][i-1].second));
    }
    int z=get_pred(all,y);
    if (z==all) z=0;
    for (int i=0;i<=20;++i)
        dp[all][i].second=max(dp[all][i].second,y);
    dp2[all][0]=make_pair(z,val[all]);
    for (int i=1;i<=20;++i) {
        dp2[all][i]=make_pair(dp2[dp2[all][i-1].first][i-1].first,dp2[all][i-1].second+dp2[dp2[all][i-1].first][i-1].second);
    }
}

inline long long solve(int x,long long y) {
    long long ans=0;
    for (int i=20;i>=0;--i)
    if (dp2[x][i].first && dp2[x][i].second<=y) {
        y-=dp2[x][i].second;
        x=dp2[x][i].first;
        ans+=(1ll<<i);
    }
    if (x && val[x]<=y) ++ans;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // dp1 - ( vershuna / maximum na puti )
    // dp2 - ( vershuna / summa )
    all=1;
    int q;
    cin>>q;
    long long last=0;
    int tp;
    long long x,y;
    long long res;
    while (q--) {
        cin>>tp>>x>>y;
        x^=last;
        y^=last;
        if (tp==1) upd(x,y);
        else {
            res=solve(x,y);
            cout<<res<<'\n';
            last=res;
        }
    }
}