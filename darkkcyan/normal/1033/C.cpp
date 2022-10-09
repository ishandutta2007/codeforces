#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define llong long long 

template<typename x> ostream& operator<< (ostream& cout, const vector<x>& a) {
  cout << "[";
  len(a) && cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i] ;
  return cout;
}

template<typename u, typename v>
ostream& operator<< (ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxn 101010
int n;
int a[maxn], pos[maxn];
bool ans[maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) {
    cin >> a[i];
    pos[a[i]] = i;
  }

  for (int t = n - 1; t > 0; t--) {
    int i = pos[t];
    for (int u = i - a[i], v = i + a[i]; !ans[i] and (u > 0 or v <= n); u -= a[i], v += a[i]){ 
      if (u > 0 and a[u] > a[i] and !ans[u]) {
        ans[i] = 1;
      }
      if (v <= n and a[v] > a[i] and !ans[v]) {
        ans[i] = 1;
      }
    }
  }
  rep1(i, n) cout << ("BA")[ans[i]];

  return 0;
}