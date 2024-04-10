#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int maxn = 5e6+5;
const int mod = 1e9+7;
const ll INF = 2e15;
const double PI = acos(-1.0);
#define lson x << 1, l, mid
#define rson x << 1 | 1, mid + 1, r
const int lowbit(int x) { return x&-x; }
#define in freopen("in.txt","r",stdin)
std::map<int, int> mp;
std::vector<int> ans;
int prime[maxn+10],sum[maxn+10];
int main(int argc, char const *argv[]) {
 int n = 1e7;
  std::vector<int> isprime(n+1,0);
  isprime[0]=isprime[1]=0;
  for(int i=2;i<=maxn;i++) {
    if(!isprime[i]) {
      for(int j=i,tmp=1;j<=maxn;j+=i,tmp++) {
        int t = tmp;
        while(1) {
          isprime[j]++;
          if(t % i != 0)break;
          t /= i;
        }
      }
    }
  }
  for(int i=2;i<=maxn;i++) {
    sum[i] = sum[i-1] + isprime[i];
  }
  int t;
//  std::cin >> t;
  scanf("%d", &t);
  while(t--) {
    int a;int b;
  //  std::cin >> a >> b;
    scanf("%d%d", &a,&b);
    std::cout << sum[a]-sum[b] << '\n';
  }
  return 0;
}