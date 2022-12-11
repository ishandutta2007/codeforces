#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a;
  cin >> a;
  
  vll k(4, 0);
  
  ll res = 0;
  
  for (int i = 0; i < a.size(); ++i) {
    int t = a[i] - '0';
    
    vll T(4, 0);
    T[t%4] = k[0] + k[2];
    T[(2 + t)%4] = k[1] + k[3];
    T[t%4]++;
    res += T[0];
    
    k = T;
  }
  
  cout << res << endl;
}