#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

const int N = 205;

int n, k;
pii dp[N][N], points[N];

ll area(int i, int j, int k){
    pii a = points[i], b = points[j], c = points[k];
    return abs(a.f*b.s+b.f*c.s+c.f*a.s-a.s*b.f-b.s*c.f-c.s*a.f);
}

int check(ll mid){
    for(int siz = 1; siz<n; ++siz)
        for(int i = 0, j = siz, k; j<n; ++i, ++j)
            for(k=i+1, dp[i][j] = {0, 0}; k<j; ++k){
                ll x = area(i, j, k)+dp[i][k].s+dp[k][j].s;
                dp[i][j] = max(dp[i][j], {dp[i][k].f+dp[k][j].f+(x>=mid), (x>=mid?0:x)});
            }
    return dp[0][n-1].f;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i<n; ++i)
        cin >> points[i].f >> points[i].s;
    ll lo = 1, hi = 1e18;
    while(lo<hi){
        ll mid = lo+(hi-lo+1)/2;
        if(check(mid)<k+1) hi = mid-1;
        else lo = mid;
    }
    cout << lo << '\n';
}