#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n,a[N],v[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while (t--) {
    cin>>n;

    for (int i=1;i<=n;i++) cin>>a[i];
    int sol=0,putere_init=1;
    while (2*putere_init<n) putere_init*=2;

    for (int has=putere_init;has>=1;has/=2) {
      ///cout<<has<<" ";
      int num=sol+has;
      vector<int> inds,vals;
      for (int i=1;i<=n;i++) {
        v[i]=a[i];
        if ((a[i]&num)==num) {
          inds.push_back(i);
          vals.push_back(a[i]);
        }
      }
      sort(vals.begin(),vals.end());
      int k=(int)inds.size();
      for (int j=0;j<k;j++) {
        v[inds[j]]=vals[j];
      }
      bool ok=1;
      for (int j=2;j<=n;j++) {
        if (v[j-1]>v[j]) {
          ok=0;
          break;
        }
      }
      if (ok) {
        sol=num;
      }
    }
    ///cout<<" : ";

    cout<<sol<<"\n";
  }

}