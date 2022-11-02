#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF = 2e15;
const double PI = acos(-1.0);
#define lson x << 1, l, mid
#define rson x << 1 | 1, mid + 1, r
const int lowbit(int x) { return x&-x; }
#define in freopen("in.txt","r",stdin)
std::map<int, int> mp;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> ans(n+1,0),b(n+1,0);
  std::vector<int> isprime(n+1,1);
  isprime[0]=isprime[1]=0;
  for(int i=2;i<=n;i++) {
    if(isprime[i]) {
      for(int j=i+i;j<=n;j+=i) {
        isprime[j]=0;
      }
    }
  }
  int id = 0;
  for(int i=2;i<=n;i++) {
    if(isprime[i]) {
      for(int j=i;j<=n;j*=i){
        ans[id++] = j;
      }
    }
  }
  std::cout << id << '\n';
  for(auto x : ans) {
    if(x!=0)
    std::cout << x <<" ";
  }
  std::cout << '\n';
  return 0;
}