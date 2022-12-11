#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define For(i,a,f) for(int i = a; i < f; ++i)
#define foR(i,a,f) for(int i = a; i > f; --i)

int main(){
  int n;
  ll mod = 1e9+7;
  cin>>n;
  ll k = 1;
  ll r = 1;
  for(int i = 0; i < n; ++i){
    k = (k*27)%mod;
    r = (r*7)%mod;
  }
  cout<<(mod+k-r)%mod<<endl;
}