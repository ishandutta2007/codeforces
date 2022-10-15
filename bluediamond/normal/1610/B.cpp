#include <bits/stdc++.h>

using namespace std;

const int N=(int)2e5+7;
int t,n,a[N];

bool is(int val){
  vector<int>x,y;
  for (int i=1;i<=n;i++){
    if (a[i]!=val)x.push_back(a[i]);
  }
  y=x;
  reverse(y.begin(),y.end());
  return x==y;
}

signed main() {

  ios::sync_with_stdio(0);cin.tie(0);
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    int l=1,r=n;
    bool ok=0;
    while (l<r){
      if (a[l]!=a[r]){
        ok|=is(a[l]);
        ok|=is(a[r]);
        break;
      }
      l++;
      r--;
    }
    if (l>=r)ok=1;
    if(ok){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }

  return 0;
}