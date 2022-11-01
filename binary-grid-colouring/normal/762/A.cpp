#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
std::vector<ll> a,b;
int vis[maxn];
int ans[maxn];

int main(int argc, char const *argv[]) {
  ll n;
  int k;
  std::cin >> n >> k;
  for(ll i=1;i*i<=n;i++) {
    if(n%i==0) {
      if(i*i==n) a.push_back(i);
      else a.push_back(i),b.push_back(n / i);
    }
  }
  if(b.size() + a.size() < k) std::cout << "-1" << '\n';
  else {
    if(a.size() >= k) std::cout << a[k-1] << '\n';
    else std::cout << b[b.size()-(k-a.size()-1)-1] << '\n';
  }
  return 0;
}