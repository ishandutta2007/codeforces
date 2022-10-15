#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long

const int N=(int) 1e5+7;
int n,k,z,a[N];
int s[N];

int get(int l, int r) {
  return s[r]-s[l-1];
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    cin>>n>>k>>z;
    for (int i=1;i<=n;i++) {
      cin>>s[i];
      a[i]=s[i];
      s[i]+=s[i-1];
    }
    /// ... chaca chaca ...
    int sol=get(1,k+1);
    for (int l=1;l<=k;l++) {
      int cur=get(1,l+1),rem=k-l;
      for (int j=1;j<=z;j++) {
        if (rem) {
          cur+=a[l];
          rem--;
        }
        if (rem) {
          cur+=a[l+1];
          rem--;
        }
      }
      if (rem) {
        cur+=get(l+2,l+rem+1);
      }
      sol=max(sol,cur);
    }
    cout<<sol<<"\n";
  }
  return 0;
}