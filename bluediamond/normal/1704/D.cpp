#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;

  while (t--) {
    int cnt,n;
    cin>>cnt>>n;
    vector<ll> s(cnt,0);
    for(int i=0;i<cnt;i++){
      for(int j=0;j<n;j++){
        ll x;
        cin>>x;
        s[i]+=x*j;
      }
    }
    cout<<max_element(s.begin(),s.end())-s.begin()+1<<" "<<*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end())<<"\n";
  }


}

/**
we analyze
sum a[i] * i

a[i - 1] * (i - 1) + a[i] * i + a[j] * j + a[j + 1] * (j + 1)
vs

(a[i - 1] + 1) * (i - 1) + (a[i] - 1) * i + (a[j] - 1) * j + (a[j + 1] + 1) * (j + 1)
delta = (i - 1) - i - j + (j + 1) = 0

delta = (i - 1) - i - j + (j + 2) = 1
**/