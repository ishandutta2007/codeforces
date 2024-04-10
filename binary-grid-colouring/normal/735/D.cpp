#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const ll INF =2e15;
int a[maxn],b[maxn];
int vis[maxn];
int ans[maxn];
std::map<int, int> mp;

int isprime(ll x)
{
  for(ll i=2;i*i<=x;i++) {
    if(x%i==0)return 0;
  }
  return 1;
}
int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  if(n==2) std::cout << "1" << '\n',exit(0);

  if(n%2==0){
    std::cout << "2" << '\n';
  }
  else {
    if(isprime(n)) std::cout << "1" << '\n';
    else if(isprime(n-2)) {
      std::cout << "2" << '\n';
    }
    else std::cout << "3" << '\n';
  }
  return 0;
}