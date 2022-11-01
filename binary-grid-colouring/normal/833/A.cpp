#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

ll cubic_root(ll x)
{
  ll mid = 0;
  ll low = 0 ,high = 1000100;
  while(low <= high) {
     mid = (low + high) >> 1;
    if(mid * mid * mid > x) {
      high = mid - 1;
    }
    else if(mid * mid * mid < x){
      low = mid + 1;
    }
    else {
       break;
    }
  }
  return mid;
}
int main(int argc, char const *argv[]) {

  int n;
  //std::cin >> n;
  scanf("%d", &n);
  for(int i= 0;i < n; i++) {
    ll a,b;
    scanf("%lld%lld",&a,&b);
    //std::cin >> a >> b;
    ll x = cubic_root(a * b);
    if(x * x * x != a * b) {
      std::cout << "No" << '\n';
    }
    else if(a % x ==0 && b % x == 0) {
      std::cout << "Yes" << '\n';
    }
    else std::cout << "No" << '\n';
  }
  return 0;
}