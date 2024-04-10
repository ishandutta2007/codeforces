#include <bits/stdc++.h>
using namespace std;
int n, w;
vector<int> v;

int main() {
  cin >> n >> w;
  v.resize(n);
  int dp[n+1][w+1];
  int closest[n];
  for(int i = 0; i<n; i++){
    int a;
    cin >> a;
    v[i] = a;
  }
  sort(v.begin(), v.end());
  int pr = 0;
  for(int i = 0; i<n; i++){
    int k;
    for(k = pr; k<=i; k++){
      if(v[i]-v[k] <= 5) break;
    }
    pr = k;
    closest[i] = k;
    //cout << closest[i] << endl;
  }
  for(int i = 0; i<=n; i++){
    for(int k = 0; k<=w; k++){
      if(i == 0 || k == 0){
        dp[i][k] = 0;
        continue;
      }
      dp[i][k] = max(dp[i-1][k], dp[closest[i-1]][k-1]+i-closest[i-1]);
    }
  }
  cout << dp[n][w] << endl;
}