#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int n, m;
int dp[401][401][51];
int arr[401];
int prefix[401];
pair<double, double> bestCur[51];

void addLine(int k, int xf, int xs){
    if(bestCur[k].second == -INF){
        bestCur[k] = {xf, xs};
        return;
    }
    if(abs(bestCur[k].first-xf)+bestCur[k].second <= xs){
        bestCur[k] = {xf, xs};
        return;
    }
    if(abs(xf-bestCur[k].first)+xs <= bestCur[k].second){
        return;
    }
    double a = bestCur[k].first, b = bestCur[k].second;
    double c = xf, d = xs;
    if(a > c){
        swap(a, c);
        swap(b, d);
    }
    bestCur[k] = {(a+c+d-b)/2.0, (c+d+b-a)/2.0};
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    prefix[0] = 0;
    for(int i = 1; i<=n; i++) prefix[i] = prefix[i-1]+arr[i];
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            dp[i][j][1] = 0;
        }
    }
    for(int k = 2; k<=m; k++){
        for(int i = 0; i<=k; i++) bestCur[i] = {0, -INF};
        for(int i = k; i<=n; i++){
            for(int j = k-1; j<i; j++) addLine(k-1, prefix[i-1]-prefix[j-1], dp[j][i-1][k-1]);
            for(int j = i; j<=n; j++){
                dp[i][j][k] = abs(bestCur[k-1].first-(prefix[j]-prefix[i-1]))+bestCur[k-1].second;
            }
        }
    }
    int ans = 0;
    for(int i = m; i<=n; i++){
        for(int j = i; j<=n; j++){
            ans = max(ans, dp[i][j][m]);
        }
    }
    cout << ans << endl;
}