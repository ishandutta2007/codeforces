#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int INF = 0x3f3f3f3f;

int dp[N][N];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> open = {0};
    vector<int> closed = {0};
    for(int i = 1; i<=n; i++){
        int a; cin >> a;
        if(a) closed.push_back(i);
        else open.push_back(i);
    }
    memset(dp, INF, sizeof dp);
    for(int i = 0; i<(int)open.size(); i++) dp[0][i] = 0;
    for(int i = 1; i<(int)closed.size(); i++){
        for(int j = i; j<(int)open.size(); j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+abs(closed[i]-open[j]));
        }
    }
    cout << dp[(int)closed.size()-1][(int)open.size()-1] << endl;
}