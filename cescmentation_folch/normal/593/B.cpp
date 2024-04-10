#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pi;
typedef pair< pi, ll > ppi;
typedef vector< ppi > vppi;

typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main(){
  int n;
  cin >> n;
  ll x1, x2;
  cin >> x1 >> x2;
  vi K(n);
  vi T(n);
  for(int i = 0; i < n; ++i) cin >> K[i] >> T[i];
  vppi In(n);
  vppi Ou(n);
  for(int i = 0; i < n; ++i){
    In[i] = ppi(pi(K[i]*x1+T[i], K[i]), i);
    Ou[i] = ppi(pi(K[i]*x2+T[i], -K[i]), i);
  }
  sort(In.begin(), In.end());
  sort(Ou.begin(), Ou.end());
  bool xec = true;
  for(int i = 0; i < n; ++i){
    if(In[i].second != Ou[i].second) {
      xec = false;
      break;
    }
  }
  if(xec) cout << "NO" << endl;
  else cout << "YES" << endl;
}