#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

pair<int, pair<int, int>> ckmax(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> b){return (b>a)?a=b:b;}
int ckmax(int &a, int b){return (b>a)?a=b:b;}
int ckmin(int &a, int b){return (b<a)?a=b:b;}

int getmask(string s){
    int res = 0;
    for(int i = 0; i<s.length(); i++) res += (s[i]-'0')*(1<<i);
    return res;
}

int n, m, k;
string s[2];
int cnt[2];
int dp[2][1<<20];
int p[20];
pair<int, pair<int, int>> ans = {0, {0, 0}};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> s[0] >> s[1];
    for(int i = 0; i<k; i++) p[i] = i;
    for(int i = 0; i<2; i++) cnt[i] = count(s[i].begin(), s[i].end(), '1');
    for(int i = 0; i<(1<<k); i++) dp[0][i] = INF, dp[1][i] = -INF;
    dp[0][getmask(s[0])] = 0;
    dp[1][getmask(s[1])] = 0;
    for(int i = 1; i<=n; i++){
        int a, b; cin >> a >> b; --a; --b;
        swap(p[a], p[b]);
        swap(s[0][p[a]], s[0][p[b]]);
        swap(s[1][p[a]], s[1][p[b]]);
        ckmin(dp[0][getmask(s[0])], i);
        ckmax(dp[1][getmask(s[1])], i);
    }
    for(int i = (1<<k)-1; i>=0; i--){
        if(dp[1][i]-dp[0][i] >= m) ckmax(ans, {2*__builtin_popcount(i)+k-cnt[0]-cnt[1], {dp[0][i]+1, dp[1][i]}});
        for(int j = 0; j<k; j++) if(i&(1<<j)) ckmin(dp[0][i^(1<<j)], dp[0][i]), ckmax(dp[1][i^(1<<j)], dp[1][i]);
    }
    cout << ans.first << endl << ans.second.first << " " << ans.second.second << endl;
}