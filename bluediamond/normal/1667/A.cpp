#include <bits/stdc++.h>

bool home=1;

using namespace std;

typedef long long ll;

ll solve(vector<ll> v) {
  int n=(int)v.size();
  ll sol=0,last=0;
  for (int i=0;i<n;i++){
    ll smth=(last+v[i])/v[i];
    sol+=smth;
    ll c=smth*v[i];
    assert(c-v[i]<=last);
    assert(c>last);
    last=c;
  }
  return sol;
}

const int N=5000+7;
const ll INF=(ll)1e18+7;
int n;
ll a[N];

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif


  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }


  cin>>n;
  for (int i=1;i<=n;i++) cin>>a[i];


  ll print=INF;

  for(int z=1;z<=n;z++){
    vector<ll> x, y;
    for (int i=z+1;i<=n;i++) x.push_back(a[i]);
    for (int i=z-1;i>=1;i--) y.push_back(a[i]);
    print=min(print,solve(x)+solve(y));
  }

  cout<<print<<"\n";
}