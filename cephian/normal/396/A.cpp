#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

map<int,int> m;

const ll MOD = 1e9+7;

void factorize(vector<int>& p, int n) {
  int q = sqrt(n);
  for(int i = 2; i <= q; ++i) {
    if(n%i != 0) continue;
    while(n%i==0) {
      n/=i;
      p.push_back(i);
    }
    q = sqrt(n);
  }
  if(n != 1) {
    p.push_back(n);
  }
}

const int N = 100005;
ll factorial[N];

void fill_factorial() {
  factorial[0]=1;
  for(int i = 1; i < N; ++i)
    factorial[i] = (factorial[i-1]*i)%MOD;
}

ll pw(ll a, ll b) {
  if(!b) return 1;
  if(b&1) return (a*pw(a,b-1))%MOD;
  ll t = pw(a,b/2);
  return (t*t)%MOD;
}

ll inv(ll a) {
  return pw(a,MOD-2);
}


ll binom(ll n, ll r) {
  return (factorial[n]*inv((factorial[r]*factorial[n-r])%MOD))%MOD;
}

int main() {
  ios::sync_with_stdio(0);
  fill_factorial();
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    vector<int> pf;
    factorize(pf,a);
    for(int i = 0; i < pf.size(); ++i) {
      ++m[pf[i]];
    }
  }
  ll ans = 1;
  for(map<int,int>::iterator i = m.begin(); i != m.end(); ++i) {
    ans = (ans*binom(n+i->second-1,n-1))%MOD;
  }
  cout << ans << "\n";
  return 0;
}