#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll, pi> pii;
typedef set<ll> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vi loca, hinta, locb, hintb;
ll N,a,b;

int main(){
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    loca.pb(a);
    locb.pb(b);
  }
  for (int i=0;i<N;++i){
    cin>>a>>b;
    hinta.pb(a);
    hintb.pb(b);
  }
  sort(ALL(loca));
  sort(ALL(locb));
  sort(ALL(hinta));
  sort(ALL(hintb));
  reverse(ALL(loca));
  reverse(ALL(locb));
  cout << loca[0] + hinta[0] << ' ' << locb[0] + hintb[0];
}