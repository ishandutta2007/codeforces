#include <bits/stdc++.h>
using namespace std;

int prefix[200002] = {0};
int density[200002] = {0};
int dp[200002] = {0};

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  for(int i = 0; i<n; i++){
    int a, b;
    cin >> a >> b;
    prefix[a] += 1;
    prefix[b+1] -= 1;
  }
  for(int i = 1; i<200002; i++){
    density[i] = density[i-1] + prefix[i];
  }
  for(int i = 1; i<200002; i++){
    dp[i] = dp[i-1] + (density[i-1]>=k);
  }
  for(int i = 0; i<q; i++){
    int a, b;
    cin >> a >> b;
    cout << dp[b+1]-dp[a] << endl;
  }
}