#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int K = 17;
const int INF = 0x3f3f3f3f;

int n, k, best[K][N], dp[1<<K], psum[K+1][N], arr[N];
string s;

int get(int l, int r, int c){
    if(l == 0) return psum[c][r]+psum[k][r];
    return (psum[c][r]+psum[k][r])-(psum[c][l-1]+psum[k][l-1]);
}

bool calc(int mid){
    memset(dp, 63, sizeof dp);
    memset(best, 63, sizeof best);
    for(int i = 0; i<k; i++){
        for(int j = n-1; j>=0; j--){
            if(j != n-1) best[i][j] = best[i][j+1];
            if(j+mid-1 <= n-1 && get(j, j+mid-1, i) == mid) best[i][j] = j;
        }
    }
    dp[0] = -1;
    for(int mask = 0, end = (1<<k); mask<end; mask++){
        if(dp[mask] == INF) continue;
        for(int i = 0; i<k; i++){
            if(mask&(1<<i)) continue;
            dp[mask^(1<<i)] = min(dp[mask^(1<<i)], best[i][dp[mask]+1]+mid-1);
        }
    }
    return dp[(1<<k)-1] < n;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> s;
    for(int i = 0; i<n; i++)
        if(s[i] != '?') arr[i] = s[i]-'a';
        else arr[i] = k;
    for(int i = 0; i<=k; i++){
        psum[i][0] = (arr[0]==i);
        for(int j = 1; j<n; j++)
            psum[i][j] = psum[i][j-1]+(arr[j]==i);
    }
    int lo = 0, hi = n/k;
    while(lo < hi){
        int mid = lo+(hi-lo+1)/2;
        if(calc(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo << endl;
}