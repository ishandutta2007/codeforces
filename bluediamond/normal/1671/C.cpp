#include <bits/stdc++.h>

bool home = 1;

using namespace std;

typedef long long ll;
typedef long double ld;
#define int long long

const int N=(int)2e5+7;
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
    sort(a+1,a+n+1);
    int sum=0;
    int sol=0;
    for(int i=1;i<=n;i++){
      sum+=a[i];
      if(sum<=x){
        int day=(x-sum)/i;
        sol+=day+1;
      }
    }
    cout<<sol<<"\n";
  }

}