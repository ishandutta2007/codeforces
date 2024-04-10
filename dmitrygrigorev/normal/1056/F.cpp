#include <bits/stdc++.h>
#define double long double
using namespace std;
double dp[101][101][1001];
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return (a.first>b.first);
}
void solve(){
    int n;
    cin >> n;
    double C, T;
    cin >> C >> T;
    vector<pair<int, int> > e(n);
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        e[i] = {x, y};
    }
    sort(e.begin(), e.end(), cmp);
    vector<pair<double,int> > v(n);
    for (int i=0;i<n;i++) v[i] = e[i];
    for (int i=0; i <= n; i++) for (int j=0; j <= n; j++) for (int k=0; k <= n*10; k++) dp[i][j][k] = 1e18;
    dp[0][0][0] = 0;
    vector<double> mnoz;
    mnoz.push_back(1);
    for (int i=0; i < 200; i++) mnoz.push_back(mnoz.back() / 0.9);
    for (int i=0; i < n; i++){
        for (int j=0; j <= i; j++){
            for (int k=0; k <= 10*i; k++){
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+1][k+v[i].second] = min(dp[i+1][j+1][k+v[i].second], dp[i][j][k] + mnoz[j+1]*v[i].first);
            }
        }
    }
    int ans = 0;
    //cout << dp[3][2][20] << endl;
    for (int take=1; take <= n; take++){
        double low = (T*C - 10.*(double) take * C - 1.) / (2.*C);
        if (low >= T) continue;
        if (low < 0.) low = 0;
        double est = (T-low-10.*(double)take) * (1.+low*C);
       // cout << low << endl;
        for (int i=0;i<=10*n;i++){
            if (dp[n][take][i] <= est){
               // cout << dp[n][take][i] * (1/(1.+low*C)) + low + (double) take*10 << " " << i << endl;
                ans = max(ans, i);
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int tc;
    cin >> tc;
    for (int i=0; i < tc; i++) solve();

}