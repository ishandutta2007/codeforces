#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int f[N];
int g[N];
int at[N];
int gmax[N];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int k1, k2, k3;
  cin >> k1 >> k2 >> k3;

  for(int i = 1; i <= k1; ++i) {
    int x; cin >> x;
    at[x] = 1;
  }


  for(int i = 1; i <= k2; ++i) {
    int x; cin >> x;
    at[x] = 2;
  }

  for(int i = 1; i <= k3; ++i) {
    int x; cin >> x;
    at[x] = 3;
  }
  int n = k1 + k2 + k3;

  f[0] = k1;
  for(int i = 1; i <= n; ++i) {
    f[i] = f[i - 1];
    if(at[i] == 1) f[i]--;
    else if(at[i] == 2) f[i]++;
  }

  g[n + 1] = gmax[n + 1] = k3;
  for(int i = n; i >= 1; --i){
    g[i] = g[i + 1];
    if(at[i] == 3) g[i]--;
    else if(at[i] == 2) g[i]++;
    gmax[i] = min(gmax[i + 1], g[i]);
  }

  int ans = k1 + k2 + k3;
  for(int i = 0; i <= n; ++i) {
    ans = min(ans, f[i] + gmax[i + 1]);
  }

  cout << ans << endl;

  return 0;
}