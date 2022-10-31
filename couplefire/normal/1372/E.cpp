#include <iostream>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    int dp[m+1][m+1];
    pair<int, int> segments[n][m];
    for(int i = 0; i<n; i++){
        int num; cin >> num;
        for(int j = 0; j<num; j++){
            int a, b; cin >> a >> b;
            --a; --b;
            for(int k = a; k<=b; k++) segments[i][k] = {a, b};
        }
    }
    for(int siz = 0; siz<=m; ++siz){
        for(int i = 0; i+siz<=m; ++i){
            int j = i+siz;
            dp[i][j] = 0;
            for(int k = i; k<j; ++k){
                int num = 0;
                for(int l = 0; l<n; l++){
                    if(segments[l][k].first >= i && segments[l][k].second < j) ++num;
                }
                // cout << dp[i][k] << endl;
                dp[i][j] = max(dp[i][j], dp[i][k]+num*num+dp[k+1][j]);
            }
        }
    }
    cout << dp[0][m] << endl;
}