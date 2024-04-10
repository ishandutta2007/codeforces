#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second

int main(){
  ll T,b,p,f,h,c;
  cin>>T;
  while(T--){
    cin>>b>>p>>f>>h>>c;
    b /= 2;
    ll ans=0;
    if (h>c){
      ll ham = min(p, b);
      b -= ham;
      ans = ham * h + c * min(b,f);
    }else{
      ll ham = min(f, b);
      b -= ham;
      ans = ham * c + h * min(b,p);
    }
    cout<<ans<<'\n';
  }
}