#include <bits/stdc++.h>

bool home = 1;

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
const int INF=(int)1e9+7;
int n,a[N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

 /// home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--) {
    int k;
    cin>>n>>k;
    {
      string str;
      cin>>str;
      assert((int)str.size()==n);
      for (int i=1;i<=n;i++) {
        char ch=str[i-1];
        a[i]=ch-'a';
        assert(0<=a[i]&&a[i]<26);
      }
    }
    bool ok=1;
    int mx=0;
    for (int i=1;i<=n;i++) {
   ///   cout<<a[i]<<" ";
      int new_mx=max(a[i],mx);
      if (new_mx>k) {
        ok=0;
        for (int i=1;i<=n;i++) {
          if (a[i]<=mx) a[i]=0;
        }
        int pot=(k-mx);
        assert(new_mx-pot>mx);
        assert(a[i]>=pot);
        for (int i=1;i<=n;i++) {
          if (new_mx-pot<=a[i]&&a[i]<=new_mx) {
            a[i]=new_mx-pot;
            assert(a[i]>=0);
          }
        }
        break;
      }
      mx=new_mx;
    }
    if (ok) {
      for (int i=1;i<=n;i++) a[i]=0;
    }
    for (int i=1;i<=n;i++) {
      cout<<(char)(a[i]+'a');
    }
    cout<<"\n";
  }

}