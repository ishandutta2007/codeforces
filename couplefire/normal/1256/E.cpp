#include <bits/stdc++.h>
using namespace std;
#define MAXN 200006
#define INF 1000001000
int arr[MAXN];
int arr2[MAXN];
int dp[MAXN];
int grp[MAXN];
int grpsize[MAXN];
map<int, stack<int>> mp;

int main() {
  int n; cin >> n;
  for(int i = 0; i<n; i++){
    int a; cin >> a;
    arr[i] = a;
    arr2[i] = a;
  }
  sort(arr, arr+n);
  dp[0] = 0;
  dp[1] = arr[1]-arr[0];
  dp[2] = arr[2]-arr[0];
  grp[0] = 1;
  grp[1] = 1;
  grp[2] = 1;
  grp[3] = 1;
  grp[4] = 1;
  grpsize[0] = 1;
  grpsize[1] = 2;
  grpsize[2] = 3;
  grpsize[3] = 4;
  grpsize[4] = 5;
  if(n >= 4) dp[3] = arr[3]-arr[0];
  if(n >= 5) dp[4] = arr[4]-arr[0];
  for(int i = 5; i<n; i++){
    dp[i] = INF;
    for(int j = 3; j<=min(5, i-2); j++){
      if(dp[i-j] + arr[i]-arr[i-j+1] < dp[i]){
        dp[i] = dp[i-j] + arr[i]-arr[i-j+1];
        grp[i] = grp[i-j]+1;
        grpsize[i] = j;
      }
    }
  }
  cout << dp[n-1] << " " << grp[n-1] << endl;
  int nn = n-1;
  int cnt = 1;
  while(nn>=0){
    int t = grpsize[nn];
    while(t--){
      mp[arr[nn]].push(cnt);
      nn--;
    }
    cnt++;
  }
  for(int i = 0; i<n; i++){
    cout << mp[arr2[i]].top() << " ";
    mp[arr2[i]].pop();
  }
  cout << endl;
}