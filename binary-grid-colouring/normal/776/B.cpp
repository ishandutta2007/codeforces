#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;
std::vector<int> mark;
int vis[maxn];
int ans[maxn];
int main(int argc, char const *argv[]) {
  std::vector<int> isprime(1e6+10,1);
  isprime[0] = isprime[1] = 0;
  isprime[2] = 1;
  for(int i=2;i<=1e6+10;i++) {
    if(isprime[i]) {
      for(int j=i+i;j<=1e6+10;j+=i) {
        isprime[j] = 0;
      }
    }
  }

  int n;
  int cnt = 0;
  std::cin >> n;
  if(n==1) {
    std::cout << "1" << '\n' <<"1" <<endl;
    return 0;
  }
  if(n==2) {
    std::cout << "1" << '\n' << "1 1" << endl;
    return 0;
  }

  cout<< "2" <<endl;
 for(int i=2;i<=n+1;i++) {
   std::cout << isprime[i]+1 << " ";
 }

  std::cout << '\n';
  return 0;
}