#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int INF = 0x3f3f3f3f;

int n, arr[N], dp[N][2][2];
array<int, 2> prv[N][2][2];

void trace(int i, int sgn, int pos){
    if(i) trace(i-1, prv[i][sgn][pos][0], prv[i][sgn][pos][1]);
    cout << (sgn?-arr[i]:arr[i]) << ' ';
}

void solve(){ cin >> n;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    memset(dp, INF, sizeof(int)*n*2*2);
    dp[0][0][0] = dp[0][1][0] = -INF;
    for(int i = 1; i<n; ++i)
        for(int sgn = 0; sgn<2; ++sgn)
            for(int pos = 0; pos<2; ++pos){
                int a = sgn?-arr[i-1]:arr[i-1], b = dp[i-1][sgn][pos];
                if(b==INF) continue; if(pos) swap(a, b);
                for(int nsgn = 0; nsgn<2; ++nsgn){
                    int nval = nsgn?-arr[i]:arr[i];
                    if(nval<b) continue;
                    if(nval<a && a<dp[i][nsgn][1]) 
                        dp[i][nsgn][1] = a, prv[i][nsgn][1] = {sgn, pos};
                    if(nval>a && b<dp[i][nsgn][0]) 
                        dp[i][nsgn][0] = b, prv[i][nsgn][0] = {sgn, pos};
                }
            }
    for(int sgn = 0; sgn<2; ++sgn){
        for(int pos = 0; pos<2; ++pos){
            if(dp[n-1][sgn][pos]==INF) continue;
            cout << "YES" << '\n'; trace(n-1, sgn, pos);
            cout << '\n'; return;
        }
    } cout << "NO" << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}