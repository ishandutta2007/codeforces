#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> pi;
ll N,a,ans;
vector<ll> V;

int main(){
  cin >> N >> a;
  cin >> a;
  V.pb(a);
  for (int i = 1; i < N; ++i){
    cin >> a;
    if (a == V.back()){
      ans = max(ans,(ll)V.size());
      V.clear();
    }
    V.pb(a);
  }
  cout << max((ll)V.size(),ans);
}