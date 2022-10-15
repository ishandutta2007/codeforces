#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long

const int N=(int)4e5+7;
const int INF=(int)1e9+7;
int n;
int x;
int a[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while(t--){
    cin>>n>>x;
    for (int i=1;i<=n;i++){
      cin>>a[i];
    }
    int cost=0;
    for(int i=1;i<n;i++){
      cost+=abs(a[i]-a[i+1]);
    }
    int mn=*min_element(a+1,a+n+1);
    int mx=*max_element(a+1,a+n+1);

    if(mn>1){
      cost+=min({2*(mn-1),a[1]-1,a[n]-1});
    }
    if(mx<x){
      cost+=min({2*(x-mx),x-a[1],x-a[n]});
    }
    cout<<cost<<"\n";
  }

}