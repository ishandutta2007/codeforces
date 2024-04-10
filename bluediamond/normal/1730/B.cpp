#include <bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define t second

const int INF=(int)1e18+7;

signed main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for (auto &it : a) cin>>it.x;
    for (auto &it : a) cin>>it.t;
    int max_sum=-INF,max_dif=-INF;
    for (auto &it : a) {
      max_sum=max(max_sum,it.t+it.x);
      max_dif=max(max_dif,it.t-it.x);
    }
    /**
    max_sum-x=max_dif+x
    2*x=max_sum-max_dif
    **/
    int x=max_sum-max_dif;
    cout<<x/2;
    if(x%2)cout<<".5";
    cout<<"\n";
  }

  return 0;
}