#include <bits/stdc++.h>

using namespace std;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for (int i=0;i<n;i++) {
      int x;
      cin>>x;
      a[i]-=x;
    }
    for (int i=0;i<n;i++) {
      int x;
      cin>>x;
      a[i]+=x;
    }
    int sol=0;
    multiset<int> s;
    for (auto &x : a) {
      s.insert(x);
    }
    while ((int) s.size()>=2) {
      auto itb=s.end();
      itb--;
      /// *itb + val >= 0
      /// val >= -*itb
      int x=*itb;
      s.erase(itb);
      auto f = s.lower_bound(-x);
      if(f==s.end()) break;
      sol++;
      s.erase(f);
    }
    cout<<sol<<"\n";
  }

}