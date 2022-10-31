#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, k, ans[N][N];

int solve(int l, int r, int col){
    if(r-l+1<=k){
        for(int i = l; i<=r; ++i)
            for(int j = i+1; j<=r; ++j)
                ans[i][j] = col;
        return col;
    }
    int len1 = (r-l+1)/k, len2 = len1+1;
    int b = (r-l+1)-len1*k, a = k-b, res = 0;
    for(int i = 0, lp = l, rp = l+len1; i<k; ++i, lp = rp, rp += (i<a?len1:len2)){
        for(int j = lp; j<rp; ++j)
            for(int x = rp; x<=r; ++x)
                ans[j][x] = col;
        res = max(res, solve(lp, rp-1, col+1));
    }
    return res;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k; 
    cout << solve(1, n, 1) << '\n';
    for(int i = 1; i<=n; ++i)
        for(int j = i+1; j<=n; ++j)
            cout << ans[i][j] << ' ';
}