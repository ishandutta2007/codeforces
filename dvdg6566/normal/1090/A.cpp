#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> pi;
ll N,a,t,T,ans;
vector<pi> M;

int main(){
  cin >> N;
  for (int i = 0; i < N; ++i){
    M.pb(mp(0LL,0LL));
    cin >> a;
    M[i].s = a;
    for (int j =0; j < a; ++j){
      cin >> t;
      T = max(t,T);
      M[i].f = max(M[i].f,t);
    }
  }
  for (auto i : M){
    ans += i.s * (T-i.f);
  }
  cout << ans;
}