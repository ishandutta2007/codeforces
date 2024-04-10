#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

const int N = 100005;
ll MOD = 1e9+7;
int n;
ll p, allsum = 0;
multiset<ll> a;

ll pw(ll a, ll b) {
  if(b == 0) return 1;
  if(b&1) return (a*pw(a,b-1))%MOD;
  ll t = pw(a,b/2);
  return (t*t)%MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> p;
  for(int i = 0; i < n; ++i) {
    int q;
    cin >> q;
    allsum += q;
    a.insert(q);
  }
  while(1) {
    ll m = *a.rbegin();
    int amt = a.count(m);
    if(amt < p) goto end;
    amt = (amt/p)*p;
    for(int i = 0; i < amt; ++i)
      a.erase(a.find(m));
      amt /= p;
    for(int i = 0; i < amt; ++i)
      a.insert(m-1);
  }
  end:;
  cout << pw(p,min(allsum,allsum - *a.rbegin())) << "\n";
  return 0;
}