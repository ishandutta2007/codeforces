#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 5e5+100;
ll n,r,k;
ll a[maxn];
ll b[maxn];
ll c[maxn];

ll check(ll x)
{
  ll cur = 0;
  ll tmp = k;
  memset(c,0,sizeof (c));
  for(ll i=1;i<=n;i++) {
    cur = cur + c[i];
    if(x > (cur + b[i])) {
      ll d = x - cur - b[i];
      tmp = tmp - d;
      if(tmp < 0) return 0;
      cur = cur + d;
      ll tt = i + r * 2 + 1;
      if(n >= tt) {
        c[tt] -= d;
      }
    }
  }
  return 1;
}
int main(int argc, char const *argv[]) {
  // std::cin >> n >> r >> k;
  scanf("%lld%lld%lld", &n,&r,&k);
  for(int i=1;i<=n;i++) {
    // std::cin >> a[i];
    scanf("%lld", &a[i]);
  }
  for(int i=1;i<=n;i++) {
    ll id = max(i-r,1LL);
    b[id] += a[i];
    if(i + r + 1 <= n) {
      b[i + r + 1] -= a[i];
    }
  }
  for(ll i=1;i<=n;i++) {
    b[i] = b[i] + b[i-1];
  }
  ll minn =  b[1];
  for(ll i=2;i<=n;i++) {
    minn = min(minn,b[i]);
  }
  ll low = minn;
  ll high = minn + k;
  // std::cout << low << " " << high << '\n';
  // std::cout << "/* message */" << '\n';
  while(low <= high)
  {
    // std::cout << "/* message */" << '\n';
    ll mid = (low + high) >> 1;
    if(check(mid)) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  // std::cout << high << '\n';
  printf("%lld\n",high );
  return 0;
}
/*
5 0 6
5 4 3 4 9
5
*/