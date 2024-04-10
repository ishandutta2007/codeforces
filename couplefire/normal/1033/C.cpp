#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;

int main() {
  cin >> n;
  int arr[n];
  for(int i = 0; i<n; i++){
    int a;
    cin >> a;
    v.push_back(make_pair(a, i));
    arr[i] = a;
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  char dp[n];
  dp[v[0].second] = 'B';
  for(int i = 1; i<n; i++){
    bool a = false;
    int s = v[i].second;
    int f = v[i].first;
    for(int k = s % f; k<n; k+=f){
      if(dp[k] == 'B' && arr[k] > f) a = true;
    }
    if(a == true) dp[s] = 'A';
    else dp[s] = 'B';
  }
  for(int i = 0; i<n; i++) cout << dp[i];
  cout << endl;
}