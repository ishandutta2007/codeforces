#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll arr[n];
  ll dp[n+1];
  dp[0] = 0;
  for(ll i = 0; i<n; i++){
    cin >> arr[i];
    dp[i+1] = arr[i]^dp[i];
  }
  unordered_map<ll, vector<ll>> m;
  for(ll i = 0; i<n+1; i++){
    if(m.count(dp[i]) == 0) m.insert(pair<ll, vector<ll>>(dp[i],{}));
    m[dp[i]].push_back(i);
  }
  ll re = 0;
  for(auto i : m){
    ll odd = 0, even = 0;
    for(ll k = 0; k<i.second.size(); k++){
      if(i.second[k] % 2 == 1) odd++;
      else even++;
    }
    re += odd*(odd-1)/2+even*(even-1)/2;
  }
  cout << re << endl;
}