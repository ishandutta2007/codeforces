#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
std::vector<ll> a,b;
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;
int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  if(n==1){
    std::cout << "-1" << '\n';return 0;
  }
  std::cout << n << " " << n+1<<" "<< n*(n+1)<<endl;
  return 0;
}