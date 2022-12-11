#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main(){
  ll n;
  
  cin >> n;
  
  ll res =  1;
  
  for(ll i = 2; i*i <= n; ++i){
    if(n%i == 0){
      while(n%i == 0) n /= i;
      res *= i;
    }
  }
  res *= n;
  
  cout << res << endl;
}