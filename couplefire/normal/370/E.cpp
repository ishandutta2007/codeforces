#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
int const N = 2e5 + 20;
int n, a[N], mn[N], mx[N], h[N], t[N];
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i ++){
    cin >> a[i];
 
    if (a[i] > n){
      cout << -1 << endl;
      return 0;
    }
  }
 
  memset(h, -1, sizeof h);
  memset(t, -1, sizeof t);
  for (int i = 0; i < n; i ++){
    int x = a[i];
    if (h[x] == -1){
      h[x] = t[x] = i;
    }
    else {
      t[x] = i;
    }
  }
 
  mn[0] = mx[0] = 0;
  for (int i = 1; i <= n; i ++){
    if (h[i] != -1){
      mx[i - 1] = min(mx[i - 1], h[i]);
    }
    
    if (h[i] == -1){
      mn[i] = mn[i - 1] + 2;
      mx[i] = mx[i - 1] + 5;
    }
    else if (h[i] == t[i]){
      if (mn[i - 1] > h[i] || mx[i - 1] < t[i] - 4){
	cout << -1 << endl;
	return 0;
      }
 
      mn[i - 1] = max(mn[i - 1], t[i] - 4);
 
      mn[i] = max(h[i] + 1, mn[i - 1] + 2);
 
      int l = min(mx[i - 1], h[i]);
      mx[i] = l + 5;
    }
    else {
      if (mn[i - 1] > h[i] || mx[i - 1] < t[i] - 4){
	cout << -1 << endl;
	return 0;
      }
 
      mn[i - 1] = max(mn[i - 1], t[i] - 4);
 
      mn[i] = t[i] + 1;
 
      int l = min(mx[i - 1], h[i]);
      mx[i] = max(mn[i], l + 5);
    }
  }
 
  int ans = 0;
 
  for (int i = 1; i <= n; i ++){
    if (mn[i] <= n) ans = i;
  }
 
  if (mx[ans] < n){
    cout << -1 << endl;
    return 0;
  }
 
  cout << ans << endl;
 
  mn[ans] = n;
  for (int i = ans - 1; i >= 0; i --){
    mn[i] = max(mn[i], mn[i + 1] - 5);
  }
  
  int p = 0;
  for (int i = 1; i <= ans; i ++){
    while (p != mn[i]){
      cout << i << ' ';
      p ++;
    }
  }
 
  return 0;
}